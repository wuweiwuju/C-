#define _CRT_SECURE_NO_WARNINGS 1
/*#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	s.reserve(255);
	int count = 0;
	int sum = 0;
	int end = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			count++;
			if (sum < count)
			{
				sum = count;
				end = i;
			}
		}
		else
		{
			count = 0;
		}
	}
	cout << s.substr(end - sum + 1, sum) << endl;
	return 0;
}*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string s;
	vector<string> t;
	while (cin >> s)
	{
		s.reserve(255);
		int count = 0;
		int sum = 0;
		int end = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				count++;
				if (sum < count)
				{
					sum = count;
					end = i;
				}
			}
			else
			{
				count = 0;
			}
		}
		t.push_back(s.substr(end - sum + 1, sum));
		int x = 0;
		for (int i = end + 1; i < s.size(); i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				x++;
				if (x == sum)
				{
					t.push_back(s.substr(i - sum + 1, sum));
				}
			}
			else
			{
				x = 0;
			}
		}
		for (int i = 0; i < t.size(); i++)
		{
			cout << t[i];
		}
		cout << ',' << sum << endl;
		t.clear();

	}
	return 0;
}