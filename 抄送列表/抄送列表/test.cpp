#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	while (getline(cin,str))
	{
		string str1;
		string str2;
		getline(cin, str1);
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] == '"')
			{
				++i;
				while (i < str.size() && str[i] != '"')
					str2 += str[i++];

				if (str1 == str2)
				{
					cout << "Ignore" << endl;
					break;
				}
				else
				{
					str2.clear();
				}
			}
			else
			{
				if (str[i] == ',')
					++i;

				if (str[i] == '"')
				{
					--i;
					continue;
				}

				while (i < str.size() && str[i] != ',')
					str2 += str[i++];

				if (str1 == str2)
				{
					cout << "Ignore" << endl;
					break;
				}
				else
				{
					str2.clear();
				}
			}
		}
		if (str1 != str2)
			cout << "Important!" << endl;

		str.clear();
		str2.clear();
	}
	return 0;
}