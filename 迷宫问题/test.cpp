#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
	int n = 0; 
	int m = 0;
	while (cin >> n >> m)
	{
		vector<vector<int>> arr;
		arr.resize(n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> arr[i][j];
			}
		}
		int k = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = k; j < m; j++)
			{
				if (arr[i][j] == 0)
				{
					printf("(%d,%d)\n", i,j);
					k = j;
				}
				else
				{
					break;
				}
			}
		}
		arr.clear();
	}
	return 0;
}