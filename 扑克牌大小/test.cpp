#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	string str;
	vector<string> arr1;
	vector<string> arr2;
	arr1.resize(5);
	arr2.resize(5);
	int x = 0;
	int y = 0;
	while (getline(cin, str))
	{
		int j = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != ' ' && str[i] != '-')
			{
				while (str[j] != ' ' && str[j] != '-')
				{
					arr1[i] += str[j];
					j++;
					x = i;
				}
			}
			if (str[i] == '-')
			{
				y = i;
				break;
			}
		}
		j = y;
		for (int i = y; i < str.size(); i++)
		{
			if (str[i] != ' ' && str[i] != '-')
			{
				while (str[j] != ' ' && str[j] != '-')
				{
					arr2[i] += str[j];
					j++;
				}
			}
			if (str[i] == '-')
			{
				y = i;
				break;
			}
		}
		arr1.resize(x);
		arr2.resize(x);
		if (arr1[0] == "joker" && arr1[1] == "JOKER")
		{
			cout << "joker JOKER" << endl;
		}
		else if (arr1[0] > arr2[0])
		{

		}
	}
}