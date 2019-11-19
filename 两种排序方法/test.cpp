/*#define _CRT_SECURE_NO_WARNINGS 3.
#include<iostream>
#include<stdlib.h>
#include<string>
#include<vector>
#include<stdio.h>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	vector<string> arr;
	arr.resize(n + 1);
	for (int i = 0; i <= n; i++)
	{
		getline(cin, arr[i]);
	}
	int i = 1;
	while (i < arr.size() && arr[i].size() < arr[i + 1].size()
		&& arr[i].compare(arr[i + 1]) < 0)
	{
		i++;
		if (i == arr.size() - 1)
		{
			cout << "both" << endl;
			return 0;
		}
	}
	i = 1;
	while (i < arr.size() && arr[i].size() < arr[i + 1].size())
	{
		i++;
		if (i == arr.size() - 1)
		{
			cout << "lengths" << endl;
			return 0;
		}
	}
	i = 1;
	while (i < arr.size() && arr[i].compare(arr[i + 1]) < 0)
	{
		i++;
		if (i == arr.size() - 1)
		{
			cout << "lexicographically" << endl;
			return 0;
		}
	}
	cout << "none" << endl;
	return 0;
}*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	vector<string> str;
	str.resize(n);
	bool lexsym = true;
	bool lensym = true;
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		if (str[i].size() >= str[i + 1].size())
		{
			lensym = false;
			break;
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		if (str[i] > str[i + 1])
		{
			lexsym = false;
			break;
		}
	}
	if (lensym && lexsym)
		cout << "both" << endl;
	else if (lensym)
		cout << "lengths" << endl;
	else if (lexsym)
		cout << "lexicographically" << endl;
	else
		cout << "none" << endl;
	return 0;
}