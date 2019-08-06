#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
using namespace std;
class Date
{
	/*一年一共有365天或者366天，平年有365天，闰年有366天，闰年每隔4年一次。100年不闰，400年一闰
		平年的2月是28天，闰年2月是29天。
		4月、6月、9月、11月各是30天.。
		1月、3月、5月、7月、8月、10月、12月各是31天。*/
public:
	int GetMonthDay(int year, int month)
	{
		static int monthDays[13] = { 0, 31, 28, 31, 30 ,31 ,30 ,31 ,31 ,30 ,31 ,30 ,31 };
		if ((month == 2) && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}
		else
		{
			return monthDays[month];
		}
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
		// 拷贝 赋值 析构 / 都要去练习写一下
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;

	}
	//拷贝构造函数
	Date (const Date& s)
	{
		_year = s._year;
		_day = s._day;
		_month = s._month;
	}
	//析构函数
	~Date()
	{}

		bool operator<(const Date& d)
		{
			if (_year < d._year)
				return true;
			if (_year > d._year)
				return false;
			if (_year = d._year)
			{
				if (_month < d._month)
					return true;
				if (_month > d._month)
					return false;
				if (_month = d._month)
				{
					if (_day < d._day)
						return true;
					else
						return false;
				}
			}
		}
		bool operator>(const Date& d)
		{
			if (_year > d._year)
				return true;
			if (_year < d._year)
				return false;
			if (_year = d._year)
			{
				if (_month > d._month)
					return true;
				if (_month < d._month)
					return false;
				if (_month = d._month)
				{
					if (_day > d._day)
						return true;
					else
						return false;
				}
			}
		}
		bool operator<=(const Date& d)
		{
			if (_year > d._year)
				return false;
			if (_year <= d._year)
			{
				if (_month > d._month)
					return false;
				if (_month <= d._month)
				{
					if (_day > d._day)
						return false;
					else
						return true;
				}
			}
		}
		bool operator>=(const Date& d) 
		{
			if (_year < d._year)
				return false;
			if (_year >= d._year)
			{
				if (_month < d._month)
					return false;
				if (_month >= d._month)
				{
					if (_day < d._day)
						return false;
					else
						return true;
				}
			}
		}
		bool operator==(const Date& d) 
		{
			return _year == d._year &&
				_day == d._day &&
				_month == d._month;
		}
		bool operator!=(const Date& d)
		{
			return _year != d._year ||
				_day != d._day ||
				_month != d._month;
		}

		// d + 100
		Date operator+(int day)
		{
			
		}
		Date operator-(int day)
		{

		}
		Date operator+=(int day)
		{

		}
		Date operator-=(int day)
		{

		}
		int operator-(const Date& d)
		{

		}

		// ++d d.operator++(&d)
		Date operator++()
		{

		}
		// d++ d.operator++(&d, 0)
		Date operator++(int)
		{

		}
	private:
		int _year;
		int _month;
		int _day;
};
