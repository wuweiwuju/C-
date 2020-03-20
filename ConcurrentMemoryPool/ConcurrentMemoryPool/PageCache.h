#pragma once
#include"Common.h"

//����ģʽ
//�����Ķ���ȫ��ֻ�ܲ���һ��
class PageCache
{
public:
	//����һ���µ�Span
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
	SpanList _spanlist[MAX_PAGES]; // �洢span��˫�����������������span�ڴ涼û�б��и�

	std::unordered_map<PAGE_ID, Span*> _idSpanMap;
	std::mutex _mtx;
};

//static PageCache pageCacheInst;//����̶߳���ThreadCache������ֻ��һ��PageCache