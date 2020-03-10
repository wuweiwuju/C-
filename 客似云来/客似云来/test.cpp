#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
long long FibNum(int n)
{
	if (n == 1 || n == 2)
		return 1;
	long long firstDay = 1;
	long long secondDay = 1;
	long long sumDay = 0;
	for (int i = 2; i < n; ++i)
	{
		sumDay = firstDay + secondDay;
		firstDay = secondDay;
		secondDay = sumDay;
	}
	return sumDay;
}
int main()
{
	int from = 0;
	int to = 0;
	while (cin >> from >> to)
	{
		long long sum = 0;
		while (from <= to)
		{
			sum += FibNum(from);
			++from;
		}
		cout << sum << endl;
	}
	return 0;
}