#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	string str1;
	while (getline(cin, str))
	{
		int count = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '"')
			{
				i++;
				while (str[i] != '"')
					i++;
			}
			else if (str[i] == ' ')
				count++;
		}
		cout << count + 1 << endl;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '"')
			{
				i++;
				while (str[i] != '"')
				{
					str1 += str[i];
					i++;
				}
			}
			else
			{
				while (str[i] != ' ' && i < str.size())
				{
					str1 += str[i];
					i++;
				}
			}
			cout << str1 << endl;
			str1.clear();
		}
	}
	return 0;
}