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
			, _pNext(nullptr)
			, _val(val)
		{}
		ListNode<T>* _pPre;
		ListNode<T>* _pNext;
		T _val;
	};

	template<class T, class Ref, class Ptr>
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
			return _pNode->_val;
		}
		T* operator->()
		{
			return &(_pNode->_val);
		}
		Self& operator++()
		{
			_pNode = _pNode->_pNext;
			return *this;
		}
		Self operator++(int)
		{
			Self temp(*this);
			_pNode = _pNode->_pNext;
			return temp;
		}
		Self& operator--()
		{
			_pNode = _pNode->_pPre;
			return *this;
		}
		Self operator--(int)
		{
			Self temp(*this);
			_pNode = _pNode->_pPre;
			return temp;
		}
		bool operator!=(const Self& l)const
		{
			return _pNode != l._pNode;
		}
		bool operator==(const Self& l)const
		{
			return _pNode == l._pNode;
		}

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
			CreateHead();
		}
		List(int n, const T& value = T())
		{
			CreateHead();
			for (int i = 0; i < n; i++)
				PushBack(value);
		}
		template<class Iterator>
		List(Iterator first, Iterator last)
		{
			CreateHead();
			while (first != last)
			{
				PushBack(*first);
				first++;
			}
		}
		List(const List<T>& l)
		{
			CreateHead();
			List<T> cur(l.CBegin(), l.CEnd());
			this->Swap(cur);
		}

		List<T>& operator=(const List<T>& l)
		{
			if (this != &l)
			{
				List<T> temp(l);
				this->Swap(temp);
			}
			return *this;
		}
		~List()
		{
			Clear();
			delete _pHead;
			_pHead = nullptr;
		}
		/////////////////////
		//List 迭代器 [）
		Iterator Begin()
		{
			return Iterator(_pHead->_pNext);
		}
		Iterator End()
		{
			return Iterator(_pHead);
		}
		ConstIterator CBegin()const
		{
			return ConstIterator(_pHead->_pNext);
		}
		ConstIterator CEnd()const
		{
			return ConstIterator(_pHead);
		}
		///////////////////
		//List 容量
		size_t size()const
		{
			int count = 0;
			PNode cur = _pHead;
			while (_pHead != cur->_pNext)
			{
				count++;
				cur = cur->_pNext;
			}
			return count;

		}
		bool Empty()const
		{
			return _pHead == _pHead->_pNext;
		}
		void Resize(size_t newSize, const T& val = T())
		{
			size_t oldSize = size();
			if (oldSize <= newSize)
			{
				int count = newSize - oldSize;
				while (count--)
				{
					PushBack(val);
				}
			}
			else if (oldSize > newSize)
			{
				int count = oldSize - newSize;
				while (count--)
				{
					PopBack();
				}
			}
		}
		//////////////////////
		//List Access
		T& Front()
		{
			if (_pHead == _pHead->_pNext)
				return;
			return _pHead->_pNext->_val;
		}
		const T& Front()const
		{
			if (_pHead == _pHead->_pNext)
				return;
			return _pHead->_pNext->_val;
		}
		T& Back()
		{
			if (_pHead == _pHead->_pNext)
				return;
			return _pHead->_pPre->_val;
		}
		const T& Back()const
		{
			if (_pHead == _pHead->_pNext)
				return;
			return _pHead->_pPre->_val;
		}
		////////////////
		//List Modify
		void PushBack(const T& val)
		{
			PNode newNode = new Node(val);
			newNode->_pPre = _pHead->_pPre;
			newNode->_pNext = _pHead;
			_pHead->_pPre = newNode;
			newNode->_pPre->_pNext = newNode;
		}
		void PopBack()
		{
			if (_pHead == _pHead->_pNext)
				return;
			PNode cur = _pHead->_pPre;
			_pHead->_pPre = cur->_pPre;
			cur->_pPre->_pNext = _pHead;
			delete cur;
		}
		void PushFront(const T& val)
		{
			PNode newNode = new Node(val);
			newNode->_pNext = _pHead->_pNext;
			newNode->_pPre = _pHead;
			_pHead->_pNext->_pPre = newNode;
			_pHead->_pNext = newNode;
		}
		void PopFront()
		{
			if (_pHead == _pHead->_pNext)
				return;
			PNode cur = _pHead->_pNext;
			cur->_pNext->_pPre = _pHead;
			_pHead->_pNext = cur->_pNext;
			delete cur;
		}
		void Swap(List<T>& l)
		{
			swap(_pHead, l._pHead);
		}
		void Clear()
		{
			if (_pHead == _pHead->_pNext)
				return;
			int count = size();
			while (count--)
			{
				PopBack();
			}
		}
		Iterator Insert(Iterator pos, const T& val)
		{
			PNode newNode = new Node(val);
			PNode cur = pos._pNode;
			newNode->_pNext = cur;
			cur->_pPre->_pNext = newNode;
			newNode->_pPre = cur->_pPre;
			cur->_pPre = newNode;
			return Iterator(newNode);
		}
		Iterator Erase(Iterator pos)
		{
			PNode cur = pos._pNode;
			PNode temp = pos._pNode->_pNext;
			cur->_pPre->_pNext = cur->_pNext;
			cur->_pNext->_pPre = cur->_pPre;
			delete cur;
			return Iterator(temp);
		}
	private:
		void CreateHead()
		{
			_pHead = new Node;
			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
		}
	private:
		PNode _pHead;
	};
}
template<class T>
void PrintList(lpf::List<T>& l)
{
	auto it = l.Begin();
	while (it != l.End())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
void TestList1()
{
	lpf::List<int> l1;
	lpf::List<int> l2(10, 5);
	PrintList(l2);
	int array[] = { 1,2,3,4,5,6,7,8,9,0 };
	lpf::List<int> l3(array, array + sizeof(array) / sizeof(array[0]));
	PrintList(l3);
	lpf::List<int> l4(l3);
	PrintList(l4);
}
void TestList2()
{
	lpf::List<int> l; 
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	PrintList(l);
	l.PopBack();
	l.PopBack();
	PrintList(l);
	l.PopBack();
	cout << l.size() << endl;
	// 测试PushFront与PopFront
	l.PushFront(1);
	l.PushFront(2);
	l.PushFront(3);
	PrintList(l);
	l.PopFront();
	l.PopFront();
	PrintList(l);
	l.PopFront();
	cout << l.size() << endl;
}
void TestList3()
{
	int array[] = { 1, 2, 3, 4, 5 };
	lpf::List<int> l(array, array + sizeof(array) / sizeof(array[0]));
	auto pos = l.Begin();
	l.Insert(l.Begin(), 0);
	PrintList(l);
	++pos; l.Insert(pos, 2);
	PrintList(l);
	l.Erase(l.Begin());
	l.Erase(pos);
	PrintList(l);
	// pos指向的节点已经被删除，pos迭代器失效
	//cout << *pos << endl;
	auto it = l.Begin();
	while (it != l.End())
	{
		it = l.Erase(it);
	}
	cout << l.size() << endl;
}
void TestList4()
{
	int array[] = { 1, 2, 3, 4, 5 };
	lpf::List<int> l1(array, array + sizeof(array) / sizeof(array[0]));
	cout << l1.size() << endl;
	PrintList(l1);
	l1.Resize(10, 6);
	cout << l1.size() << endl;
	PrintList(l1);
	l1.Resize(4);
	cout << l1.size() << endl;
	PrintList(l1);
	lpf::List<int> l2(array, array + sizeof(array) / sizeof(array[0]));
	PrintList(l1);
	PrintList(l2);
	l1.Swap(l2);
	PrintList(l1);
	PrintList(l2);
	l2.Clear();
	cout << l2.size() << endl;
}
int main()
{
	//TestList1();
	//TestList2();
	//TestList3();
	TestList4();
	return 0;
}