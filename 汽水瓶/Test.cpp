#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int drinkWater(int num)
{
	if (num < 2)
		return 0;
	int sum = 0;
	int count = 0;
	while (num)
	{
		count = num % 3;
		num = num / 3;
		if (num == 0)
			break;
		sum += num;
		count = num + count;
		num = count;
	}
	if (count == 2)
		sum += 1;
	return sum;
}
int main()
{
	int n = 0;
	while (cin >> n)
	{
		int ret = drinkWater(n);
		cout << ret << endl;
	}
	return 0;
}