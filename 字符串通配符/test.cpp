#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str1;
	string str2;
	while (cin >> str1 >> str2)
	{
		int flag = 0;
		for (int i = 0; i < str2.size(); i++)
		{
			if (str2[i] != str1[i])
			{
				if (str1[i] != '?' && str1[i] != '*')
				{
					cout << "false" << endl;
					flag = 1;
					break;
				}
				else if (str1[i] == '*')
				{
					int j = i;
					if (str2[i - 1] == '.')
						break;
					while (str2[i] != '.' && i < str2.size())
					{
						i++;
					}
					if (i == str2.size())
						i = j;
				}
			}
		}
		if (flag == 0)
			cout << "true" << endl;
	}
}