#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
bool Judge_pnumber(int x)
{
	if (x < 2)
		return false;
	if (x == 2)
		return true;
	for (int i = x - 1; i > 2; i--)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}
int main()
{
	int n = 0;
	while (cin >> n)
	{
		int num1 = n / 2;
		int num2 = n - num1;
		while (1)
		{
			if (Judge_pnumber(num1) && Judge_pnumber(num2))
			{
				cout << num1 << endl;
				cout << num2 << endl;
				break;
			}
			else
			{
				num1++;
				num2--;
			}
		}
	}
	return 0;
}