#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
using namespace std;


/*int main()
{
	string str;

	while (cin >> str)
	{
		int len = str.size();
		for (int i = 0; i < len; i++)
		{
			char ch = str[i];
			if (ch != ' ') //略过已经标记的元素
			{
				for (int j = i + 1; j < len; j++) //内层循环用于寻找相同元素
				{
					if (ch == str[j])
					{
						str[j] = ' '; //标记相同元素
					}
				}
			}
		}

		//打印
		for (int i = 0; i < len; i++)
		{
			if (str[i] != ' ')
			{
				cout << str[i];
			}
		}
		cout << endl;
	}


	return 0;
}*/


