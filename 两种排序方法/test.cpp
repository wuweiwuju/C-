#define _CRT_SECURE_NO_WARNINGS 3.
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
}