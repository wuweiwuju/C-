#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace  std;
#include<assert.h>
#include<algorithm>
namespace lpf
{
	template<class T>
	class vector
	{
	public:
		//vector的迭代器是一个原生指针
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator c_begin()const
		{
			return _start;
		}
		const_iterator c_end()const
		{
			return _finish;
		}
		size_t size()const
		{
			return _finish - _start;
		}
		size_t capacity()const
		{
			return _end_of_storage - _start;
		}
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{}
		vector(int n, const T& value = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			reserve(n);
			while (n--)
			{
				PushBack(value);
			}
		}
		//这里如果使用iterator做迭代器，就会导致初始化的迭代器区间[first,last]只能是vector的迭代器
		// 这里重新声明迭代器，迭代器区间[first,last]可以是任意容器的迭代器区间。
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			reserve(last - first);
			while (first != last)
			{
				PushBack(*first);
				++first;
			}
		}
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			reserve(v.capacity());
			iterator it = begin();
			const_iterator cit = v.c_begin();
			while (cit != v.c_end())
			{
				*it++ = *cit++;
			}
			_finish = _start + v.size();
			_end_of_storage = _start + v.capacity();
		}
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}
		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}
		void reserve(size_t n)
		{
			if (capacity() < n)
			{
				size_t sz = size();
				T* temp = new T[n];
				if (_start)
				{
					for (size_t i = 0; i < sz; ++i)
					{
						temp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = temp;
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}
		void resize(size_t n, const T& value = T())//有效元素个数的调整
		{
			if (n > size())
			{
				reserve(n);
				iterator it = begin() + size();
				iterator nit = begin() + n;
				while (it < nit)
				{
					PushBack(value);
					it++;
				}
			}
			else if (n < size())
			{
				iterator it = begin() + n;
				iterator eit = end();
				while (it != eit)
				{
					_finish--;
					it++;
				}
			}
		}
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}
		void PushBack(const T& x)
		{
			Insert(end(), x);
		}
		void PopBack()
		{
			assert(_finish > _start);
			--_finish;
		}
		iterator Insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _finish);

			if (_finish == _end_of_storage)
			{
				size_t n = pos - _start;
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);
				pos = _start + n;
			}

			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}

			*pos = x;
			++_finish;
			return pos;
		}
		iterator Erase(iterator pos)
		{
			while (pos < (end()-1))
			{
				*(pos) = *(pos + 1);
				pos++;
			}
			_finish = _finish - 1;
			return pos;
		}
		T& operator[](size_t pos)
		{
			return _start[pos];
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
}
void TestVector1()
{
	// constructors used in the same order as described above:
	lpf::vector<int> first; // empty vector of ints
	lpf::vector<int> second(4, 100); // four ints with value 100
	lpf::vector<int> third(second.begin(), second.end()); // iterating through second
	lpf::vector<int> fourth(third); // a copy of third
	//// the iterator constructor can also be used to construct from arrays:
	//int myints[] = { 16, 2, 77, 29 };
	//lpf::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
	//std::cout << "The contents of fifth are:";
	//for (bit::Vector<int>::Iterator it = fifth.Begin(); it != fifth.End(); ++it)
	//	std::cout << ' ' << *it;
	//std::cout << '\n';
	//// 测试T是string时，拷贝问题
	lpf::vector<int> strV;
	strV.PushBack(1);
	strV.PushBack(2);
	strV.PushBack(3);
	strV.PushBack(4);
	for (size_t i = 0; i < strV.size(); ++i)
	{
		cout << strV[i] << " ";
	}
	cout << endl;
}
void TestVector5()
{
	int a[] = { 1, 2, 3, 4 };
	lpf::vector<int> v(a, a + sizeof(a) / sizeof(int));
	// 使用find查找3所在位置的iterator
	lpf::vector<int>:: iterator pos = find(v.begin(), v.end(), 3);
	// 在pos位置之前插入30
	v.Insert(pos, 30);
	lpf::vector<int>::iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	pos = find(v.begin(), v.end(), 3);
	// 删除pos位置的数据
	v.Erase(pos);
	it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
int main()
{
	//TestVector1();
	TestVector5();
	return 0;
}