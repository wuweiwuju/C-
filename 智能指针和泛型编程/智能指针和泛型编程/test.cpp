//泛型编程
//简而言之就是构成函数重载的都可以用函数模板进行
//复用，这样的话，极大的增加了代码的复用率

//举个例子 比较大小
//#include<iostream>
//using namespace std;
///*bool cmp(int a, int b)
//{
//	return a > b;
//}
//bool cmp(double a, double b)
//{
//	return a > b;
//}
//bool cmp(char a, char b)
//{
//	return a > b;
//}*/
///*template<class T>
//bool cmp(T a, T b)
//{
//	return a > b;
//}*/
//#include<string.h>
//
////函数模板只有全特化，没有偏特化，而类模板两者皆有
//template<class T>
//class Solution {
//public:
//	bool cmp(T a, T b)
//	{
//		return a == b;
//	}
//};
//
////函数模板的特化不能单独使用，要搭配原模板一起使用
//template<>
//class Solution <char*>{
//public:
//	bool cmp(char* a, char* b)
//	{
//		return strcmp(a, b) == 0;
//	}
//};
//
//
//
//int main()
//{
//	/*cout << cmp(1, 2) << endl;
//	cout << cmp('a', 'b') << endl;
//	cout << cmp(1.0, 2.0) << endl;*/
//
//	char str[] = "Hello";
//	char tmp[] = "Hello";
//
//	Solution<char*> t;
//	cout << t.cmp(str, tmp) << endl;
//	return 0;
//}

//智能指针
//类似的RAII管理方式，将其指针设定为一个对象，让一个类来实现指针的操作，
//这样的话，就不需要显示的释放申请的内存什么的了，可以预防异常安全，资源泄漏情况。

//#include<iostream>
//using namespace std;
////auto_ptr
////类似于管理权的转让
////将其拷贝或者赋值的原对象置空
///*namespace lpf
//{
//	template<class T>
//	class auto_ptr
//	{
//	public:
//		auto_ptr(T* ptr = nullptr)
//			:_ptr(ptr)
//		{}
//		auto_ptr(auto_ptr<T>& tmp)
//		{
//			_ptr = tmp._ptr;
//			tmp._ptr = nullptr;
//		}
//		auto_ptr<T>& operator=(auto_ptr<T>& tmp)
//		{
//			if (this != &tmp)
//			{
//				if (_ptr)
//					delete _ptr;
//
//				_ptr = tmp._ptr;
//				tmp._ptr = nullptr;
//			}
//			return *this;
//		}
//		T& operator*()
//		{
//			return *_ptr;
//		}
//		T* operator->()
//		{
//			return _ptr;
//		}
//		~auto_ptr()
//		{
//			if (_ptr)
//			{
//				delete _ptr;
//				_ptr = nullptr;
//			}
//		}
//	private:
//		T* _ptr;
//	};
//}
//struct A
//{
//	int _a;
//	int _b;
//};
//void test_auto_ptr()
//{
//	lpf::auto_ptr<A> str1(new A);
//	str1->_a = 10;
//	str1->_b = 20;
//	lpf::auto_ptr<A> str2(str1);
//	lpf::auto_ptr<A> str3;
//	str3 = str2;
//}
//int main()
//{
//	test_auto_ptr();
//}*/
////unique_ptr
////类似于将其拷贝构造和赋值私有化，或者让其写成delete
///*namespace lpf
//{
//	template<class T>
//	class unique_ptr
//	{
//	public:
//		unique_ptr(T* ptr = nullptr)
//			:_ptr(ptr)
//		{}
//		~unique_ptr()
//		{
//			if (_ptr)
//				delete(_ptr);
//		}
//
//		T& operator*()
//		{
//			return *_ptr;
//		}
//		T* operator->()
//		{
//			return _ptr;
//		}
//		//将拷贝构造和赋值运算符重载设为私有
//		unique_ptr(const unique_ptr<T>&) = delete;
//		unique_ptr<T>& operator=(const unique_ptr<T>&) = delete;
//	private:
//		T* _ptr;
//	};
//}
//int main()
//{
//	lpf::unique_ptr<int> str(new int);
//	*str = 10;
//	return 0;
//}*/
////shared_ptr
////用引用计数来解决支持多个指针的操作
//namespace lpf
//{
//	template<class T>
//	class shared_ptr
//	{
//	public:
//		shared_ptr(T* ptr = nullptr)
//			:_ptr(ptr)
//			,_pCount(new int(1))
//		{}
//		shared_ptr(const shared_ptr<T>& tmp)
//		{
//			_ptr = tmp._ptr;
//			_pCount = tmp._pCount;
//			(*_pCount)++;
//		}
//		shared_ptr<int>& operator=(const shared_ptr<int>& srv)
//		{
//			if (_ptr != srv._ptr)
//			{
//				if (--(*_pCount) == 0)
//				{
//					delete(_pCount);
//					delete(_ptr);
//				}
//				_ptr = srv._ptr;
//				srv._pCount++;
//			}
//			return *this;
//		}
//		T& operator*()
//		{
//			return *_ptr;
//		}
//		T* operator->()
//		{
//			return _ptr;
//		}
//		~shared_ptr()
//		{
//			if (--(*_pCount) == 0)
//			{
//				delete(_pCount);
//				delete(_ptr);
//			}
//		}
//	private:
//		T* _ptr;
//		int* _pCount;
//	};
//}
////特定场景下才会产生循环引用
////weak_ptr
//
//
///*namespace lpf 
//{
//	template<class T>
//	class auto_ptr 
//	{
//	public:
//		auto_ptr(T* ptr = nullptr) 
//			:_ptr(ptr)
//		{}
//		auto_ptr(const auto_ptr<T>& tmp)
//		{
//			_ptr = tmp._ptr;
//			tmp._ptr = nullptr;
//		}
//		auto_ptr<T>& operator=(const auto_ptr<T>& tmp)
//		{
//			if (_ptr != tmp._ptr)
//			{
//				_ptr = tmp._ptr;
//				tmp._ptr = nullptr;
//			}
//			return *this;
//		}
//		~auto_ptr()
//		{
//			if (_ptr)
//				delete(_ptr);
//		}
//		T& operator*()
//		{
//			return *_ptr;
//		}
//		T* operator->()
//		{
//			return _ptr;
//		}
//	private:
//		T* _ptr;
//	};
//
//
//	template<class T>
//	class unique_ptr
//	{
//	public:
//		unique_ptr(T* ptr = nullptr)
//			:_ptr(ptr)
//		{}
//		~unique_ptr()
//		{
//			if (_ptr)
//				delete(_ptr);
//		}
//		T& operator*()
//		{
//			return *_ptr;
//		}
//		T* operator->()
//		{
//			return _ptr;
//		}
//		unique_ptr(const unique_ptr<T>&) = delete;
//		unique_ptr<T>& operator=(const unique_ptr<T>&) = delete;
//	private:
//		T* _ptr;
//	};
//}*/
#include<iostream>
#include<mutex>
using namespace std;
namespace lpf
{
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			,_pCount(new int(1))
			,_mtu(new mutex)
		{}
		shared_ptr(const shared_ptr<T>& tmp)
			:_ptr(tmp._ptr)
			,_pCount(tmp._pCount)
			,_mtu(tmp._mtu)
		{
			AddRef();
		}
		shared_ptr<T>& operator=(const shared_ptr<T>& tmp)
		{
			if (_ptr != tmp._ptr)
			{
				Release();

				_ptr = tmp._ptr;
				_pCount = tmp._pCount;
				AddRef();
			}
			return *this;
		}
		T* GetPtr() const
		{
			return _ptr;
		}
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		~shared_ptr()
		{
			Release();
		}
		void AddRef()
		{
			_mtu->lock();
			++(*_pCount);
			_mtu->unlock();
		}
	private:
		void Release()
		{
			bool flag = false;
			_mtu->lock();
			if (--(*_pCount) == 0)
			{
				delete(_pCount);
				delete(_ptr);
				flag = true;
			}
			_mtu->unlock();

			if (flag == true)
				delete(_mtu);
		}
		T* _ptr;
		int* _pCount;
		mutex* _mtu;
	};
	template<class T>
	class weak_ptr
	{
	public:
		weak_ptr()
			:_ptr(nullptr)
		{}
		weak_ptr(const shared_ptr<T>& tmp)
		{
			_ptr = tmp.GetPtr();
		}
		weak_ptr<T>& operator=(const shared_ptr<T>& tmp)
		{
			_ptr = tmp.GetPtr();
			return *this;
		}
	private:
		T* _ptr;
	};
	struct ListNode
	{
		weak_ptr<ListNode> _next;
		weak_ptr<ListNode> _prev;
		int _val;
	};

	void Test()
	{
		shared_ptr<ListNode> t1(new ListNode);
		shared_ptr<ListNode> t2(new ListNode);
		t1->_next = t2;
		t2->_prev = t1;
	}
}
int main()
{
	lpf::Test();
	return 0;
}