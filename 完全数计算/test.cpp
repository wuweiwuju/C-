#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int count(int n)
{
	int count = 0;
	int num = 0;
	int sum = 0;
	for (int i = 6; i <= n; i++)
	{
		for (int j = i - 1; j > 1; j--)
		{
			if (i % j == 0)
			{
				num += j;
			}
		}
		if (num + 1 == i)
			count++;
		num = 0;
	}
	if (count == 0)
		return -1;
	return count;
}
int main()
{
	int n = 0;
	while (cin >> n)
	{
		int ret = count(n);
		cout << ret << endl;
	}
	return 0;
}