#pragma once
#include "ThreadCache.h"
#include "PageCache.h"



static void* ConcurrentMalloc(size_t size)
{
	if (size <= MAX_SIZE) // [1byte, 64kb] 就去central cache中去拿
	{
		if (pThreaCache == nullptr)
		{
			pThreaCache = new ThreadCache;
			cout << std::this_thread::get_id() << "->" << pThreaCache << endl;
		}

		return pThreaCache->Alloct(size);
	}
	else if (size <= ((MAX_PAGES - 1) << PAGE_SHIFT)) // (64kb, 128*4kb] 就去page cache中去拿
	{
		size_t align_size = SizeClass::_RoundUp(size, 1 << PAGE_SHIFT);
		size_t pagenum = (align_size >> PAGE_SHIFT);
		Span* span = PageCache::GetInstance().NewSpan(pagenum);
		span->objsize = align_size;
		void* ptr = (void*)(span->_pageid << PAGE_SHIFT);
		return ptr;
	}
	else // [128*4kb,-] 直接找系统要就OK了
	{
		size_t align_size = SizeClass::_RoundUp(size, 1 << PAGE_SHIFT);
		size_t pagenum = (align_size >> PAGE_SHIFT);
		return SystemAlloc(pagenum);
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
