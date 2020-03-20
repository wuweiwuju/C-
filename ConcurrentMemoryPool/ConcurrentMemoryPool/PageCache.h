#pragma once
#include"Common.h"

//单例模式
//这个类的对象全局只能产生一个
class PageCache
{
public:
	//申请一个新的Span
	//Span* _NewSpan(size_t num);
	Span* NewSpan(size_t num);

	void ReleaseSpanToPageCache(Span* span);

	Span* GetIdToSpan(PAGE_ID id);

	static PageCache& GetInstance()
	{
		static PageCache Inst;
		return Inst;
	}
private:
	PageCache(){}
	PageCache(const PageCache&) = delete;
	SpanList _spanlist[MAX_PAGES]; // 存储span的双向链表，但是这内面的span内存都没有被切割

	std::unordered_map<PAGE_ID, Span*> _idSpanMap;
	std::mutex _mtx;
};

//static PageCache pageCacheInst;//多个线程都有ThreadCache，但是只有一个PageCache