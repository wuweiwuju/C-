#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//һ������η�ֹ������?
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)//const
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{
//		cout << "Date(int,int,int)" <<this<< endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	//const int a = 10;
//	Date d1;
//	return 0;
//}


//�ڲ������ⲿ�����Ԫ��
class Solution
{
	class Sum
	{
	public:
		Sum()
		{
			++count;
			sum += count;
		}
		static void ReSet()
		{
			count = 0;
			sum = 0;
		}
		void TestFunc()
		{
			Solution s;
			s._a = 10;
		}
		static int GetSum()
		{
			return sum;
		}
	private:
		static int count;
		static int sum;
	};
public:
	int Sum_Solution(int n)
	{
		Solution::Sum::ReSet();
		return Solution::Sum::GetSum();
	}

private:
	int _a;
};
int Solution::Sum::count = 0;
int Solution::Sum::sum = 0;
int main()
{
	return 0;
}
//sizeof(�ⲿ��)  �������ڲ���Ĵ�С
//��װ  
//C++�ǻ�����������