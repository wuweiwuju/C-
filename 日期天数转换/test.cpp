#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Date
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	static int iConverDateToDay(int year, int month, int day)
	{
		/* 在这里实现功能，将结果填入输入数组中*/
		//1 3 5 7 8 10 12
		int Month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if ((year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0)))
		{
			Month[2] = 29;
		}
		if ((year < 0) || (month > 12 || month < 0) || (day<0 || day>Month[month]))
			return -1;
		for (int i = 1; i < month; i++)
		{
			sum = sum + Month[i];
		}
		sum = sum + day;
		return 0;
	}
	static int getOutDay(int year, int month, int day)
	{
		sum = 0;
		if (iConverDateToDay(year, month, day) == -1)
			return -1;
		return sum;
	}
private:
	int _year;
	int _month;
	int _day;
	static int sum;
};
int Date::sum = 0;
int main()
{
	int year = 0, month = 0, day = 0;
	while (cin >> year >> month >> day)
	{
		cout<<Date::getOutDay(year, month, day);
	}
	return 0;
}