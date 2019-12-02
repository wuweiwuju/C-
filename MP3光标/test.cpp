#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n = 0;
	string str;
	while (cin >> n >> str)
	{
		int bottle = 1;
		int cur = 1;
		if (n <= 4)
		{
			for (int i = 1; i < n; i++)
			{
				cout << i << " ";
			}
			cout << n << endl;
			for (int i = 0; i < str.size(); i++)
			{
				if(str[i] == 'U')
				{
					bottle--;
					if (bottle < 1)
					{
						bottle = n;
					}
				}
				else
				{
					bottle++;
					if (bottle > n)
					{
						bottle = 1;
					}
				}
			}
			cout << bottle << endl;
		}
		else
		{
			for (int i = 0; i < str.size(); i++)
			{
				if (str[i] == 'U')
				{
					bottle--;
					if (bottle < 1)
					{
						bottle = n;
					}
					if (i == 0 || bottle == n)
					{
							cur = n - 3;
					}
					else
					{
						if(bottle < cur)
							cur--;
					}
				}
				else
				{
					bottle++;
					if (bottle > n)
					{
						bottle = 1;
						cur = 1;
					}
					else
					{
						if(bottle > cur+3)
							cur++;
					}
				}
			}
			if (cur + 3 <= n)
			{
				for (int i = cur; i < cur + 3; i++)
				{
					cout << i << " ";
				}
				cout << cur + 3 << endl;
				cout << bottle << endl;
			}
			else
			{
				for (int i = cur; i < n; i++)
				{
					cout << i << " ";
				}
				cout << n << endl;
				cout << bottle << endl;
			}
		}
	}
	return 0;
}