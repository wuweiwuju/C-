#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	string str1;
	string str2;
	string str;
	while (cin >> str1 >> str2)
	{
		int count = 0;
		int max = 0;
		int k = 0;
		if (str1.size() > str2.size())
			swap(str1, str2);
		for (int i = 0; i < str1.size(); i++)
		{
			int flag = i;
			for (int j = 0; j < str2.size(); j++)
			{
				if (str1[i] == str2[j])
				{
					count++;
					if (count > max)
					{
						max = count;
						str.clear();
						str += str1.substr(flag , count);
					}
					i++;
				}
				else
				{
					count = 0;
					i = flag;
					j = k++;
				}
				if (j == str2.size() - 1)
					i = flag;
			}
		}
		if (str1 == str2)
			cout << str1.size() << endl;
		else
			cout << str.size() << endl;
		str.clear();
	}
}