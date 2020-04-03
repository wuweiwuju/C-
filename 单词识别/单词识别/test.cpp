#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
int main()
{
	map<string, int> countMap;
	string str1;
	getline(cin,str1);
	vector<string> arr;
	string str2;
	int flag = 0;
	for (int i = 0; i < str1.size(); ++i)
	{
		if (str1[i] != ' ' && str1[i] != ',' && str1[i] != '.')
		{
			if (str1[i] >= 'A' && str1[i] <= 'Z')
				str1[i] += 32;

			str2 += str1[i];
			flag = 1;
		}
		else
		{
			if (flag == 1)
			{
				arr.push_back(str2);
				str2.clear();
			}
			flag = 0;
		}
	}

	for (auto& e : arr)
	{
		countMap[e]++;
	}

	for (auto& e : countMap)
	{
		cout << e.first << ":" << e.second << endl;
	}

	return 0;
}