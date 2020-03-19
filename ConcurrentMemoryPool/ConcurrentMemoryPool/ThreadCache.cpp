#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include"ThreadCache.h"
#include"CentralCache.h"

void* ThreadCache::Alloct(size_t size)//申请内存
{
	size_t index = SizeClass::ListIndex(size);
	FreeList& freelist = _freeList[index];
	if (!freelist.Empty())//如果thread cache本身就有就直接拿着用
	{
		return freelist.Pop();
	}
	else//如果没有那就去找central cache去要
	{
		return FetchFromCentralCache(SizeClass::RoundUp(size));
	}
}

void  ThreadCache::Deallocte(void* ptr, size_t size)//释放内存
{
	size_t index = SizeClass::ListIndex(size);

	//释放内存的操作不自己去写，而是专门独立出来交给一个独立的类去做；
	//体现模块化

	FreeList& freeList = _freeList[index];
	freeList.Push(ptr);

	//这里可能还会有一种情况，就是当ThreadCache中该大小内存队列太多了应该返回给Centralcache了
	//判断条件  ： 对象个数   |    内存大小
	size_t num = SizeClass::NumMoveSize(size);
	if (freeList.Num() >= num)
	{
		//ReleaseToCentralCache();//thread cache内面挂的内存太多了还给中心缓冲区
		ListTooLong(freeList, num, size);
	}
}

//独立测试Thead Cache

//void* ThreadCache::FetchFromCentralCache(size_t index)//从Central cache缓冲区去取内存
//{
//	size_t num = 20;//暂时性写死，以后会进行调整,跟单个对象大小有关系
//	
//	//模拟测试：取内存,测试Thread Cache
//	size_t size = (index + 1) * 8;
//	char* start = (char*)malloc(size*num);
//	char* cur = start;
//	
//	for (size_t i = 0; i < num-1; i++)
//	{
//		char* next = cur + size;
//		NextObj(cur) = next;
//		cur = next;
//	}
//	NextObj(cur) = nullptr;
//
//	void* head = NextObj(start);
//	void* tail = cur;
//
//	_freeList[index].PushRange(head, tail);
//
//	return start;
//}

void* ThreadCache::FetchFromCentralCache(size_t size)//从Central cache缓冲区去取内存
{
	size_t num = SizeClass::NumMoveSize(size);//来决定向Central Cache要多少个size大小的内存块

	//从centralcache去内存块
	void *start = nullptr, *end = nullptr;
	size_t actualNum = CentralCache::GetInstance().FetchRangeObj(start, end, num, size);
	if (actualNum == 1)
	{
		return start;
	}
	else
	{
		size_t index = SizeClass::ListIndex(size);
		FreeList& list = _freeList[index];
		list.PushRange(NextObj(start), end, actualNum - 1);
		return start;
	}
}


// 如果自由链表中对象超过一定长度就要释放给中心缓存
void ThreadCache::ListTooLong(FreeList& freeList, size_t num, size_t size)
{
	void* start = nullptr, *end = nullptr;
	freeList.PopRange(start, end, size);//从thread cache中拿出

	NextObj(end) = nullptr;
	CentralCache::GetInstance().ReleaseListToSpans(start, size);
	//从thread cache中取出要归还的内存，然后插入到central cache中对应的span页中
}
