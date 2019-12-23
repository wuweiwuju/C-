#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<int> v(m + 1, INT_MAX); //v[i]为在第i个石板时，所需要的步数
		v[n] = 0;
		for (int i = n; i <= m; i++)
		{
			for (int j = 2; j <= sqrt(i); j++) //比如i为8，当找到i的一个约数j为2时，另一个约数就为i/j
			{ //找j*j<=i,如果不这样，会运行超时
				if (i % j == 0)
				{
					if (i + j <= m)
						v[i + j] = min(v[i + j], v[i] + 1);
					if (i + i / j <= m) //关键步骤
						v[i + i / j] = min(v[i + i / j], v[i] + 1);
				}
			}
		}
		if (v[m] == INT_MAX)
			cout << "-1" << endl;
		else
			cout << v[m] << endl;
	}
}