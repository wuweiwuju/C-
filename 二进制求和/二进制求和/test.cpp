#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
string addBinary(string a, string b)
{
	string c;
	if (a.size() < b.size())
		swap(a, b);
	int j = b.size() - 1;
	char tmp = '0';
	for (int i = a.size() - 1; i >= 0; --i)
	{
		if (j < 0)
		{
			if (a[i] == '1' && tmp == '1')
			{
				c += '0';
				tmp = '1';
			}
			else if(a[i] == '0' && tmp == '0')
			{
				c += '0';
				tmp = '0';
			}
			else
			{
				c += '1';
				tmp = '0';
			}
		}
		else
		{
			if ((a[i] == '1' && b[j] == '1' && tmp == '0')
				|| (a[i] == '1' && b[j] == '0' && tmp == '1')
				|| (a[i] == '0' && b[j] == '1' && tmp == '1'))
			{
				c += '0';
				tmp = '1';
			}
			else if (a[i] == '1' && b[j] == '1' && tmp == '1')
			{
				c += '1';
				tmp = '1';
			}
			else if (a[i] == '0' && b[j] == '0' && tmp == '0')
			{
				c += '0';
				tmp = '0';
			}
			else
			{
				c += '1';
				tmp = '0';
			}
			--j;
		}
	}
	if (tmp == '1')
		c += tmp;
	reverse(c.begin(), c.end());
	return c;
}
int main()
{
	string a;
	string b;
	string c = addBinary("100", "110010");
	
	return 0;
}