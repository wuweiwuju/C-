#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool isBrother(string str1, string str2)
{
	if (str1.size() == str2.size())
	{
		if (str1 == str2)
			return false;

		sort(str1.begin(), str1.end());
		sort(str2.begin(), str2.end());
		if (str1 == str2)
			return true;
	}

	return false;
}
int main()
{
	int n = 0;
	while (cin >> n)
	{
		vector<string> arr(n);
		string str;
		string temp;
		int count = 0;
		int k = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		cin >> str >> k;
		sort(arr.begin(), arr.end());
		for (int i = 0; i < n; ++i)
		{
			if (isBrother(arr[i], str))
			{
				++count;
				if (count == k)
					temp = arr[i];
			}
		}
		if (!arr.empty())
			cout << count << endl;
		if (!temp.empty())
			cout << temp << endl;
	}
	return 0;
}