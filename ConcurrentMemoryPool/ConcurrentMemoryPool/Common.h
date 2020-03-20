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
const size_t PAGE_SHIFT = 12; // 4k为页移位

inline void*& NextObj(void* obj)//返回引用，直接就进行修改
{
	return *((void**)obj);//自适应32位和64位下地址长度
}

class FreeList
{
public:
	void Push(void *obj)//从链表插入一个对象---头插
	{
		NextObj(obj) = _freelist;
		_freelist = obj;
		++_num;
	}

	void *Pop()//从链表中拿一个对象---头删
	{
		void* obj = _freelist;
		_freelist = NextObj(obj);
		--_num;
		return obj;
	}

	void PushRange(void* head,void* tail,size_t num)//向链表中插入一段内存
	{
		NextObj(tail) = _freelist;
		_freelist = head;

		_num += num;
	}

	//从链表中依次取出一段空间，直接指针传引用就可以拿到内存
	size_t PopRange(void*& start, void*& end, size_t num)
	{
		size_t actualNum = 0;//实际拿到的内存数量
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

		return actualNum;//返回实际取出来内存块的数量
	}

	bool Empty()
	{
		return _freelist == nullptr;//自由链表头结点
	}

	void clear()//这里的清理自由链表其实就是链表清空，将内存归还给系统。
	{
		_freelist = nullptr;//只是将内存归还，并不是销毁所以只需要将自由链表表头置空就OK了
		_num = 0;
	}

	size_t Num()//返回当前自由链表中有多少个内存块
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

	// 计算一次向系统获取几个页
	static inline size_t NumMovePage(size_t size)
	{
		size_t num = NumMoveSize(size);
		size_t npage = num*size;

		//转换成页数
		npage >>= 12;
		if (npage == 0)
			npage = 1;

		return npage;
	}

	//根据要申请的内存块的大小，动态的决定从Centarl cache要内存块的个数
	static inline size_t NumMoveSize(size_t size)
	{
		if (size == 0)
			return 0;

		int num = MAX_SIZE / size;//用来计算要申请内存块的个数
		if (num < 2)
			num = 2;   //size大了，那就少拿一些，最少拿两个；

		if (num > 512)
			num = 512; //size小了，那就多拿一些，最多拿512个；也就是4k --》一页

		return num;
	}

	// 对齐大小计算
	static inline size_t _RoundUp(size_t size,int align)//将size大小按照alignment大小进行对齐
	{
		//return size % 8 == 0 ? size : (size >> 4 + 1) << 8;
		//[9-16] + 7 = [16-23]  -> 16 8 4 2 1
		//[17-32] + 15 = [32-47]  -> 32 16 8 4 2 1
		if (size % align == 0)
			return size;
		else
			return (size / align + 1)*align;
		//return (size + align - 1)&(~(align - 1));//选择不同的对齐数，防止内存被切的太碎
	}

	//根据用户申请的内存大小，然后计算出合适的大小  控制内碎片浪费在[1%，10%]之间
	static inline size_t RoundUp(size_t size)
	{
		// 控制在[1%,10%]左右的内碎片浪费
		// [1,128] 8byte对齐 freelist[0,16)  第一个浪费较大因为要考虑到必须对齐到8字节处，平台不支持4字节
		// [129,1024] 16byte对齐 freelist[16,72)
		// [1025,8*1024] 128byte对齐 freelist[72,128)
		// [8*1024+1,64*1024] 1024byte对齐 freelist[128,184)

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

	static inline size_t _ListIndex(size_t size, int align_shift)//这里的align_shift是系数
	{
		return ((size + (1 << align_shift) - 1) >> align_shift) - 1;
	}
	//映射的自由链表的位置
	static inline size_t ListIndex(size_t size)
	{
		// [1,128] 8byte对齐 freelist[0,16)
		// [129,1024] 16byte对齐 freelist[16,72)
		// [1025,8*1024] 128byte对齐 freelist[72,128)
		// [8*1024+1,64*1024] 1024byte对齐 freelist[128,184)

		// 或者是全部都以8字节进行对齐，这样就是前面内存较小时内碎片很严重，但是越往后越大内碎片就会很小，
		// 另外一个问题就是这样会导致自由链表非常的长
		assert(size <= MAX_SIZE);
		// 每个区间有多少个链
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

//跨度  管理页为单位的内存对象 本质上是为了做合并，解决内存碎片问题
//2^64 / 2^12 = 2^52;   超过2^32数量

#ifdef _WIN32 // 针对windows
typedef unsigned int PAGE_ID;// int 无符号整形
#else
typedef unsigned long long PAGE_ID;//long long 八个字节
#endif

struct Span//跨度  管理页为单位的内存对象 本质上是为了做合并，解决内存碎片问题
{
	PAGE_ID _pageid = 0;//页号
	PAGE_ID _pagesize = 0;//页的数量

	FreeList _freelist;//对象的自由链表
	
	int _usecount = 0;//内存块对象使用计数
	size_t objsize = 0;//自由链表对象大小
	
	//实现双向链表需要两个指针
	Span* _next = nullptr;
	Span* _prev = nullptr;

};

class SpanList  //管理span的带头双向循环链表
{
public:
	SpanList()//构造函数
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

	void Insert(Span* pos, Span* newspan)//在pos位置之前插入newspan
	{
		Span* prev = pos->_prev;

		//进行插入链接
		prev->_next = newspan;
		newspan->_next = pos;
		pos->_prev = newspan;
		newspan->_prev = prev;
	}

	void Earse(Span* pos)//删除pos位置上面的span节点
	{
		assert(pos != _head);

		Span* prev = pos->_prev;
		Span* next = pos->_next;

		//进行删除
		prev->_next = next;
		next->_prev = prev;
	}

	void PushBack(Span* newspan)//尾插
	{
		Insert(_head, newspan);
	}

	void PushFront(Span* newspan)//头插
	{
		Insert(_head->_next, newspan);
	}

	void PopFront()//头删
	{
		Earse(_head->_next);
	}

	void PopBack()//尾删
	{
		Earse(_head->_prev);
	}

	void Lock()
	{
		_mtx.lock();
	} //加锁

	void Unlock()
	{
		_mtx.unlock();
	} //解锁
private:
	Span* _head;
	std::mutex _mtx; // 在central cache中多线程并发操作，要加锁避免资源竞争
};


inline static void* SystemAlloc(size_t kpage)  //windows下使用Virtual Alloc在Linux下用brk
{
#ifdef _WIN32  //条件编译
	void* ptr = VirtualAlloc(0, kpage*(1 << PAGE_SHIFT),
	MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
#else
	// brk mmap等
#endif
	if (ptr == nullptr)
	throw std::bad_alloc();
	return ptr;
}

inline static void SystemFree(void* ptr) //windows下使用VirtualFree， linux下使用sbrk
{
#ifdef _WIN32
	VirtualFree(ptr, 0, MEM_RELEASE);
#else
	// sbrk unmmap等
#endif
}