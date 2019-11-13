#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	vector<int> arr;
	arr.resize(n + 1);
	arr[n] = 0;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < arr[i + 1])
		{
			while (arr[i] <= arr[i + 1])
			{
				i++;
			}
			count++;
		}
		else if (arr[i] > arr[i + 1])
		{
			while (arr[i] >= arr[i + 1])
			{
				i++;
				if (i == n)
					break;
			}
			count++;
		}
	}
	cout << count << endl;
	return 0;
}