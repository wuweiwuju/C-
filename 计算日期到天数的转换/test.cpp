#include<iostream>
using namespace std;
class Date
{
public:
	//1 3 5 7 8 10 12每月31天 2月是闰年29天，否则28天， 一年闰年366 否则355天
	int iConverDateToDay(int year, int month, int day)
	{
		int arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		int sum = 0;
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		{
			arr[1] = 29;
		}
		if (month <= 12 && month > 0)
		{
			if (day <= arr[month - 1] && day > 0)
			{
				for(int i = 0;i < month - 1;i++)
				{
					sum += arr[i];
				}
				return sum + day;
			}
			else
				return -1;
		}
		else
			return -1;
	}
};
int main()
{
	int year = 0;
	int month = 0;
	int day = 0;
	cin >> year >> month >> day;
	Date d;
	int ret = d.iConverDateToDay(year, month, day);
	cout << ret << endl;
	return 0;
}