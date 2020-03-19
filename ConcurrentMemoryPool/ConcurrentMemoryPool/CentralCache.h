#pragma once
#include"Common.h"

//����ģʽ
class CentralCache
{
public:
	// �����Ļ����ȡһ�������Ķ����thread cache
	size_t FetchRangeObj(void*& start, void*& end, size_t num, size_t size);
	
	// ��һ�������Ķ����ͷŵ�span���
	//�����size�����������ã�1.�䵱�±꣬ȥ�ҵ���Ӧ��Сspan�������� 2.����size�Ĵ�С���㻹��sapn�����е���һҳ
	void ReleaseListToSpans(void* start, size_t size);

	// ��spanlist ���� page cache��ȡһ��span
	Span* GetOneSpan(size_t size);

	static CentralCache& GetInstance()
	{
		static CentralCache Inst;
		return Inst;
	}
private:
	CentralCache(){}
	CentralCache(const CentralCache&) = delete;
	SpanList _SpanLists[NFREELIST];//��һ������Span����������
};

//static CentralCache centralCacheInst;//����̶߳���ThreadCache������ֻ��һ��CentarlCache

