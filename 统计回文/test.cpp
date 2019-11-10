#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string s1;
	string s2;
	string s3;
	string s4;
	getline(cin, s1);
	getline(cin, s2);
	s1.reserve(100);
	s2.reserve(100);
	s3.reserve(100);
	s4.reserve(100);
	int count = 0;
	int sum = s1.size() + 1;
	int j = 0;
	while (sum--)
	{
		for (int i = j; i <= s1.size(); i++)
		{
			s4 = s1;
			s1.insert(i, s2);
			s3 = s1;
			reverse(s1.begin(), s1.end());
			if (s3 == s1)
			{
				count++;
			}
			s1 = s4;
			j++;
			break;
		}
	}
	cout << count << endl;
	return 0;
}