#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//����
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
//		//ǳ����
//		string(const string& s)
//			:_str(s._str)
//		{
//
//		}
//		//ǳ����
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
//ǳ������ֵ�Ŀ���
//�����


//���---��ͳ��
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
//		//���
//		string(const string& s)
//			:_str(new char[strlen(s._str)+1])
//		{
//			strcpy(_str, s._str);
//		}
//		//���
//		string& operator=(const string& s)
//		{
//			if (this != &s)
//			{
//				/*
//				delete[] _str;
//				_str = new char[strlen(s._str) + 1];
//				strcpy(_str, s._str);
//				*/
//				//����Ե�ǰ�������Ӱ��
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

//���---�ִ���
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
//			:_str(nullptr)//��ֹ����
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
//���ü��� 
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
//	//lpf::string s3("world");//��̬Ҳ����
//	//s2 = s1;
//}
//int main()
//{
//
//}
namespace lpf
{
	class string
	{
	public:
		string(const char* str = "")
		{
			if (nullptr == str)
			{
				str = "";
			}
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
			_pCount = new int(1);
		}
		string(const string& s)
			:_str(s._str)
			,_pCount(s._pCount)
		{
			++(*_pCount);
		}
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				Release();

				_str = s._str;
				_pCount = s._pCount;
				++(*_pCount);
			}
		}

		char& operator[](size_t index)
		{
			return _str[index];
		}

		const char& operator[](size_t index)const
		{
			return _str[index];
		}

		~string()
		{
			Release();
		}
	private:
		void Release()
		{
			if (_str && 0 == --(*_pCount))
			{
				delete[] _str;
				delete _pCount;
				_str = nullptr;
				_pCount = nullptr;
			}
		}
	private:
		char* _str;
		int* _pCount;
	};
}
void TestString()
{
	lpf::string s1("hello");
	lpf::string s2(s1);
	lpf::string s3("world");
	lpf::string s4(s3);

	s1 = s3;//s1 s3 s4����һ�ݿռ�  s2����һ��

	s2 = s4;//s1 s2 s3 s4����ͬһ��
}
int main()
{
	TestString();
	return 0;
}