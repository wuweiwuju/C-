#define _CRT_SECURE_NO_WARNINGS 1
#include"CentralCache.h"
#include"PageCache.h"


// 从中心缓存获取一定数量的对象给thread cache
size_t CentralCache::FetchRangeObj(void*& start, void*& end, size_t num, size_t size)//从centralcache获取到一段对象
{
	size_t index = SizeClass::ListIndex(size);
	SpanList& spanlist = _SpanLists[index];

	spanlist.Lock();

	Span* span = GetOneSpan(size);
	FreeList& freelist = span->_freelist;
	size_t actualNum = freelist.PopRange(start, end, num);
	span->_usecount += actualNum;

	spanlist.Unlock();

	return actualNum;
}

Span*  CentralCache::GetOneSpan(size_t size)
{
	size_t index = SizeClass::ListIndex(size);
	SpanList& spanlist = _SpanLists[index];
	Span* it = spanlist.Begin();
	while (it != spanlist.End())
	{
		if (!it->_freelist.Empty())
		{
			return it;
		}
		else
		{
			it = it->_next;
		}
	}

	//从page cache 获取一个span
	size_t numpage = SizeClass::NumMovePage(size);
	Span* span = PageCache::GetInstance().NewSpan(numpage);

	//把span对象切割成对应大小挂到span的freelist中
	char* start = (char*)(span->_pageid << 12);
	char* end = start + (span->_pagesize << 12);
	while (start < end)
	{
		char* obj = start;
		start += size;

		span->_freelist.Push(obj);
	}
	span->objsize = size;
	spanlist.PushFront(span);

	return span;
}

void CentralCache::ReleaseListToSpans(void* start, size_t size)
{
	size_t index = SizeClass::ListIndex(size);
	SpanList& spanlist = _SpanLists[index];

	spanlist.Lock();//加锁
	while (start)
	{
		void* next = NextObj(start);
		PAGE_ID id = (PAGE_ID)start >> PAGE_SHIFT;//计算出这块内存属于哪一个页
		Span* span = PageCache::GetInstance().GetIdToSpan(id);
		span->_freelist.Push(start);
		span->_usecount--;

		if (span->_usecount == 0)//表示当前的页已经完全被归还/空闲没有使用
		{
			size_t index = SizeClass::ListIndex(span->objsize);

			_SpanLists[index].Earse(span);
			span->_freelist.clear();

			PageCache::GetInstance().ReleaseSpanToPageCache(span);
		}
		start = next;
	}

	spanlist.Unlock();//解锁
}