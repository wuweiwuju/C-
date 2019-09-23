#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
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
				_finsh = _start + n;
				return;
			}
			if (n > capacity())
			{
				reserve(n);
			}
			while (finsh != start + n)
			{
				*_finsh = val;
				++_finsh();
			}
		}
		void reserve(size_t n)
		{

		}
		void push_back()
		{

		}
		void pop_back()
		{
			assert(_finsh > _start);
			--_finsh;
		}
		void insert(iterator pos, const T& x)
		{

		}
		void erase(iterator pos)
		{

		}
		size_t size()const
		{
			return _finsh - _start;
		}
		size_t capacity()const
		{
			return _end_of_storage - _start;
		}
		T& operator[](size_t pos)
		{
			return _start[pos];
		}
		const T& operator[](size_t pos)const 
		{
			return _start[pos];
		}
	private:
		T* _a;
		size_t _size;
		size_t _capacity;

		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};

	void test_vector()
	{

	}
}
int main()
{

}