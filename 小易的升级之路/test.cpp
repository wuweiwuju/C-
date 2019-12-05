#include<iostream>
#include<vector>
using namespace std;
int greaterCommon(int n1, int n2)
{
	int min = n1;
	while (1)
	{
		if (n2 % min == 0 && n1 % min == 0)
			return min;
		else
			min--;
	}
}
int main()
{
	int n = 0;
	int a = 0;
	while (cin >> n >> a)
	{
		vector<int> arr;
		arr.resize(n);
		int sum = a;
		for (int i = 0; i < arr.size(); i++)
		{
			cin >> arr[i];
		}
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i] <= sum)
				sum += arr[i];
			else
				sum += greaterCommon(sum, arr[i]);
		}
		cout << sum << endl;
		arr.clear();
	}
}