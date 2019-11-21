#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int main()
{
	int n, m, i, j;
	cin >> n >> m >> j >> i;
	int count = 0;
	int max = n;
	int min = m;
	int k = i - j + 1;
	int y = i - j;
	int l = j;
	while (j--)
	{
		n = n / 2;
	}
	while (k--)
	{
		if (n % 2 != 0)
			return 0;
	}
	int x = 0;
	for (int a = 0; a < 32; a++)
	{
		count = m % 2;
		if (count == 1)
			x = a;
		m = m / 2;
	}
	if (x != y)
		return 0;
	m = min << l;
	n = max;
	cout << n + m << endl;
	return 0;
}