#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	while (cin >> s)
	{
		int count = 0;
		int sum = 0;
		if (s.size() <= 4)
			count = 5;
		else if (s.size() > 4 && s.size() < 8)
			count = 10;
		else
			count = 25;
		int a = 0;
		int b = 0;
		int c = 0;
		int d = 0;
		int e = 0;
		int f = 0;
		int j = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
				a++;
			if (s[i] >= 'A' && s[i] <= 'Z')
				b++;
			if (s[i] >= 'a' && s[i] <= 'z')
				c++;
			if (s[i] >= '!' && s[i] <= '/')
				d++;
			if (s[i] >= ':' && s[i] <= '@')
				e++;
			if (s[i] >= '[' && s[i] <= '`')
				f++;
			if (s[i] >= '{' && s[i] <= '~')
				j++;
		}
		int k = d + e + f + j;
		if (a == 1)
			count += 10;
		else if (a > 1)
			count += 20;
		if (k == 1)
			count += 10;
		else if (k > 1)
			count += 25;
		if ((b == 0 && c == s.size()) || (c == 0 && b == s.size()))
			count += 10;
		else if (b > 0 && c > 0)
			count += 20;
		sum = count;
		if ((b > 0 || c > 0) && a > 0)
			sum = sum + 2;
		if ((b > 0 || c > 0) && a > 0 && k > 0)
			sum = sum + 3 - 2;
		if (b > 0 && c > 0 && a > 0 && k > 0)
			sum = sum + 5 - 3;
		if (sum >= 90)
			cout << "VERY_SECURE" << endl;
		else if (sum >= 80)
			cout << "SECURE" << endl;
		else if (sum >= 70)
			cout << "VERY_STRONG" << endl;
		else if (sum >= 60)
			cout << "STRONG" << endl;
		else if (sum >= 50)
			cout << "AVERAGE" << endl;
		else if (sum >= 25)
			cout << "WEAK" << endl;
		else
			cout << "VERY_WEAK" << endl;
	}
	return 0;
}