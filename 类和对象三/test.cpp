#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//1.operator++()  ǰ��++
//operator++(int) ����++
//{
//	Date temp(*this);
//	_day += 1;
//	return temp; 
//}
//2.��ֵ�����������
//���������  ���������ǲ�һ����
//��������أ�����ֵ���� operator+�������б�
//Date& operator=(const Date&d)
//{
//	if (this != &d)
//	{
//		//��ֵ����
//	}
//	return *this;
//}
//3.&��const&
//�����޸ĵ�ǰ����ĳ�Ա����
//const ����thisָ��//Date* const this(this ָ���ģʽ)
//void Display()const//����thisָ��
//mutable �ؼ���
//mutable int _day  ������const������ǿ����޸ĵ�
//4.const���󲻿��Ե��÷�const��Ա����
//5.��const������Ե���const����
//6.const��Ա�����ڿ��Ե��������ķ�const��Ա������?������
//7.��const��Ա�����ڿ��Ե���������const��Ա����
//8.const Date* operator&()const
//{
//	return this;
//}
//****************************************//
//1.��̸���캯��
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
	//��ʼ���б�   ֻ���ڹ��캯����   ��������Ҳ��
	//1.��ʼ���б��Ա�ĳ��ִ��򣬲������������ĳ�ʼ������
	//2.��Ա�����ڳ�ʼ���б��еĳ�ʼ������Ϊ�������е���������
	//���飺��ò�Ҫʹ�ó�Ա��ʼ����Ա
	//�����ڳ�ʼ���б��н��г�ʼ�����ǣ�
	//���ó�Ա����
	//const��Ա����
	//�����ͳ�Ա����(����û��Ĭ�Ϲ��캯��)
	Date(int year = 1999, int month = 1, int day = 1)
		//������ǳ�ʼ��  ��ʼ��ֻ�ܳ�ʼ��һ��
		//���ﲻ������thisָ�룬��Ϊ�����ﻹû�й���ɹ�
		: _year(year)
		,_month(month)
		,_day(day)
		//,_t() //�����޲ε�Ĭ�Ϲ��캯��  ���ǲ��е�
		,_t(0,0,0)
	{
		//���캯�����Ǹ���ֵ���ǳ�ʼ��
		//_year = year;
		//_month = month;
		//_day = day;
		//a = _day;
	}
private:
	int _year;
	int _month;
	int _day;
	//int& a;���治�ǳ�ʼ��
	Time _t;//
};
int main()
{
	Date(2019, 3, 24);
	return 0;
}
//�ڹ��캯������֮ǰ�������ǲ����ڵ�  
//�ڱ����������ڼ䣬�Ѿ�Ϊmain�������ջ�ռ�
//�ÿռ��Ѿ������˺�����ľֲ�����  �������ڼ䲻����뺯���ڲ�Ҳ���ǲ������У�
#endif
//explicit �ؼ���
//���Խ�ֹ���캯��������ת��
//��Ϊ�����ɶ��Բ����Բ�����ֹ��
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
	//d = 2020;//2020->ͨ�����ι��캯��->��ʱ����
	//���캯�� ���ڵ��������Ĺ��캯������������ת��������
	return 0;
}
//ʲô����£��������Ż�Ĭ������?
//����������о��Լ���Ҫ��ʱ��ͻ�����->ʲô���Ǳ�������Ҫ��ʱ��
//�ĸ�������
//class Time
//{
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//
//	{
//
//	}
//	Time(Time&)
//	{
//
//	}
//	Time& operator=(Time& a)
//	{
//		return *this;
//	}
//	~Time()
//	{
//
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//public:
//	//Date()
//	//{
//
//	//}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//int main()
//{
//	Date d1;//������Ĺ��캯��
//	Date d2(d1);//Time(Time&)->�Ҹ�����λ��->Date��Ŀ������캯����
//	Date d3;
//	d3 = d1;
//
//
//	return 0;
//}
//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//class Date
//{
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//��ע�⡿
//1. ÿ����Ա�����ڳ�ʼ���б���ֻ�ܳ���һ��(��ʼ��ֻ�ܳ�ʼ��һ��)
//2. ���а������³�Ա��������ڳ�ʼ���б�λ�ý��г�ʼ����
//���ó�Ա����
//const��Ա����
//�����ͳ�Ա(����û��Ĭ�Ϲ��캯��)
//class A {
//public: A(int a)
//	:_a(a)
//{}
//private:
//	int _a;
//};
//class B {
//public: B(int a, int ref)
//	:_aobj(a)
//	, _ref(ref)
//	, _n(10)
//{}
//private: A _aobj; // û��Ĭ�Ϲ��캯��
//		 int& _ref; // ����
//		 const int _n; // const 
//};
//3. ����ʹ�ó�ʼ���б��ʼ������Ϊ�������Ƿ�ʹ�ó�ʼ���б������Զ������ͳ�Ա������һ������ʹ
//�ó�ʼ���б��ʼ����
//class Time
//{
//public:
//	Time(int hour = 0)
//		:_hour(hour)
//	{
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//};
//class Date
//{
//public:
//	Date(int day)
//	{}
//private:
//	int _day;
//	Time _t;
//};
//int main()
//{
//	Date d(1);
//}
//4. ��Ա������������������������ڳ�ʼ���б��еĳ�ʼ��˳�������ڳ�ʼ���б��е��Ⱥ�����޹�
//class Array
//{
//public:
//	Array(int size)
//		:_size(size)
//		, _array((int*)malloc(sizeof(int)* _size))
//	{}
//private:
//	int* _array;
//	int _size;
//};