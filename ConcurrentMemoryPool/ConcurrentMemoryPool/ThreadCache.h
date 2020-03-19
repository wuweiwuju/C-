#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include"Common.h"

class ThreadCache
{
public:
	//�����ڴ�
	void* Alloct(size_t size);
	
	//�ͷ��ڴ�
	void  Deallocte(void* ptr, size_t size);
	
	//�����Ļ�����ȥȡ�ڴ�
	void* FetchFromCentralCache(size_t index);

	//������������ж��󳬹�һ�����Ⱦ�Ҫ�ͷŸ����Ļ���,�黹�ڴ��central cache 
	void ListTooLong(FreeList& freeList, size_t num, size_t size);
private:
	FreeList _freeList[NFREELIST];//��������
};

// ThreadCache* tclist = nullptr;
// �߳�TLS Thread Local Storage ÿ���̶߳����
_declspec (thread) static ThreadCache* pThreaCache = nullptr;
//static ThreadCache* pThreaCache = nullptr; ������̹߳��е�