#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
using namespace std;
class Date
{
	/*һ��һ����365�����366�죬ƽ����365�죬������366�죬����ÿ��4��һ�Ρ�100�겻��400��һ��
		ƽ���2����28�죬����2����29�졣
		4�¡�6�¡�9�¡�11�¸���30��.��
		1�¡�3�¡�5�¡�7�¡�8�¡�10�¡�12�¸���31�졣*/
public:
	int GetMonthDay(int year, int month);
	void Print();
	//	// ���� ��ֵ ���� / ��Ҫȥ��ϰдһ��
	Date(int year = 2019, int month = 1, int day = 1);
	////�������캯��
	//Date (const Date& s)
	//{
	//	_year = s._year;
	//	_day = s._day;
	//	_month = s._month;
	//}
	////��������
	//~Date()
	//{}

	bool operator<(const Date& d);
	bool operator>(const Date& d);
	bool operator<=(const Date& d);
	bool operator>=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);

	//// d + 100
	Date operator+(int day);//�������������
	Date operator-(int day);

	Date& operator+=(int day);//�������������
	Date& operator-=(int day);

	Date& operator=(const Date& d);
	int operator-(const Date& d);

	//// ++d d.operator++(&d)
	Date operator++();
	//// d++ d.operator++(&d, 0)
	Date operator++(int);

	//// --d d.operator++(&d)
	Date operator--();
	//// d-- d.operator++(&d, 0)
	Date operator--(int);


private:
	int _year;
	int _month;
	int _day;
};
