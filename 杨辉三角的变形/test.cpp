#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
bool is_odd(int x)
{
	for (int i = 3; i <= x; i+=2)
	{
		if ( i == x)
			return true;
	}
	return false;
}
int main()
{
	int n = 0;
	while (cin >> n)
	{
		if (n <= 2)
			cout << -1 << endl;
		else if (is_odd(n))
			cout << 2 << endl;
		else if (n % 4 == 0)
			cout << 3 << endl;
		else
			cout << 4 << endl;
	}
	return 0;
}