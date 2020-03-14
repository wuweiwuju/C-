// write your code here cpp
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> height(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> height[i];
		}

		vector<int> f(n, 1);
		int result = 1;
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (height[i] > height[j])
				{
					f[i] = max(f[i], f[j] + 1);
				}
			}
			result = max(result, f[i]);
		}

		cout << result << endl;
	}
}