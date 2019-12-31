#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	while (getline(cin, str))
	{
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] >= 'F' && str[i] <= 'Z')
				str[i] = str[i] - 5;
			else if (str[i] >= 'A' && str[i] <= 'E')
				str[i] = str[i] + 21;
		}
		cout << str << endl;
		str.clear();
	}
	return 0;
}