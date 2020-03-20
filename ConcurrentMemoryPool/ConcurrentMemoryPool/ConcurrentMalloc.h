#pragma once
#include "common.h"
#include "ThreadCache.h"
#include "PageCache.h"

static void* ConcurrentMalloc(size_t size)
{
	if (size > MAX_SIZE)
	{
		//大于64K，小于128页，就到PageCache中申请内存
		size_t roundsize = SizeClass::_RoundUp(size, 1 << PAGE_SHIFT);
		size_t npage = roundsize >> PAGE_SHIFT;
		Span* span = PageCache::GetInstance().NewSpan(npage);
		void* ptr = (void*)(span->_pageid << PAGE_SHIFT);

		return ptr;

		//大于64K直接malloc
		//return malloc(size);
	}
	//在64K之内直接在线程缓存中申请内存
	else
	{
		//通过tls，获取线程自己的tls
		if (pThreaCache == nullptr)
		{
			pThreaCache = new ThreadCache;
			//std::cout << std::this_thread::get_id() << "->"  << tls_threadcache << std::endl;
			//std::cout << tls_threadcache << std::endl;
		}

		//返回获取的内存块的地址
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