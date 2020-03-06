#include<iostream>
using namespace std;
long long numRib(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	long long one = 1;
	long long two = 2;
	long long count = 0;
	n = n - 2;
	while (n--)
	{
		count = one + two;
		one = two;
		two = count;
	}

	return count;
}
int main()
{
	int n = 0;
	while (cin >> n)
	{
		long long  ret = numRib(n);
		cout << ret << endl;
	}
	return 0;
}