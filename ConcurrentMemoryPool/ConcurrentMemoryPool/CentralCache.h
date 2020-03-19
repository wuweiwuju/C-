#pragma once
#include"Common.h"

//单例模式
class CentralCache
{
public:
	// 从中心缓存获取一定数量的对象给thread cache
	size_t FetchRangeObj(void*& start, void*& end, size_t num, size_t size);
	
	// 将一定数量的对象释放到span跨度
	//这里的size的有两个作用：1.充当下标，去找到对应大小span自由链表 2.根据size的大小计算还给sapn链表中的那一页
	void ReleaseListToSpans(void* start, size_t size);

	// 从spanlist 或者 page cache获取一个span
	Span* GetOneSpan(size_t size);

	static CentralCache& GetInstance()
	{
		static CentralCache Inst;
		return Inst;
	}
private:
	CentralCache(){}
	CentralCache(const CentralCache&) = delete;
	SpanList _SpanLists[NFREELIST];//是一个管理Span的自由链表
};

//static CentralCache centralCacheInst;//多个线程都有ThreadCache，但是只有一个CentarlCache

