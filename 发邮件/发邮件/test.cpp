#include<iostream>
using namespace std;
long long mirNum(long long n)
{
	if (n == 0 || n == 1)
		return 0;
	if (n == 2)
		return 1;
	if (n == 3)
		return 2;
	return (n - 1)*(mirNum(n - 1) + mirNum(n - 2));
}
int main()
{
	int n = 0;
	while (cin >> n)
	{
		cout << mirNum(n) << endl;
	}
	return 0;
}