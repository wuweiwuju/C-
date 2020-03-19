#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include"ThreadCache.h"
#include"CentralCache.h"

void* ThreadCache::Alloct(size_t size)//�����ڴ�
{
	size_t index = SizeClass::ListIndex(size);
	FreeList& freelist = _freeList[index];
	if (!freelist.Empty())//���thread cache������о�ֱ��������
	{
		return freelist.Pop();
	}
	else//���û���Ǿ�ȥ��central cacheȥҪ
	{
		return FetchFromCentralCache(SizeClass::RoundUp(size));
	}
}

void  ThreadCache::Deallocte(void* ptr, size_t size)//�ͷ��ڴ�
{
	size_t index = SizeClass::ListIndex(size);

	//�ͷ��ڴ�Ĳ������Լ�ȥд������ר�Ŷ�����������һ����������ȥ����
	//����ģ�黯

	FreeList& freeList = _freeList[index];
	freeList.Push(ptr);

	//������ܻ�����һ����������ǵ�ThreadCache�иô�С�ڴ����̫����Ӧ�÷��ظ�Centralcache��
	//�ж�����  �� �������   |    �ڴ��С
	size_t num = SizeClass::NumMoveSize(size);
	if (freeList.Num() >= num)
	{
		//ReleaseToCentralCache();//thread cache����ҵ��ڴ�̫���˻������Ļ�����
		ListTooLong(freeList, num, size);
	}
}

//��������Thead Cache

//void* ThreadCache::FetchFromCentralCache(size_t index)//��Central cache������ȥȡ�ڴ�
//{
//	size_t num = 20;//��ʱ��д�����Ժ����е���,�����������С�й�ϵ
//	
//	//ģ����ԣ�ȡ�ڴ�,����Thread Cache
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

void* ThreadCache::FetchFromCentralCache(size_t size)//��Central cache������ȥȡ�ڴ�
{
	size_t num = SizeClass::NumMoveSize(size);//��������Central CacheҪ���ٸ�size��С���ڴ��

	//��centralcacheȥ�ڴ��
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


// ������������ж��󳬹�һ�����Ⱦ�Ҫ�ͷŸ����Ļ���
void ThreadCache::ListTooLong(FreeList& freeList, size_t num, size_t size)
{
	void* start = nullptr, *end = nullptr;
	freeList.PopRange(start, end, size);//��thread cache���ó�

	NextObj(end) = nullptr;
	CentralCache::GetInstance().ReleaseListToSpans(start, size);
	//��thread cache��ȡ��Ҫ�黹���ڴ棬Ȼ����뵽central cache�ж�Ӧ��spanҳ��
}
