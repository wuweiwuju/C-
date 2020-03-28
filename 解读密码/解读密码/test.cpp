#define _CRT_SECURE_NO_WARNINGS 1
// write your code here cpp
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		string A;
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] >= '0' && str[i] <= '9')
				A += str[i];
		}
		cout << A << endl;
	}
	return 0;
}