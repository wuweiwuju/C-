#pragma once
#include<iostream>
#include<assert.h>
#include<mutex>
#include<unordered_map>
#include<thread>
#include<windows.h>

using std::cout;
using std::endl;

const size_t MAX_SIZE = 64 * 1024;//64k
const size_t NFREELIST = MAX_SIZE / 8;
const size_t MAX_PAGES = 129;
const size_t PAGE_SHIFT = 12; // 4kΪҳ��λ

inline void*& NextObj(void* obj)//�������ã�ֱ�Ӿͽ����޸�
{
	return *((void**)obj);//����Ӧ32λ��64λ�µ�ַ����
}

class FreeList
{
public:
	void Push(void *obj)//���������һ������---ͷ��
	{
		NextObj(obj) = _freelist;
		_freelist = obj;
		++_num;
	}

	void *Pop()//����������һ������---ͷɾ
	{
		void* obj = _freelist;
		_freelist = NextObj(obj);
		--_num;
		return obj;
	}

	void PushRange(void* head,void* tail,size_t num)//�������в���һ���ڴ�
	{
		NextObj(tail) = _freelist;
		_freelist = head;

		_num += num;
	}

	//������������ȡ��һ�οռ䣬ֱ��ָ�봫���þͿ����õ��ڴ�
	size_t PopRange(void*& start, void*& end, size_t num)
	{
		size_t actualNum = 0;//ʵ���õ����ڴ�����
		void* prev = nullptr;
		void* cur = _freelist;
		for (; actualNum < num && cur != nullptr; ++actualNum)
		{
			prev = cur;
			cur = NextObj(cur);
		}

		start = _freelist;
		end = prev;
		_freelist = cur;

		_num -= actualNum;

		return actualNum;//����ʵ��ȡ�����ڴ�������
	}

	bool Empty()
	{
		return _freelist == nullptr;//��������ͷ���
	}

	void clear()//�������������������ʵ����������գ����ڴ�黹��ϵͳ��
	{
		_freelist = nullptr;//ֻ�ǽ��ڴ�黹����������������ֻ��Ҫ�����������ͷ�ÿվ�OK��
		_num = 0;
	}

	size_t Num()//���ص�ǰ�����������ж��ٸ��ڴ��
	{
		return _num;
	}
private:
	void* _freelist = nullptr;
	size_t _num = 0;
};

class SizeClass
{
public:

	// ����һ����ϵͳ��ȡ����ҳ
	static inline size_t NumMovePage(size_t size)
	{
		size_t num = NumMoveSize(size);
		size_t npage = num*size;

		//ת����ҳ��
		npage >>= 12;
		if (npage == 0)
			npage = 1;

		return npage;
	}

	//����Ҫ������ڴ��Ĵ�С����̬�ľ�����Centarl cacheҪ�ڴ��ĸ���
	static inline size_t NumMoveSize(size_t size)
	{
		if (size == 0)
			return 0;

		int num = MAX_SIZE / size;//��������Ҫ�����ڴ��ĸ���
		if (num < 2)
			num = 2;   //size���ˣ��Ǿ�����һЩ��������������

		if (num > 512)
			num = 512; //sizeС�ˣ��ǾͶ���һЩ�������512����Ҳ����4k --��һҳ

		return num;
	}

	// �����С����
	static inline size_t _RoundUp(size_t size,int align)//��size��С����alignment��С���ж���
	{
		//return size % 8 == 0 ? size : (size >> 4 + 1) << 8;
		//[9-16] + 7 = [16-23]  -> 16 8 4 2 1
		//[17-32] + 15 = [32-47]  -> 32 16 8 4 2 1
		if (size % align == 0)
			return size;
		else
			return (size / align + 1)*align;
		//return (size + align - 1)&(~(align - 1));//ѡ��ͬ�Ķ���������ֹ�ڴ汻�е�̫��
	}

	//�����û�������ڴ��С��Ȼ���������ʵĴ�С  ��������Ƭ�˷���[1%��10%]֮��
	static inline size_t RoundUp(size_t size)
	{
		// ������[1%,10%]���ҵ�����Ƭ�˷�
		// [1,128] 8byte���� freelist[0,16)  ��һ���˷ѽϴ���ΪҪ���ǵ�������뵽8�ֽڴ���ƽ̨��֧��4�ֽ�
		// [129,1024] 16byte���� freelist[16,72)
		// [1025,8*1024] 128byte���� freelist[72,128)
		// [8*1024+1,64*1024] 1024byte���� freelist[128,184)

		assert(size <= MAX_SIZE);

		if (size <= 128){
			return _RoundUp(size, 8);
		}
		else if (size <= 1024){
			return _RoundUp(size, 16);
		}
		else if (size <= 8192){
			return _RoundUp(size, 128);
		}
		else if (size <= 65536){
			return _RoundUp(size, 1024);
		}
		return -1;
	}

	static inline size_t _ListIndex(size_t size, int align_shift)//�����align_shift��ϵ��
	{
		return ((size + (1 << align_shift) - 1) >> align_shift) - 1;
	}
	//ӳ������������λ��
	static inline size_t ListIndex(size_t size)
	{
		// [1,128] 8byte���� freelist[0,16)
		// [129,1024] 16byte���� freelist[16,72)
		// [1025,8*1024] 128byte���� freelist[72,128)
		// [8*1024+1,64*1024] 1024byte���� freelist[128,184)

		// ������ȫ������8�ֽڽ��ж��룬��������ǰ���ڴ��Сʱ����Ƭ�����أ�����Խ����Խ������Ƭ�ͻ��С��
		// ����һ��������������ᵼ����������ǳ��ĳ�
		assert(size <= MAX_SIZE);
		// ÿ�������ж��ٸ���
		static int group_array[4] = { 16, 56, 56, 56 };
		if (size <= 128){
			return _ListIndex(size, 3);
		}
		else if (size <= 1024){
			return _ListIndex(size - 128, 4) + group_array[0];
		}
		else if (size <= 8192){
			return _ListIndex(size - 1024, 7) + group_array[1] + group_array[0];
		}
		else if (size <= 65536){
			return _ListIndex(size - 8192, 10) + group_array[2] + group_array[1] +
				group_array[0];
		}
		assert(false);
		return -1;
	}
};

//���  ����ҳΪ��λ���ڴ���� ��������Ϊ�����ϲ�������ڴ���Ƭ����
//2^64 / 2^12 = 2^52;   ����2^32����

#ifdef _WIN32 // ���windows
typedef unsigned int PAGE_ID;// int �޷�������
#else
typedef unsigned long long PAGE_ID;//long long �˸��ֽ�
#endif

struct Span//���  ����ҳΪ��λ���ڴ���� ��������Ϊ�����ϲ�������ڴ���Ƭ����
{
	PAGE_ID _pageid = 0;//ҳ��
	PAGE_ID _pagesize = 0;//ҳ������

	FreeList _freelist;//�������������
	
	int _usecount = 0;//�ڴ�����ʹ�ü���
	size_t objsize = 0;//������������С
	
	//ʵ��˫��������Ҫ����ָ��
	Span* _next = nullptr;
	Span* _prev = nullptr;

};

class SpanList  //����span�Ĵ�ͷ˫��ѭ������
{
public:
	SpanList()//���캯��
	{
		_head = new Span;
		_head->_prev = _head;
		_head->_next = _head;	
	}

	Span* Begin()
	{
		return _head->_next;
	}

	Span* End()
	{
		return _head;
	}

	bool Empty()
	{
		return Begin() == End();
	}

	void Insert(Span* pos, Span* newspan)//��posλ��֮ǰ����newspan
	{
		Span* prev = pos->_prev;

		//���в�������
		prev->_next = newspan;
		newspan->_next = pos;
		pos->_prev = newspan;
		newspan->_prev = prev;
	}

	void Earse(Span* pos)//ɾ��posλ�������span�ڵ�
	{
		assert(pos != _head);

		Span* prev = pos->_prev;
		Span* next = pos->_next;

		//����ɾ��
		prev->_next = next;
		next->_prev = prev;
	}

	void PushBack(Span* newspan)//β��
	{
		Insert(_head, newspan);
	}

	void PushFront(Span* newspan)//ͷ��
	{
		Insert(_head->_next, newspan);
	}

	void PopFront()//ͷɾ
	{
		Earse(_head->_next);
	}

	void PopBack()//βɾ
	{
		Earse(_head->_prev);
	}

	void Lock()
	{
		_mtx.lock();
	} //����

	void Unlock()
	{
		_mtx.unlock();
	} //����
private:
	Span* _head;
	std::mutex _mtx; // ��central cache�ж��̲߳���������Ҫ����������Դ����
};


inline static void* SystemAlloc(size_t kpage)  //windows��ʹ��Virtual Alloc��Linux����brk
{
#ifdef _WIN32  //��������
	void* ptr = VirtualAlloc(0, kpage*(1 << PAGE_SHIFT),
	MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
#else
	// brk mmap��
#endif
	if (ptr == nullptr)
	throw std::bad_alloc();
	return ptr;
}

inline static void SystemFree(void* ptr) //windows��ʹ��VirtualFree�� linux��ʹ��sbrk
{
#ifdef _WIN32
	VirtualFree(ptr, 0, MEM_RELEASE);
#else
	// sbrk unmmap��
#endif
}