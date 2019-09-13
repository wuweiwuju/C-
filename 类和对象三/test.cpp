#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//1.operator++()  前置++
//operator++(int) 后置++
//{
//	Date temp(*this);
//	_day += 1;
//	return temp; 
//}
//2.赋值运算符的重载
//运算符重载  函数重载是不一样的
//运算符重载：返回值类型 operator+（参数列表）
//Date& operator=(const Date&d)
//{
//	if (this != &d)
//	{
//		//赋值操作
//	}
//	return *this;
//}
//3.&和const&
//不能修改当前对象的成员变量
//const 修饰this指针//Date* const this(this 指针的模式)
//void Display()const//限制this指针
//mutable 关键字
//mutable int _day  这样在const里面就是可以修改的
//4.const对象不可以调用非const成员函数
//5.非const对象可以调用const对象
//6.const成员函数内可以调用其它的非const成员函数吗?不可以
//7.非const成员函数内可以调用其它的const成员函数
//8.const Date* operator&()const
//{
//	return this;
//}
//****************************************//
//1.再谈构造函数
#if 0
class Time
{
public:
	Time(int hour, int minute, int second)
		: _hour(hour)
		, _minute(minute)
		, _second(second)

	{

	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	//初始化列表   只存在构造函数中   拷贝构造也有
	//1.初始化列表成员的出现次序，不代表其真正的初始化次序
	//2.成员变量在初始化列表中的初始化次序为其在类中的声明次序
	//建议：最好不要使用成员初始化成员
	//必须在初始化列表中进行初始化的是：
	//引用成员变量
	//const成员变量
	//类类型成员变量(该类没有默认构造函数)
	Date(int year = 1999, int month = 1, int day = 1)
		//这里才是初始化  初始化只能初始化一次
		//这里不可以用this指针，因为在这里还没有构造成功
		: _year(year)
		,_month(month)
		,_day(day)
		//,_t() //调用无参的默认构造函数  这是不行的
		,_t(0,0,0)
	{
		//构造函数中是赋初值不是初始化
		//_year = year;
		//_month = month;
		//_day = day;
		//a = _day;
	}
private:
	int _year;
	int _month;
	int _day;
	//int& a;里面不是初始化
	Time _t;//
};
int main()
{
	Date(2019, 3, 24);
	return 0;
}
//在构造函数调用之前，对象是不存在的  
//在编译器编译期间，已经为main分配好了栈空间
//该空间已经包含了函数体的局部变量  （编译期间不会进入函数内部也就是不会运行）
#endif
//explicit 关键字
//可以禁止构造函数的类型转换
//因为那样可读性差所以不妨禁止掉
#if 0
class Date
{
public:
	explicit Date(int year = 1999)
		: _year(year)
	{
	}
	Date& operator=(const Date& d)
	{

	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d(2019);
	//d = 2020;//2020->通过单参构造函数->临时对象
	//构造函数 对于单个参数的构造函数，还有类型转换的作用
	return 0;
}
#endif
//什么情况下，编译器才会默认生成?
//如果编译器感觉自己需要的时候就会生成->什么才是编译器需要的时候？
//四个场景：
class Time
{
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		: _hour(hour)
		, _minute(minute)
		, _second(second)

	{

	}
	Time(Time&)
	{

	}
	Time& operator=(Time& a)
	{
		return *this;
	}
	~Time()
	{

	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	//Date()
	//{

	//}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};
int main()
{
	Date d1;//日期类的构造函数
	Date d2(d1);//Time(Time&)->找个调用位置->Date类的拷贝构造函数中
	Date d3;
	d3 = d1;


	return 0;
}
 