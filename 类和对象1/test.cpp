#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//#include<string.h>
//class Student
//{
//public:
//	void SetStudentInfo(const char* name, const char* gender, int age)
//	{
//		strcpy(_name, name);
//		strcpy(_gender, gender);
//		_age = age;
//	}
//	void PrintStudentInfo()
//	{
//		cout << _name << " " << _gender << " " << _age << endl;
//	}
//	char _name[20];
/*	char _gender[3];
	int _age;
};
int main()
{
	Student s;
	s.SetStudentInfo("Peper", "男",19);
	s.PrintStudentInfo();
	return 0;
}*/
//1.nullptr 的 类型是 nullptr_t    也就是int*
//2.NULL 类型是  int 
//3.auto是新的类型指示符
//4.offsetof(A,a) 这个是求结构体偏移量
//转到定义看如何模拟实现宏  offsetof
//class Student
//{
//public:
//	void InitStudent(/*Student* const this ,*/ int age)
//	{
//		this->_age = age;
//	}
//	void PrintStudent(/*Student* const this*/)
//	{
//		//this: Student*  const
//		cout <<this-> _age << endl;
//	}
//private:
//	int _name[20];
//	int _age;
//	char _gender[3];
//};
//int main()
//{
//	Student d1;
//	Student::InitStudent(&d1,10);
//	Student::PrintStudent(&d1);
//}
class Date
{
	//里面不受访问限定符的限制
public:
	void Display()
	{
			cout << this->_year << "-" << _month << "-" << _day << endl;
	}
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year; // 年
	int _month; // 月
	int _day; // 日
};
int main()
{
	Date d1, d2;
	d1.SetDate(2018, 5, 1);
	d2.SetDate(2018, 7, 1);
	d1.Display();
	d2.Display();

	Date* p = &d1;
	p->Display();

	Date* ps = nullptr;//
	ps->Display();
	return 0;
}
//5.this 是不能更改的 
//6.this指针存在哪?
//本质存在栈上  因为它也是一个形参   但有时编译器会存在ecx寄存器
//其实编译器在生成程序时加入了获取对象首地址的相关代码。并把获取的首地址存放在了寄存器ECX中(VC++编译器是放在ECX中，其它编译器有可能不同)。也就是成员函数的其它参数正常都是存放在栈中。而this指针参数则是存放在寄存器中。类的静态成员函数因为没有this指针这个参数，所以类的静态成员函数也就无法调用类的非静态成员变量。

//7.this指针可以为空吗？
//可以为空，当我们在调用函数的时候，如果函数内部并不需要使用到this, 也就是不需要通过this指向当前对象并对其进行操作时才可以为空(当我们在其中什么都不放或者在里面随便打印一个字符串)，如果调用的函数需要指向当前对象，并进行操作，则会发生错误（空指针引用）就跟C中一样不能进行空指针的引用
