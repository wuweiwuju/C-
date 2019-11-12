#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int main()
{
	int a = 0;
	int b = 0;
	cin >> a >> b;
	int max = a;
	int min = b;
	if (b > a)
	{
		max = b;
		min = a;
	}
	for (int i = min; i > 0; i--)
	{
		if (max % i == 0 && min % i == 0)
		{
			int sum = min * (max / i);
			cout << sum << endl;
			break;
		}
	}
	return 0;
}