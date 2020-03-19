#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include"Common.h"

class ThreadCache
{
public:
	//申请内存
	void* Alloct(size_t size);
	
	//释放内存
	void  Deallocte(void* ptr, size_t size);
	
	//从中心缓冲区去取内存
	void* FetchFromCentralCache(size_t index);

	//如果自由链表中对象超过一定长度就要释放给中心缓存,归还内存给central cache 
	void ListTooLong(FreeList& freeList, size_t num, size_t size);
private:
	FreeList _freeList[NFREELIST];//自由链表
};

// ThreadCache* tclist = nullptr;
// 线程TLS Thread Local Storage 每个线程独享的
_declspec (thread) static ThreadCache* pThreaCache = nullptr;
//static ThreadCache* pThreaCache = nullptr; 这个是线程共有的