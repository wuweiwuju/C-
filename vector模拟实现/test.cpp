#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;
//everything
namespace lpf
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{

		}
		vector(size_t n, const T& data = T())
			:_start(new T[n])
			, _finish(_start + n)
			, _end_of_storage(_finish)
		{
			for (size_t i = 0; i < n; ++i)
			{
				_start[i] = data;
			}
		}
		vector(T* first, T* last)
		{
			size_t size = last - first;
			_start = new T[size];
			for (size_t i = 0; i < size; ++i)
			{
				_start[i] = first[i];
			}
			_finish = _end_of_storage = _start + size;
		}
		vector(const vector<T>& v)
		{
			size_t size = v.size();
			_start = new T[size];
			for (size_t i = 0; i < size; ++i)
			{
				_start[i] = v[i];
			}
			_finish = _end_of_storage = _start + size;
		}
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}
		void resize(size_t n, const T& val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
				return;
			}
			if (n > capacity())
			{
				reserve(n);
			}
			while (_finish != _start + n)
			{
				*_finish = val;
				++_finish();
			}
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				T* temp = new T[n];
				if (_start)
				{
					for (size_t i = 0; i < size(); ++i)
					{
						temp[i] = _start[i];
					}
					delete[] _start;
					_start = temp;
					_finish = _start + size();
					_end_of_storage = _start + n;
				}
			}
		}

		///////////////////
		void push_back(const T& data)
		{
			if (_finish == _end_of_storage)
				reserve(2 * capacity());

			*_finish++ = data;
		}
		void pop_back()
		{
			assert(_finish > _start);
			--_finish;
		}
		iterator insert(iterator pos, const T& data)
		{
			if (_finish == _end_of_storage)
				reserve(2 * capacity());

			for (int i = size()-1; i >= pos - _start; --i)
			{
				_start[i + 1] = _start[i];
			}

			*pos = data;
			_finish++;
			return pos;
		}
		void erase(iterator pos)
		{
			iterator cur = pos;
			iterator curNext = cur + 1;
			while(curNext != _finish)
			{
				*cur++ = *curNext++;
			}
			return pos;
		}
		void clear()
		{
			_finish = _start;
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}
		size_t size()const
		{
			return _finish - _start;
		}
		size_t capacity()const
		{
			return _end_of_storage - _start;
		}
		T& operator[](size_t pos)
		{
			assert(pos <= size());
			return _start[pos];
		}
		const T& operator[](size_t pos)const 
		{
			assert(pos <= size());
			return _start[pos];
		}
		// iterator
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
}
void PrintVector(lpf::vector<int>& v)
{
	auto it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
int main()
{
	lpf::vector<int> v1;
	lpf::vector<int> v2(10, 5);
	PrintVector(v2);
	int array[] = { 1,2,3,4,5,6,7,8,9,0 };
	lpf::vector<int> v3(array, array + sizeof(array)/sizeof(int));
	PrintVector(v3);
	lpf::vector<int> v4(v3);
	PrintVector(v4);
	return 0;
}

