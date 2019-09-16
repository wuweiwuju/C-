#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//一个类如何防止被拷贝?
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)//const
		:_year(year)
		,_month(month)
		,_day(day)
	{
		cout << "Date(int,int,int)" <<this<< endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	//const int a = 10;
	Date d1;
	return 0;
}