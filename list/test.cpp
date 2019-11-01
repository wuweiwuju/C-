#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
namespace lpf
{
	//List的结点类
	template<class T>
	struct ListNode
	{
		ListNode(const T& val = T())
			:_pPre(nullptr)
			,_pNext(nullptr)
			,_val(val)
		{}
		ListNode<T>* _pPre;
		ListNode<T>* _pNext;
		T _val;
	};

	template<class T,class Ref,class Ptr>
	class ListIterator
	{
		typedef ListNode<T>* PNode;
		typedef ListIterator<T, Ref, Ptr> Self;
	public:
		ListIterator(PNode pNode = nullptr)
			:_pNode(pNode)
		{}
		ListIterator(const Self& l)
			:_pNode(l._pNode)
		{}
		T& operator*()
		{

		}
		T* operator->()
		{

		}
		Self& operator++()
		{

		}
		Self operator++(int)
		{

		}
		Self& operator--()
		{

		}
		Self operator--(int)
		{

		}
		bool operator!=(const Self& l)const
		{

		}
		bool operator==(const Self& l)const
		{

		}
	private:
		PNode _pNode;
	};

	template<class T>
	class List
	{
		typedef ListNode<T> Node;
		typedef Node* PNode;
	public:
		typedef ListIterator<T, T&, T*> Iterator;
		typedef ListIterator<T, const T&, const T&> ConstIterator;
	public:
		//List的构造
		List()
		{

		}
		List(int n, const T& value = T())
		{

		}
		template<class Iterator>
		List(Iterator first, Iterator last)
		{

		}
		List(const List<T>& l)
		{

		}

		List<T>& operator=(const List<T>& l)
		{

		}
		~List()
		{

		}
		/////////////////////
		//List 迭代器 [）
		Iterator Begin()
		{

		}
		Iterator End()
		{

		}
		ConstIterator CBegin()const
		{

		}
		ConstIterator CEnd()const
		{

		}
		///////////////////
		//List 容量
		size_t size()const
		{

		}
		bool Empty()const
		{

		}
		void Resize(size_t newSize, const T& val = T())
		{

		}
		//////////////////////
		//List Access
		T& Front()
		{

		}
		const T& Front()const
		{

		}
		T& Back()
		{

		}
		const T& Back()const
		{

		}
		////////////////
		//List Modify
		void PushBack(const T& val)
		{

		}
		void PopBack()
		{

		}
		void PushFront(const T& val)
		{

		}
		void PopFront()
		{

		}
		//?
		void Swap(List<T>& l)
		{

		}
		void Clear()
		{

		}
		Iterator Insert(Iterator pos,const T& val)
		{

		}
		Iterator Erase(Iterator pos)
		{

		}
	private:
		void CreateHead()
		{

		}
		private:
			PNode _pHead;
	};
}