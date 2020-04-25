#define _CRT_SECURE_NO_WARNINGS 1
// write your code here cpp
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	string t;
	while (cin >> s)
	{
		cin >> t;
		int count = 0;
		int start = 0;
		int j = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			start = i;
			for (j = 0; j < t.size(); ++j)
			{
				if (s[i] == t[j])
					++i;
				else
					break;
			}
			if (j == t.size())
			{
				++count;
				i = i - 1;
			}
			else
				i = start;
		}
		cout << count << endl;
	}
	return 0;
}