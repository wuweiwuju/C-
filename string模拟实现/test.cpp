#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//反例
//namespace lpf
//{
//	class string
//	{
//	public:
//		string(const char* str = "")
//		{
//			/*if (nullptr == str)
//			{
//				_str = new char[1];
//				*_str = '\0';
//			}
//			_str = new char[strlen(str)+1];
//			strcpy(_str, str);*/
//
//			if (nullptr == str)
//				str = "";
//
//			_str = new char[strlen(str) + 1];
//			strcpy(_str, str);
//		}
//		//浅拷贝
//		string(const string& s)
//			:_str(s._str)
//		{
//
//		}
//		//浅拷贝
//		string& operator=(const string& s)
//		{
//			_str = s._str;
//			return *this;
//		}
//		~string()
//		{
//			if (_str)
//			{
//				delete[] _str;
//				_str = nullptr;
//			}
//		}
//	private:
//		char* _str;
//	};
//}
//void TestString()
//{
//	lpf::string s1("hello");
//	lpf::string s2("nullptr");
//	//lpf::string s3(s1);
//
//	s2 = s1;
//}
//int main()
//{
//	TestString();
//	return 0;
//
//}
//浅拷贝：值的拷贝
//深拷贝：


//深拷贝---传统版
//namespace lpf
//{
//	class string
//	{
//	public:
//		string(const char* str = "")
//		{
//			/*if (nullptr == str)
//			{
//				_str = new char[1];
//				*_str = '\0';
//			}
//			_str = new char[strlen(str)+1];
//			strcpy(_str, str);*/
//
//			if (nullptr == str)
//				str = "";
//
//			_str = new char[strlen(str) + 1];
//			strcpy(_str, str);
//		}
//		//深拷贝
//		string(const string& s)
//			:_str(new char[strlen(s._str)+1])
//		{
//			strcpy(_str, s._str);
//		}
//		//深拷贝
//		string& operator=(const string& s)
//		{
//			if (this != &s)
//			{
//				/*
//				delete[] _str;
//				_str = new char[strlen(s._str) + 1];
//				strcpy(_str, s._str);
//				*/
//				//不会对当前对象产生影响
//				char* pStr = new char[strlen(s._str) + 1];
//				strcpy(pStr, s._str);
//				delete[] _str;
//				_str = pStr;
//			}
//			return *this;
//		}
//		~string()
//		{
//			if (_str)
//			{
//				delete[] _str;
//				_str = nullptr;
//			}
//		}
//	private:
//		char* _str;
//	};
//}
//void TestString()
//{
//	lpf::string s1("hello");
//	lpf::string s2("nullptr");
//	lpf::string s3(s1);
//
//	s2 = s1;
//}
//int main()
//{
//	TestString();
//	return 0;
//
//}

//深拷贝---现代版
//namespace lpf
//{
//	class string
//	{
//	public:
//		string(const char* str = "")
//		{
//
//			if (nullptr == str)
//				str = "";
//
//			_str = new char[strlen(str) + 1];
//			strcpy(_str, str);
//		}
//		
//		string(const string& s)
//			:_str(nullptr)//防止崩溃
//		{
//			string strTemp(s._str);
//			swap(_str, strTemp._str);
//		}
//		
//	/*	string& operator=(const string& s)
//		{
//			if (this != &s)
//			{
//				string strTemp(s);
//				swap(_str, strTemp._str);
//			}
//			return *this;
//		}*/
//
//	/*	string& operator=(const string& s)
//		{
//			string strTemp(s);
//			swap(_str, strTemp._str);
//			return *this;
//		}*/
//
//		string& operator=(string s)
//		{
//			swap(_str, s._str);
//			return *this;
//		}
//
//		~string()
//		{
//			if (_str)
//			{
//				delete[] _str;
//				_str = nullptr;
//			}
//		}
//	private:
//		char* _str;
//	};
//}
//void TestString()
//{
//	lpf::string s1("hello");
//	lpf::string s2("nullptr");
//	lpf::string s3(s1);
//
//	s2 = s1;
//}
//int main()
//{
//	TestString();
//	return 0;
//}
//引用计数 
//namespace lpf
//{
//	class string
//	{
//	public:
//		string(const char* str = "")
//		{
//			if (nullptr == str)
//			{
//				str = "";
//			}
//			_str = new char[strlen(str) + 1];
//			strcpy(_str, str);
//			_count = 1;
//		}
//		string(string& s)
//			:_str(s._str)
//		{
//			++_count;
//		}
//		~string()
//		{
//			if (0 == --_count)
//			{
//				delete[] _str;
//				_str = nullptr;
//			}
//		}
//	private:
//		char* _str;
//		static int _count;
//};
//}
//int lpf::string::_count = 0;
//void TestString()
//{
//	lpf::string s1("hello");
//	lpf::string s2(s1);
//	//lpf::string s3("world");//静态也不行
//	//s2 = s1;
//}
//int main()
//{
//
//}
//namespace lpf
//{
//	class string
//	{
//	public:
//		string(const char* str = "")
//		{
//			if (nullptr == str)
//			{
//				str = "";
//			}
//			_str = new char[strlen(str) + 1];
//			strcpy(_str, str);
//			_pCount = new int(1);
//		}
//		string(const string& s)
//			:_str(s._str)
//			,_pCount(s._pCount)
//		{
//			++(*_pCount);
//		}
//		string& operator=(const string& s)
//		{
//			if (this != &s)
//			{
//				Release();
//
//				_str = s._str;
//				_pCount = s._pCount;
//				++(*_pCount);
//			}
//		}
//
//		char& operator[](size_t index)
//		{
//			if (*_pCount > 1)
//			{
//				string strTemp(_str);
//				Swap(strTemp);
//			}
//			return _str[index];
//		}
//
//		const char& operator[](size_t index)const
//		{
//			return _str[index];
//		}
//
//		~string()
//		{
//			Release();
//		}
//		void Swap(string& s)
//		{
//			swap(_str, s._str);
//			swap(_pCount, s._pCount);
//		}
//	private:
//		void Release()
//		{
//			if (_str && 0 == --(*_pCount))
//			{
//				delete[] _str;
//				delete _pCount;
//				_str = nullptr;
//				_pCount = nullptr;
//			}
//		}
//	private:
//		char* _str;
//		int* _pCount;
//	};
//}
//void TestString()
//{
//	lpf::string s1("hello");
//	lpf::string s2(s1);
//	lpf::string s3("world");
//	lpf::string s4(s3);
//
//	s1 = s3;//s1 s3 s4共用一份空间  s2共用一份
//
//	s2 = s4;//s1 s2 s3 s4共用同一份
//
//	s1[0] = 'H';
//}
//int main()
//{
//	TestString();
//	return 0;
//}
#include<assert.h>
//namespace lpf
//{
//	class string
//	{
//	public:
//		typedef char* iterator;
//	public:
//		string(const char* str = "")
//		{
//			if (nullptr == str)
//				str = "";
//			_size = strlen(str);
//			_capacity = _size;
//			_str = new char[_capacity + 1];
//			strcpy(_str, str);
//		}
//		string(size_t n, char c)
//			:_str(new char[n+1])
//			,_capacity(n)
//			,_size(n)
//		{
//			memset(_str, c, _size);
//		}
//		string(const char* pstr, size_t n)
//		{
//			size_t length = strlen(pstr);
//			_size = length > n ? n : length;
//			_capacity = _size;
//			_str = new char[_capacity + 1];
//			for (size_t i = 0; i < _size; ++i)
//			{
//				_str[i] = pstr[i];
//			}
//			_str[_size] = '\0';
//		}
//		//深拷贝
//		string(const string& s)
//			:_str(new char[strlen(s._str)+1])
//		{
//			strcpy(_str, s._str);
//		}
//		//深拷贝
//		string& operator=(const string& s)
//		{
//			if (this != &s)
//			{
//				//不会对当前对象产生影响
//				char* pStr = new char[strlen(s._str) + 1];
//				strcpy(pStr, s._str);
//				delete[] _str;
//				_str = pStr;
//			}
//			return *this;
//		}
//		~string()
//		{
//			if (_str)
//			{
//				delete[] _str;
//				_str = nullptr;
//			}
//		}
//		iterator begin()
//		{
//			return _str;
//		}
//		iterator end()
//		{
//			return _str + _size;
//		}
//		//capacity
//		size_t size()const
//		{
//			return _size;
//		}
//		size_t length()const
//		{
//			return _size;
//		}
//
//		size_t capacity()const
//		{
//			return _capacity;
//		}
//		bool empty()const
//		{
//			return 0 == _size;
//		}
//		void clear()
//		{
//			_size = 0;
//			_str[0] = '\0';
//		}
//		//将对象中有效元素的个数改变到newSize,多出的字符用ch进行填充
//		void resize(size_t newSize, char ch = char())
//		{
//			size_t oldSize = size();
//			if (newSize < oldSize)
//			{
//				_size = newSize;
//				_str[_size] = '\0';
//			}
//			else
//			{
//				if (newSize > capacity())
//				{
//					size_t newCapacity = capacity() * 2;
//					reserve(newCapacity);
//				}
//		
//				memset(_str + _size, ch, newSize - oldSize);
//				_size = newSize;
//				_str[_size] = '\0';
//			}
//		}
//		void reserve(size_t newCapacity)
//		{
//			if (newCapacity > capacity())
//			{
//				char* pStr = new char[newCapacity + 1];
//				strcpy(pStr, _str);
//				delete[] _str;
//				_str = pStr;
//				_capacity = newCapacity;
//			}
//		}
//		char& operator[](size_t index)
//		{
//			assert(index < size());
//			return _str[index];
//		}
//		const char& operator[](size_t index)const
//		{
//			assert(index < size());
//			return _str[index];
//		}
//		string& operator+=(const string& s)
//		{
//			size_t leftByte = _capacity - _size;
//			size_t totalByte = s.size();
//			if (totalByte > leftByte)
//			{
//				reserve(totalByte +_size);
//			}
//			strcpy(_str + _size, s._str);
//			_size += totalByte;
//			return *this;
//		}
//		void push_back(char ch)
//		{
//			if (_size == _capacity)
//			{
//				reserve(2 * _capacity);
//			}
//			_str[_size++] = ch;
//			_str[_size] = '\0';
//		}
//		void append(size_t n, char ch)
//		{
//			size_t leftByte = _capacity - _size;
//			if (n > leftByte)
//			{
//				reserve(n + _size);
//			}
//
//			memset(_str + _size, ch, n);
//			_size += n;
//			_str[_size] = '\0';
//		}
//		void swap(string& s)
//		{
//			std::swap(_str, s._str);
//			std::swap(_size, s._size);
//			std::swap(_capacity, s._capacity);
//		}
//
//		const char* c_str()const
//		{
//			return _str;
//		}
//		size_t find(char ch, size_t pos = 0)
//		{
//			for (size_t i = pos; i < _size; ++i)
//			{
//				if (ch == _str[i])
//					return i;
//			}
//			return npos;
//		}
//		size_t rfind(char ch, size_t pos = npos)
//		{
//			if (pos == npos)
//				pos = _size - 1;
//			for (int i = pos; i >= 0 ; --i)
//			{
//				if (_str[i] == ch)
//					return i;
//			}
//			return npos;
//		}
//		string strsub(size_t pos = 0, size_t n = npos)const
//		{
//			return string(_str + pos, n);
//		}
//		friend ostream& operator<<(ostream& _cout, const string& s)
//		{
//			_cout << s._str;
//			return _cout;
//		}
//		bool operator<(const string& s)const
//		{
//			for (int i = 0; i < s.size(); i++)
//			{
//				if (_str[i] < s[i])
//					return true;
//				else if (_str[i] > s[i])
//					return false;
//			}
//			return false;
//		}
//		bool operator<=(const string& s)const
//		{
//			for (int i = 0; i < s.size(); i++)
//			{
//				if (_str[i] < s[i])
//					return true;
//				else if (_str[i] > s[i])
//					return false;
//			}
//			return true;
//		}
//		bool operator>(const string& s)const
//		{
//			if (_str < s._str)
//			{
//				return false;
//			}
//			return true;
//
//		}
//		bool operator>=(const string& s)const
//		{
//			if (_str <= s._str)
//			{
//				return false;
//			}
//			return true;
//		}
//		bool operator!=(const string& s)const
//		{
//			if (_str == s._str)
//				return false;
//			return true;
//		}
//		bool operator==(const string& s)const
//		{
//			if (_str < s._str)
//				return false;
//			if (_str > s._str)
//				return false;
//			return true;
//		}
//		size_t Find(char c, size_t pos = 0) const
//		{
//			for (int i = 0; i < _size; i++)
//			{
//				if (_str[i] == c)
//					return i + 1;
//			}
//			return -1;
//		}
//		// 返回子串s在string中第一次出现的位置
//		size_t Find(const char* s, size_t pos = 0) const
//		{
//			int size = strlen(s);
//			int j = 0;
//			int k = 1;
//			for (int i = 0; i < _size; i++)
//			{
//				if (_str[i] == s[0])
//				{
//					j = i + 1;
//					while (size--)
//					{
//						if (_str[j++] != s[k++])
//						{
//							break;
//						}
//					}
//					if (size == 0)
//						return i + 1;
//				}
//			}
//			return -1;
//		}
//		// 截取string从pos位置开始的n个字符
//		string SubStr(size_t pos, size_t n)
//		{
//			return string(_str + pos, n);
//		}
//		// 在pos位置上插入字符c/字符串str
//		string& Insert(size_t pos, char c)
//		{
//			if (pos > 0 && pos <= _size)
//			{
//				if (_size == _capacity)
//					reserve(2 * _capacity);
//				for (int i = _size; i >= pos; i--)
//				{
//					_str[i] = _str[i - 1];
//				}
//				_str[pos - 1] = c;
//				_str[_size + 1] = '\0';
//				return *this;
//			}
//		}
//		string& Insert(size_t pos, const char* str)
//		{
//			if (pos > 0 && pos <= _size)
//			{
//				if ( (_size+strlen(str)) > _capacity )
//					reserve(_size + strlen(str));
//				int len = strlen(str);
//				int j = 0;
//				for (int i = _size; i >= pos; i--)
//				{
//					_str[i + len - 1] = _str[i - 1];
//				}
//				for (int i = pos - 1; i < pos + len - 1; i++)
//				{
//					_str[i] = str[j];
//					j++;
//				}
//				_str[len + _size] = '\0';
//				return *this;
//			}
//		}
//		// 删除pos位置上的元素，并返回该元素的下一个位置  len是pos位置后面len个元素
//		string& Erase(size_t pos, size_t len)
//		{
//			assert(pos < _size);
//			int j = 0;
//			int i = 0;
//			for (i = pos - 1; j < _size; i++,j++)
//			{
//				if (i == pos - 1)
//				{
//					_str[i] = _str[len + i];
//					j = len + i;
//				}
//				_str[i] = _str[j + 1];
//			}
//			_str[i] = '\0';
//			//this是当前对象的指针，*this是当前对象
//			return *this;
//		}
//private:
//	friend ostream& operator<<(ostream& _cout, const lpf::string& s);
//	private:
//		char* _str;
//		size_t _capacity;
//		size_t _size;
//		static const size_t npos;
//	};
//	const size_t string::npos = -1;
//}
//void TestString()
//{
//	lpf::string s1("helloossooss");
//	lpf::string s2(10, 'a');
//	lpf::string s3("world", 5);
//	lpf::string s4(s3);
//	const char* str = " world";
//	cout << s1.Erase(1,3) << endl;
//	//cout << s1.Find("oss") << endl;
//	//cout << s1.Insert(1, 'c');
//	//cout << s1.Insert(2, str) << endl;
//	/*cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//	cout << (s1 > s2 )<< endl;
//	cout << (s1 == s2) << endl;
//	cout << (s1 != s2) << endl;
//	cout << (s1 < s2) << endl;
//	cout << (s1 >= s2) << endl;
//	cout << (s1 <= s2) << endl;*/
///*	auto it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it;
//		++it;
//	}
//	cout << endl;
//
//	s1.push_back(' ');
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//
//	s1 += s3;
//	cout << s1.strsub(s1.rfind(' ')+1);
//	s1.resize(20, '$');
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//	cout << s1 << endl;
//	s1.resize(5);
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//	cout << s1 << endl;
//	s1.resize(10);
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//	cout << s1 << endl;
//	s1.clear();*/
//}
//int main()
//{
//	TestString();
//	return 0;
//}

//实现一个简单的string
class my_string
{
private:
	char* _str;
public:
	my_string(const char* str = "")
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);
	}
	my_string(const my_string& s)
		:_str(nullptr)
	{
		my_string tmp(s._str);
		swap(tmp._str, _str);
	}
	/*my_string& operator=(const my_string& s)
	{
		if (this != &s)
		{
			my_string tmp(s);
			swap(tmp._str, _str);
		} 
		return *this;
	}*/
	my_string& operator=(my_string s)
	{
		swap(_str, s._str);
		return *this;
	}
	~my_string()
	{
		delete[] _str;
	}
};
int main()
{
	return 0;
}