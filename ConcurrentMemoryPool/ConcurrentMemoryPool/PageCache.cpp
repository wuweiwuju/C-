#include"PageCache.h"

Span* PageCache::_NewSpan(size_t numpage)
{
	if (!_spanlist[numpage].Empty())
	{
		Span* span = _spanlist[numpage].Begin();
		_spanlist[numpage].PopFront();
		return span;
	}

	for (size_t i = numpage + 1; i < MAX_PAGES; ++i)
	{
		if (!_spanlist[i].Empty())
		{
			// ����
			Span* span = _spanlist[i].Begin();
			_spanlist[i].PopFront();

			Span* splitspan = new Span;
			splitspan->_pageid = span->_pageid + span->_pagesize - numpage;
			splitspan->_pagesize = numpage;
			for (PAGE_ID i = 0; i < numpage; ++i)
			{
				_idSpanMap[splitspan->_pageid + i] = splitspan;
			}

			span->_pagesize -= numpage;

			_spanlist[span->_pagesize].PushFront(span);

			return splitspan;
		}
	}

	void* ptr = SystemAlloc(MAX_PAGES - 1);

	Span* bigspan = new Span;
	bigspan->_pageid = (PAGE_ID)ptr >> PAGE_SHIFT;
	bigspan->_pagesize = MAX_PAGES - 1;

	for (PAGE_ID i = 0; i < bigspan->_pagesize; ++i)
	{
		//_idSpanMap.insert(std::make_pair(bigspan->_pageid + i, bigspan));
		_idSpanMap[bigspan->_pageid + i] = bigspan;
	}

	_spanlist[bigspan->_pagesize].PushFront(bigspan);

	return NewSpan(numpage);
}

Span* PageCache::NewSpan(size_t numpage)
{
	_mtx.lock();
	Span* span = _NewSpan(numpage);
	_mtx.unlock();

	return span;
}

void PageCache::ReleaseSpanToPageCache(Span* span)
{

	//��ǰ�ϲ�
	while (1)
	{
		PAGE_ID prevPageId = span->_pageid - 1;//��ǰҳ��ǰһҳ��ҳ�ž��ǵ�ǰҳ=ҳ��-1��
		auto pit = _idSpanMap.find(prevPageId);
		//ǰ���ҳ�治����
		if (pit == _idSpanMap.end())
		{
			break;
		}

		//˵��ǰһ������ʹ�õ���
		Span* prevSpan = pit->second;
		if (prevSpan->_usecount != 0)
		{
			break;
		}

		//���кϲ�
		span->_pageid = prevSpan->_pageid;//ҳ�źϲ���ǰһ��ҳ��ҳ��
		span->_pagesize += prevSpan->_pagesize;//ҳ���������
		for (PAGE_ID i = 0; i < prevSpan->_pagesize; ++i)//�ϲ�������µ�mapӳ��
		{
			_idSpanMap[prevSpan->_pageid + i] = span;
		}

		_spanlist[prevSpan->_pagesize].Earse(prevSpan);
		delete prevSpan;
	}

	//���ϲ�
	while (1)
	{
		PAGE_ID nextPageId = span->_pageid + span->_pagesize;
		auto nextIt = _idSpanMap.find(nextPageId);
		if (nextIt == _idSpanMap.end())
		{
			break;
		}

		Span* nextSpan = nextIt->second;
		if (nextSpan->_usecount != 0)
		{
			break;
		}

		span->_pagesize += nextSpan->_pagesize;
		for (PAGE_ID i = 0; i < nextSpan->_pagesize; ++i)
		{
			_idSpanMap[nextSpan->_pageid + i] = span;
		}

		_spanlist[nextSpan->_pagesize].Earse(nextSpan);
		delete nextSpan;
	}
	_spanlist[span->_pagesize].PushFront(span);
}

Span* PageCache::GetIdToSpan(PAGE_ID id)
{
	//std::map<PAGE_ID, Span*>::iterator it = _idSpanMap.find(id);
	auto it = _idSpanMap.find(id);
	if (it != _idSpanMap.end())
	{
		return it->second;
	}
	else
	{
		return nullptr;
	}
}