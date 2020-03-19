#define _CRT_SECURE_NO_WARNINGS 1
#include"CentralCache.h"
#include"PageCache.h"


// �����Ļ����ȡһ�������Ķ����thread cache
size_t CentralCache::FetchRangeObj(void*& start, void*& end, size_t num, size_t size)//��centralcache��ȡ��һ�ζ���
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

	//��page cache ��ȡһ��span
	size_t numpage = SizeClass::NumMovePage(size);
	Span* span = PageCache::GetInstance().NewSpan(numpage);

	//��span�����и�ɶ�Ӧ��С�ҵ�span��freelist��
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

	spanlist.Lock();//����
	while (start)
	{
		void* next = NextObj(start);
		PAGE_ID id = (PAGE_ID)start >> PAGE_SHIFT;//���������ڴ�������һ��ҳ
		Span* span = PageCache::GetInstance().GetIdToSpan(id);
		span->_freelist.Push(start);
		span->_usecount--;

		if (span->_usecount == 0)//��ʾ��ǰ��ҳ�Ѿ���ȫ���黹/����û��ʹ��
		{
			size_t index = SizeClass::ListIndex(span->objsize);

			_SpanLists[index].Earse(span);
			span->_freelist.clear();

			PageCache::GetInstance().ReleaseSpanToPageCache(span);
		}
		start = next;
	}

	spanlist.Unlock();//����
}