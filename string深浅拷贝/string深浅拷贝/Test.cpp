#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string.h>
#include<assert.h>
#include<algorithm>
using namespace std;
/*class String
{
public:
	String(const char* str = "")
	{
		//����string�����ʱ���������nullptrָ�룬��Ϊ����Ƿ����˴�������
		if (nullptr == str)
		{
			assert(false);
			return;
		}

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};*/
//��ͳ��
/*class String
{
public:
	String(const char* str = "")
	{
		if (str == nullptr)
			str = "";

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s)
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pStr = new char[strlen(s._str) + 1];
			strcpy(pStr, s._str);
			delete[] _str;
			_str = pStr;
		}

		return *this;
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};*/
//�ִ���
class String
{
public:
	String(const char* str = "")
	{
		if (str == nullptr)
			str = "";

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s)
		:_str(nullptr)
	{
		String strTemp(s._str);
		swap(_str, strTemp._str);
	}
	String& operator=(String s)
	{
		swap(_str, s._str);
		return *this;
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};
void TestString()
{
	String s1("hello world!!!");
	String s2(s1);
}
int main()
{
	TestString();
	return 0;
}