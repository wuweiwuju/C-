#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
template<class T>
struct ListNode
{
	ListNode(const T& data = T())
	{

	}
	ListNode<T>* _pNext;
	ListNode<T>* _pPre;
	T _data;
};
namespace lpf
{
	template<class>
	class list
	{
		typedef ListNode<T> Node;
		typedef Node* PNode;
		list()
		{
			GreateHead();
		}
		list(size_t n, const T& data = T())
		{
			GreateHead();
			for (size_t i = 0; i < n; ++i)
			{
				push_back(data);
			}
		}
		list(T* first, T* last)
		{
			GreateHead();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		list(const list<T>& l)
		{
			PNode pCur = l._pHead->_pNext;
			while (pCur != l._pHead)
			{
				push_back(pCur->_data);
				pCur = pCur->_pNext;
			}
		}
		list<T>& operator=(const list<T>& l)
		{
			swap(_head, l._head);
			return *this;
		}
		size_t size()const
		{
			sizr_t count = 0;
			PNode pCur = _pHead->_pNext;
			while (pCur != _pHead)
			{
				count++;
				pCur = pCur->_pNext;
			}
			return count;
		}
		bool empty()const
		{
			return _pHead == _pHead->_pNext;
		}
		void resize(size_t newSize, const T& data = T())
		{
			size_t oldSize = size();
			if (oldSize < newSize)
			{
				for (size_t i = oldSize; i < newSize; i++)
					push_back(data);
			}
			else
			{
				for (size_t i = newSize; i < oldSize; i++)
					pop_back();
			}
		}
		////////////////////////
		////////// access
		T& front()
		{
			return _pHead->_pNext->_data;
		}
		const T& front()const
		{
			return _pHead->_pNext->_data;
		}
		T& back()
		{
			return _pHead->_pPre->_data;
		}
		const T& back()const
		{
			return _pHead->_pPre->_data;
		}
		//////////////////////////
		void PushBack(const T& val)
		{
			PNode pNewNode = new Node(val);
			// �Ȱ��½ڵ�β���ȥ
			pNewNode->_pNext = _pHead;
			pNewNode->_pPre = _pHead->_pPre;
			// ������ʣ������ָ��
			_pHead->_pPre = pNewNode;
			pNewNode->_pPre->_pNext = pNewNode;
		}
		// βɾ
		void PopBack()
		{
			// �ҵ���ɾ���ڵ�
			PNode pDel = _pHead->_pPre;
			if (pDel != _pHead)
			{
				_pHead->_pPre = pDel->_pPre;
				pDel->_pPre->_pNext = _pHead;
				delete pDel;
			}
		}
		// ͷ��
		void PushFront(const T& val)
		{
			PNode pNewNode = new Node(val);
			// �Ȱ��½ڵ�β���ȥ
			pNewNode->_pNext = _pHead->_pNext;
			pNewNode->_pPre = _pHead;
			// ������ʣ������ָ��
			_pHead->_pNext = pNewNode;
			pNewNode->_pNext->_pPre = pNewNode;
		}
		// ͷɾ
		void PopFront()
		{
			// �ҵ���ɾ���ڵ�
			PNode pDel = _pHead->_pNext;
				if (pDel != _pHead)
				{
					_pHead->_pNext = pDel->_pNext;
					pDel->_pNext->_pPre = _pHead;
					delete pDel;
				}
		}
		// ��posλ��ǰ����ֵΪval�Ľڵ�
		Iterator Insert(Iterator pos, const T& val)
		{
			PNode pNewNode = new Node(val);
			PNode pCur = pos._pNode;
			// �Ƚ��½ڵ����
			pNewNode->_pPre = pCur->_pPre;
			pNewNode->_pNext = pCur;
			pNewNode->_pPre->_pNext = pNewNode;
			pCur->_pPre = pNewNode;
			return Iterator(pNewNode);
		}
		// ɾ��posλ�õĽڵ㣬���ظýڵ����һ��λ��
		Iterator Erase(Iterator pos)
		{
			// �ҵ���ɾ���Ľڵ�
			PNode pDel = pos._pNode;
			PNode pRet = pDel->_pNext;
			// ���ýڵ�������в�������ɾ��
			pDel->_pPre->_pNext = pDel->_pNext;
			pDel->_pNext->_pPre = pDel->_pPre;
			delete pDel;
			return Iterator(pRet);
		}
		void swap(list<T>& l)
		{
			std::swap(_pHead, l._pHead);
		}
		void clear()
		{
			PNode pCur = _pHead->_pNext;
			while (pCur != _pHead)
			{
				_pHead->_pNext = pCur->_pNext;
				delete pCur;
				pCur = _pHead->_pNext;
			}
			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
		}
		~list()
		{
			clear();
			delete _pHead;
			_pHead = nullptr;
		}
	private:
		void GreateHead()
		{
			_pHead = new Node;
			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
		}
	private:
		PNode _pHead;
	};
}