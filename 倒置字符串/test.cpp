#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	if (s.size() == 0)
		return 0;
	int count = 1;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
			count++;
	}
	int j = s.size() - 1;
	while (count--)
	{
		for (int i = j; i >= 0; i--)
		{
			if (s[i] == ' ')
			{
				cout << s.substr(i + 1, j - i) << ' ';
				j = i - 1;
				break;
			}
		}
	}
	cout << s.substr(0, j + 1);
	return 0;
}
/*#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1;
	string s2;
	cin >> s2;
	while (cin >> s1)
		s2 = s1 + ' ' + s2;
	cout << s2;
	return 0;
}*/