#pragma once
#include "common.h"
#include "ThreadCache.h"
#include "PageCache.h"

static void* ConcurrentMalloc(size_t size)
{
	if (size > MAX_SIZE)
	{
		//����64K��С��128ҳ���͵�PageCache�������ڴ�
		size_t roundsize = SizeClass::_RoundUp(size, 1 << PAGE_SHIFT);
		size_t npage = roundsize >> PAGE_SHIFT;
		Span* span = PageCache::GetInstance().NewSpan(npage);
		void* ptr = (void*)(span->_pageid << PAGE_SHIFT);

		return ptr;

		//����64Kֱ��malloc
		//return malloc(size);
	}
	//��64K֮��ֱ�����̻߳����������ڴ�
	else
	{
		//ͨ��tls����ȡ�߳��Լ���tls
		if (pThreaCache == nullptr)
		{
			pThreaCache = new ThreadCache;
			//std::cout << std::this_thread::get_id() << "->"  << tls_threadcache << std::endl;
			//std::cout << tls_threadcache << std::endl;
		}

		//���ػ�ȡ���ڴ��ĵ�ַ
		return pThreaCache->Alloct(size);
		//return nullptr;
	}
}

static void ConcurrentFree(void* ptr)
{
	size_t pageid = (PAGE_ID)ptr >> PAGE_SHIFT;
	Span* span = PageCache::GetInstance().GetIdToSpan(pageid);
	if (span == nullptr)// [128*4kb,-]
	{
		SystemFree(ptr);
		return;
	}

	size_t size = span->objsize;
	if (size <= MAX_SIZE) // [1byte, 64kb]
	{
		pThreaCache->Deallocte(ptr, size);
	}
	else if (size <= ((MAX_PAGES - 1) << PAGE_SHIFT)) // (64kb, 128*4kb]
	{
		PageCache::GetInstance().ReleaseSpanToPageCache(span);
	}
}