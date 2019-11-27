#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	string s, table{ '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','I' };
	int m, n;
	cin >> m >> n;
	bool flag = false;
	if (m < 0)
	{
		m = -m;
		flag = true;
	}
	while (m)
	{
		s += table[m % n];
		m /= n;
	}
	if (flag)
	{
		s += '-';
	}
	reverse(s.begin(), s.end());
	cout << s << endl;
	return 0;
}