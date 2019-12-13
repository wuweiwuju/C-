#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string str1;
	string str2;
	while (cin >> str1 >> str2)
	{
		int count = 0;
		int max = 0;
		if (str1.size() > str2.size())
			swap(str1, str2);
		for (int i = 0; i < str1.size(); i++)
		{
			int flag = i;
			int j = 0;
			int k = 0;
			while(j < str1.size())
			{
				if (str1[i] == str2[j])
				{
					count++;
					i++;
					j++;
					if (count > max)
					{
						max = count;
					}
				}
				else
				{
					j = ++k;
					count = 0;
					i = flag;
				}
				if (j == str2.size() - 1)
				{
					i = flag;
					count = 0;
				}
			}
		}
		cout << max << endl;
	}
	return 0;
}