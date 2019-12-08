#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> shuffleCards(vector<int> arr)
{
	vector<int> swap;
	swap.resize(arr.size());
	int j = 0;
	int k = 0;
	int m = arr.size() / 2;
	for (int i = 0; i < arr.size(); i++)
	{
		if (j == 0)
		{
			swap[i] = arr[k];
			j = 1;
			k++;
		}
		else
		{
			swap[i] = arr[m];
			j = 0;
			m++;
		}
	}
	return swap;
}
int main()
{
	int T = 0;
	int n = 0;
	int k = 0;
	int min = 0;
	int max = 0;
	int len = 0;
	vector<int> sum;
	sum.resize(100000);
	while (cin >> T)
	{
		int flag = T;
		while (T--)
		{
			cin >> n >> k;
			vector<int> arr1;
			vector<int> arr2;
			arr1.resize(2 * n);
			arr2.resize(2 * n);
			for (int i = 0; i < 2 * n; i++)
			{
				cin >> arr1[i];
			}
			arr2 = arr1;
			while (k--)
			{
				arr2 = shuffleCards(arr2);
			}
			if (flag == T + 1)
			{
				max = arr2.size();
				len = max;
			}
			else
			{
				max += arr2.size();
				min = max - arr2.size();
			}
			int l = 0;
			for (int i = min; i < max; i++)
			{
				sum[i] = arr2[l];
				l++;
			}
			for (int i = min; i < max - 1; i++)
			{
				cout << sum[i] << " ";
			}
			cout << sum[max - 1] << endl;
			arr2.clear();
			arr1.clear();
			sum.clear();
		}
	}
}