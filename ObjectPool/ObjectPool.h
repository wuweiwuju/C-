#pragma once
template<class T, size_t initNum = 100>
//ģ��ʵ�ֵ���new �� delete  ���⿪�ٿռ���ҳ�ʼ��
//�������������  û�н���ڴ���Ƭ����
//ȱ�㣺����
class ObjectPool
{
public:
	ObjectPool()
	{
		_itemSize = sizeof(T) < sizeof(T*) ? sizeof(T*) : sizeof(T);
		_start = (char*)malloc(initNum * _itemSize);
		_end = _start + initNum * _itemSize;
		_freeList = nullptr;
	}

	T*& Next_Obj(T* obj)
	{
		return *(T * *)obj;
	}

	//T* Alloc()
	/*T* New()
	{
		//1.���freeList�ж�������ȡ�����
		//2.�����ٵ�������ȡ
		T* obj = nullptr;
		if (_freeList != nullptr)
		{
			obj = _freeList;
			_freeList = Next_Obj(obj);
		}
		else
		{
			if (_start == _end)
			{
				_start = (char*)malloc(initNum * _itemSize);
				_end = _start + initNum * _itemSize;
			}

			obj = (T*)_start;
			_start += _itemSize;
		}

		// new�Ķ�λ���ʽ
		new(obj)T;

		return obj;
	}*/
	T* New()
	{
		//1.���freeList�ж�������ȡ�����
			//2.�����ٵ�������ȡ
		T* obj = nullptr;
		if (_freeList != nullptr)
		{
			obj = _freeList;
			_freeList = Next_Obj(obj);
		}
		else
		{
			if (_start == _end)
			{
				_start = (char*)malloc(initNum * _itemSize);
				_end = _start + initNum * _itemSize;
			}

			obj = (T*)_start;
			_start += _itemSize;
		}
		//new�Ķ�λ���ʽ
		new(obj)T;

		return obj;
	}
	void Delete(T* ptr)
	{
		ptr->~T();

		Next_Obj(ptr) = _freeList;
		_freeList = ptr;
	}
private:
	char* _start;
	char* _end;	//�����ڴ��ָ��
	size_t _itemSize;

	T* _freeList;
};

void TestObjectPool()
{
	ObjectPool<int> pool;
	int* p1 = pool.New();
	int* p2 = pool.New();
	int* p3 = pool.New();

	pool.Delete(p1);
	pool.Delete(p2);
	pool.Delete(p3);

	cout << p1 << endl;
	cout << p2 << endl;
	cout << p3 << endl << endl;;

	int* p4 = pool.New();
	int* p5 = pool.New();
	int* p6 = pool.New();

	pool.Delete(p4);
	pool.Delete(p5);
	pool.Delete(p6);

	cout << p4 << endl;
	cout << p5 << endl;
	cout << p6 << endl;

}
#include<vector>
#include<time.h>

void BenchMark()
{
	size_t n = 1000000;

	vector<string*> v1;
	v1.reserve(n);
	size_t begin1 = clock();

	for (size_t i = 0; i < n; i++)
	{
		v1.push_back(new string);
	}

	for (size_t i = 0; i < n; ++i)
	{
		delete v1[i];
	}

	size_t end1 = clock();

	v1.clear();

	cout << "ֱ��ϵͳ�����ڴ�:" << end1 - begin1 << endl;

	//ģ��ʵ�ֵ���new �� delete
	vector<string*> v2;
	v2.reserve(n);
	ObjectPool<string> pool;
	size_t begin2 = clock();

	for (size_t i = 0; i < n; ++i)
	{
		v2.push_back(pool.New());
	}

	for (size_t i = 0; i < n; ++i)
	{
		pool.Delete(v2[i]);
	}

	size_t end2 = clock();

	v2.clear();

	cout << "Pool�����ڴ�:" << end2 - begin2 << endl;
}

