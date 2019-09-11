#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//1.getline遇到换行结束
//2.MyString 模拟实现
class String
{
public:
	//String()
	//	:_str(new char[1])
	//{
	//	*_str = '\0';
	//}
	String(const char* str = "")//不能给nullptr，因为这样会崩     
		:_str(new char[strlen(str)+1])//
	{
		strcpy(_str, str);
		_size = strlen(str);
		_capacity = _size;
	}
	~String()
	{
		delete[] _str;
		_str = nullptr;
		_size = _capacity = 0;
	}
	// s1 = s2
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			delete[] _str;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}
		return *this;
	}
	const char* c_str()
	{
		return _str;
	}
private:
	char* _str;
	size_t _size;
	size_t _capacity;
};
int main()
{
	system("pause");
	return 0;
}