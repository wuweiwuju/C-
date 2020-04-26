// write your code here cpp
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	while (cin >> str)
	{
		string arr;
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] != '_')
			{
				arr.push_back(str[i]);
			}
			else
			{
				str[i + 1] = str[i + 1] - 32;
			}
		}
		cout << arr << endl;
		arr.clear();
	}
	return 0;
}