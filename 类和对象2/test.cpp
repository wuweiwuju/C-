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
typedef int DataType;
class SeqList
{
public:
	SeqList(int capacity = 10)
	{
		//初始化
		_pData = (DataType*)malloc(capacity * sizeof(DataType));
		assert(_pData);
		_size = 0;
		_capacity = capacity;
	}
	~SeqList()
	{
		//清理
		if (_pData)
		{
			free(_pData); // 释放堆上的空间
			_pData = nullptr; // 将指针置为空
			_capacity = 0;
			_size = 0;
		}
	}
private:
	int* _pData;
	size_t _size;
	size_t _capacity;
};
int main()
{
	SeqList s1;
	return 0;
}