#include<math.h>
#include<iostream>
#include<vector>
using namespace std;
bool is_prime(int n)
{
	if (n == 2 || n == 3)
		return true;
	int x = n;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}
bool is_one(int i)
{
	if (i % 10 == 1)
		return true;
	return false;
}
int main()
{
	int n = 0;
	vector<int> str;
	while (cin >> n)
	{
		int flag = 0;
		for (int i = 11; i < n; i++)
		{
			if (is_prime(i) && is_one(i))
			{
				str.push_back(i);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			cout << -1 << endl;
		}
		else
		{
			for (int i = 0; i < str.size() - 1; i++)
			{
				cout << str[i] << " ";
			}
			cout << str[str.size() - 1] << endl;
		}
		str.clear();
	}
	return 0;
}