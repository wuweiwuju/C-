#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//类中共创建了多少个对象?
//计数的变量----不能包含在每个对象中，应该是所有对象共享
//1.使用全局变量--->是可以实现的->缺陷：不安全
//int g_count = 0;
//普通成员变量：   可以再初始化列表中进行初始化       每个对象都包含    必须通过对象访问
//static成员变量： 不可以再初始化列表中进行初始化     只有一份，没有包含在具体的对象中，是所有对象共享的  可以通过对象直接访问/也可以通过类名加作用域直接访问
//class Test
//{
//public:
//	Test()
//		: _b(0)
//	{
//		g_count++;
//	}
//	Test(Test& t)
//	{
//		g_count++;
//	}
//	static int GetCount()
//	{
//		return g_count;
//	}
//	~Test()
//	{
//		g_count--;
//	}
//private:
//	int _b;
////public:
//	//声明
//	static int g_count;//能否定义一个共享的成员变量
//};
//int Test::g_count = 0; //开辟空间
//void TestCount()
//{
//	Test t1, t2;
//	cout << Test::GetCount() << endl;
//}
//int main()
//{
//	cout << Test::GetCount() << endl;
//	Test t1, t2;
//	cout << Test::GetCount() << endl;
//	TestCount();
//	//cout << &t1.g_count << "=" << &t2.g_count << endl;
//	//cout <<Test:: g_count << endl;
//	////有啥区别
//
//
//	//int a = 10;
//	//a = t1.g_count;
//	//a = Test::g_count;
//	//通过反汇编发现  两种没啥区别  只是把第一种转化成第二种方式访问的
//	cout << Test::GetCount() << endl;
//	return 0;
//}
//1.静态成员变量一定要在类外进行初始化
//比普通成员安全
//静态成员函数 和 普通成员函数有啥区别?
//class Test
//{
//public:
//	Test()
//		: _b(0)
//	{
//		g_count++;
//	}
//	Test(Test& t)
//		: _b(0)
//	{
//		g_count++;
//	}
//	//普通成员函数  有一个隐藏的this指针
//	//普通成员变量必须通过this指针访问
//	//可以访问普通成员变量
//	int GetB()
//	{
//		cout << this << endl;
//		return _b;
//	}
//	//静态成员函数  没有this指针
//	//不能访问普通的成员变量
//	static int GetCount()
//	{
//		//cout << this << endl;
//
//		//cout << _b << endl;
//		return g_count;
//	}
//	~Test()
//	{
//		g_count--;
//	}
//private:
//	int _b;
//	//相当于在类中定义一个与对象无关的全局变量--共享的
//	static int g_count;//能否定义一个共享的成员变量
//};
//int Test::g_count = 0; //开辟空间
//void TestCount()
//{
//	Test t1, t2;
//	cout << Test::GetCount() << endl;
//}
//int main()
//{
//	Test t;
//	t.GetB();
//
//	Test::GetCount();//可以不通过对象调用，所以没有this指针
//	return 0;
//}
//静态成员变量保存在数据段
//定义的时候不用加static关键字
//1. 静态成员函数可以调用非静态成员函数吗？
//不可以
//2. 非静态成员函数可以调用类的静态成员函数吗？
//可以
//class Date
//{
//public:
//	//友元函数
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date(int,int,int):" << this << endl;
//	}
//	void PrintDate()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	//void operator<<(ostream& _cout)
//	//{
//	//	cout << _year << "-" << _month << "-" << _day << endl;
//	//}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////条件
////1.两个参数 ： 参数一一定为ostream&,参数二输出的内容
////2.必须有ostream&的返回值，支持连续输出
////3.少做格式化操作：比如换行
////4.将该函数作为类的友元函数
//ostream& operator<<(ostream& _cout,const Date& d)
//{
//	//_cout<<d.GetYear()<<"-"<<d.GetMonth()<<"-"d.GetDay();
//	cout << d._year << "-" << d._month << "-" << d._day;
//	return _cout;
//}
//int main()
//{
//	Date d(2019, 3, 24);
//	d.PrintDate();
//	cout << 10 << endl;//cout<<10   cout<<endl;
//	cout << d << endl;
//	//cout << d;
//	//d.operator<<(cout);
//	//d << cout;
//	return 0;
//}
//https://www.zhihu.com/question/274746738
//1.友元函数的优点：提高代码的效率
//缺点：破坏了封装性
//输入运算符重载
//2.istream&

//友元函数不是类的成员函数，不受访问限定符限制
//友元函数不能用const修饰

//3.友元类
//class Time 
//{
//	friend class Date;
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		:_hour(hour)
//		,_minute(minute)
//		,_second(second)
//	{
//		cout << this->_hour << endl;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date(int,int,int):" << this << endl;
//	}
//	void PrintDate()
//	{
//		cout << _year << "-" << _month << "-" << _day << _t._hour<<endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//int main()
//{
//	return 0;
//}
//友元关系是单向的，不能交换
//友元关系不能传递

//一个类如何防止被拷贝 ?
