#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;
//1.类的6个默认函数
//2.构造函数 完成对象的初始化
//函数名于类名相同
//可以重载
//自动调用
//无返回值
//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time()" << endl;
//		_hour = _minute = _second = 0;
//	}
//private:
//	int  _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//public:
//	//void Init(int year, int month, int day)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//	void Display()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	//有歧义   下面这两个不能同时存在
//	//Date()//第一个
//	//{
//	//	cout << "cout" << endl;
//	//	_year = 2018;
//	//	_month = 1;
//	//	_day = 1;
//	//}
//	//Date(int year,int month,int day)//第二个  最常用的方式
//	//{
//	//	_day = day;
//	//	_month = month;
//	//	_year = year;
//	//}
//private:
//	//1.基本类型/内置类型   不会初始化
//	int _year;
//	int _month;
//	int _day;
//
//	//2.自定义类型  默认构造函数会初始化  
//	Time _t;
//};
//int main()
//{
//	Date d1;
//	//d1.Init(2018, 5, 1);
//	d1.Display();
//
//
//	//d2.Init(2018, 7, 1);
//	//Date d2(2018, 6, 6);
//	//d2.Display();
//	return 0;
//}
//3.无参的构造函数  / 全缺省的构造函数 / 没写的默认构造函数 都可以认为是默认构造函数  但是 默认构造函数只能有一个
//4.析构函数   类的一些资源清理工作   
//无参数 无返回值
//自动生成
//有且只有一个
//类名前加字符 ~
//5.先构造的后析构
//typedef int DataType;
//class SeqList
//{
//public:
//	SeqList(int capacity = 10)
//	{
//		//初始化
//		_pData = (DataType*)malloc(capacity * sizeof(DataType));
//		assert(_pData);
//		_size = 0;
//		_capacity = capacity;
//	}
//	~SeqList()
//	{
//		//清理
//		if (_pData)
//		{
//			free(_pData); // 释放堆上的空间
//			_pData = nullptr; // 将指针置为空
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	int* _pData;
//	size_t _size;
//	size_t _capacity;
//};
//int main()
//{
//	SeqList s1;
//	return 0;
//}
//6.拷贝构造函数
//参数只有一个
//是构造函数的重载形式
//默认的拷贝我们称为值拷贝或者浅拷贝
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	} 
//	Date(const Date& d)//必须引用传参  const  是防止拷贝构造的同时修改了原内容
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2018,9,10);
//	d1.Print();
//
//	Date d2(d1);//拷贝构造
//	d2.Print();
//
//	return 0;
//}
//深拷贝才可以解决这个程序会崩溃的问题，之后在学习
//class String
//{
//public:
//	String(const char* str = "jack")
//	{
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//	~String()
//	{
//		cout << "~String()" << endl;
//		free(_str);
//	}
//private:
//	char* _str;
//};
//int main()
//{
//	String s1("hello");
//	String s2(s1);//不能释放两次
//}
//7.运算符的重载
// 全局的operator==
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	bool operator==(const Date& d) //有个隐含的this指针 指向的是第一个d1   d2传给的是d
//	{
//		return (_year == d._year)
//			&& (_month == d._month)
//			&& (_day == d._day);
//	}
//	Date& operator=(const Date& d)//
//	{
//		if (this != &d)//防止自己给自己赋值
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;//出了作用域还在用引用返回
//	}
//	/*bool operator<(const Date& d1, const Date& d2) {
//		return (d1._year < d2._year)
//			|| (d1._year == d2._year && d1._month < d2._month)
//			|| (d1._year == d2._year && d1._month == d2._month && d1._day < d2._day);
//	}*/
//private:
//	int _year;
//	int _month;
//	int _day;
//};
// 这里会发现运算符重载成全局的就需要成员变量是共有的，那么问题来了，封装性如何保证？
// 这里其实可以用我们后面学习的友元解决，或者干脆重载成成员函数。
//bool operator==(const Date& d1, const Date& d2) {
//	return (d1._year == d2._year)
//	&& (d1._month == d2._month)
//		&& (d1._day == d2._day);
//}
//bool operator<(const Date& d1, const Date& d2) {
//	return (d1._year < d2._year)
//		|| (d1._year == d2._year && d1._month < d2._month)
//		|| (d1._year == d2._year && d1._month == d2._month && d1._day < d2._day);
//}
//int main()
//{
//	Date d1(2018, 9, 26);
//	Date d2(2018, 9, 27);
//	cout << (d1 == d2) << endl;
//	d1 = d2;
//	cout << (d1 == d2) << endl;
//	//cout << (d1 < d2) << endl;
//}
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	// bool operator==(Date* this, const Date& d2)
//	// 这里需要注意的是，左操作数是this指向的调用函数的对象
//	bool operator==(const Date& d2)
//	{
//		return _year == d2._year
//			&& _month == d2._month
//			&& _day == d2._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void Test()
//{
//	Date d1(2018, 9, 26);
//	Date d2(2018, 9, 27);
//	cout << (d1 == d2) << endl;
//}