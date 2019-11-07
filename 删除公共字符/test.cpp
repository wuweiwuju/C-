#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
int main()
{
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	int array[256] = { 0 };
	for (int i = 0; i < s2.size(); i++)
	{
		array[s2[i]] = 1;
	}
	for (int i = 0; i < s1.size(); i++)
	{
		if (array[s1[i]] == 0)
		{
			cout << s1[i];
		}
	}
	cout << endl;
	return 0;
}