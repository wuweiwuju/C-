#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	int i = 0;
	while (cin >> str)
	{
		char arr[255] = { 0 };
		for (int i = 0; i < str.size(); i++)
		{
			arr[str[i]]++;
		}
		for (i = 0; i < str.size(); i++)
		{
			if (arr[str[i]] == 1)
				break;
		}
		if (i == str.size())
			cout << -1 << endl;
		else
			cout << str[i] << endl;
		str.clear();
	}
	return 0;
}