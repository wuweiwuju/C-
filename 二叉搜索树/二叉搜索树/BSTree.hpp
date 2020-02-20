//.hpp����ģ��Ļ�����������һ��
#pragma once
#include<iostream>
using namespace std;
template<class T>
struct BSTNode
{
	BSTNode(const T& data = T())
		:_pLeft(nullptr)
		,_pRight(nullptr)
		,_data(data)
	{}
	BSTNode<T>* _pLeft;
	BSTNode<T>* _pRight;
	T _data;
};

template<class T>
class BSTree
{
	typedef BSTNode<T> Node;
public:
	BSTree()
		:_pRoot(nullptr)
	{}

	~BSTree()
	{
		_Destroy(_pRoot);
	}

	Node* Find(const T& data)
	{
		Node* pCur = _pRoot;
		while (pCur)
		{
			if (data == pCur->_data)
				return pCur;
			else if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else
				pCur = pCur->_pRight;
		}
		return nullptr;
	}

	bool Insert(const T& data)
	{
		//����
		if (_pRoot == nullptr)
		{
			_pRoot = new Node(data);
			return true;
		}
		//�ǿգ��ҵ�ǰ�ڵ��ڶ�����������λ��
		Node* pCur = _pRoot;
		Node* pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;

			if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else if (data > pCur->_data)
				pCur = pCur->_pRight;
			else
				return false;
		}
		//����ڵ�
		pCur = new Node(data);
		if (pParent->_data > data)
			pParent->_pLeft = pCur;
		else
			pParent->_pRight = pCur;

		return true;
	}

	bool Delete(const T& data)
	{
		if (nullptr == _pRoot)
			return false;

		//���ݶ����������Ĺ����Ҵ�ɾ���ڵ��λ��
		Node* pCur = _pRoot;
		Node* pParent = nullptr;
		while (pCur)
		{
			if (data == pCur->_data)
				break;
			else if (data < pCur->_data)
			{
				pParent = pCur;
				pCur = pCur->_pLeft;
			}
			else
			{
				pParent = pCur;
				pCur = pCur->_pRight;
			}
		}
		//������������û��ֵΪdata�Ľڵ�
		if (nullptr == pCur)
			return false;

		/*
		1.Ҷ�ӽڵ�--->ֱ��ɾ��
		2.ֻ������-->ֱ��ɾ��
		3.ֻ���Һ���-->ֱ��ɾ��
		4.���Һ��Ӿ�����--->��һ������ڵ㣨����������� || ����������С��
		1������2 || 1������3�ϲ�Ϊһ�����
		*/
		//Ҷ�Ӻ�ֻ���Һ��ӵĽڵ�
		if (nullptr == pCur->_pLeft)
		{
			//��ɾ���ڵ�Ϊ���ڵ�
			if (pCur == _pRoot)
				_pRoot = pCur->_pRight;
			else
			{
				//��ɾ���ڵ�Ϊ��˫�׵�����
				if (pCur == pParent->_pLeft)
					pParent->_pLeft = pCur->_pRight;
				else
					pParent->_pRight = pCur->_pRight;
			}
		}
		else if (nullptr == pCur->_pRight)
		{
			//ֻ������
			if (pCur == _pRoot)
				_pRoot = pCur->_pLeft;
			else
			{
				if (pCur == pParent->_pLeft)
					pParent->_pLeft = pCur->_pLeft;
				else
					pParent->_pRight = pCur->_pLeft;
			}
		}
		else
		{
			//pCur���Һ��Ӿ�����
			//������ڵ� ���������������Ҳ������С�Ľڵ㣩
			Node* pFirstOfIn = pCur->_pRight;
			pParent = pCur;
			while (pFirstOfIn->_pLeft)
			{
				pParent = pFirstOfIn;
				pFirstOfIn = pFirstOfIn->_pLeft;
			}

			pCur->_data = pFirstOfIn->_data;
			if (pFirstOfIn == pParent->_pLeft)
				pParent->_pLeft = pFirstOfIn->_pRight;
			else
				pParent->_pRight = pFirstOfIn->_pRight;

			pCur = pFirstOfIn;

		}
		delete pCur;
		return true;
	}

	Node* LeftMost()
	{
		if (nullptr == _pRoot)
			return nullptr;
		Node* pCur = _pRoot;
		while (pCur->_pLeft)
		{
			pCur = pCur->_pLeft;
		}

		return pCur;
	}

	Node* RightMost()
	{
		if (nullptr == _pRoot)
			return nullptr;
		Node* pCur = _pRoot;
		while (pCur->_pRight)
		{
			pCur = pCur->_pRight;
		}

		return pCur;
	}

	void InOrder()
	{
		_InOrder(_pRoot);
	}


private:
	void _InOrder(Node* pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->_pLeft);
			cout << pRoot->_data << " ";
			_InOrder(pRoot->_pRight);
		}
	}
	void _Destroy(Node*& pRoot)
	{
		if (pRoot)
		{
			_Destroy(pRoot->_pLeft);
			_Destroy(pRoot->_pRight);
			delete pRoot;
			pRoot = nullptr;
		}
	}
private:
	Node* _pRoot;
};
void TestBSTree()
{
	int array[] = { 5,3,4,1,7,8,2,6,0,9 };
	BSTree<int> t;

	for (auto e : array)
		t.Insert(e);

	cout << t.LeftMost()->_data << endl;
	cout << t.RightMost()->_data << endl;
	BSTNode<int>* pCur = t.Find(2);
	if (pCur)
		cout << "2 is in BSTree!!!" << endl;
	else
		cout << "2 is not in BSTree!!!" << endl;
	t.InOrder();
	cout << endl;
	t.Delete(8);
	t.InOrder();
	cout << endl;
	t.Delete(0);
	t.InOrder();
	cout << endl;
	t.Delete(1);
	t.InOrder();
}