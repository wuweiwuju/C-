#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool findNum(int num, vector<int> arr, int len)
{
	if (num <= arr[len - 1])
	{
		for (int i = 0; i < len; i++)
		{
			if (arr[i] == num)
				return true;
		}
	}
	if(num > 0)
	{
		int sum = 0;
		int count = 0;
		for (int i = 0; i < len; i++)
		{
			sum = arr[i];
			count = arr[i];
			for (int j = i + 1; j < len; j++)
			{
				count += arr[j];
				sum = sum + arr[j];
				if (count == num || sum == num)
					return true;
				sum = arr[i];
			}
		}
		return false;
	}
}
int main() 
{
	int len;
	cin >> len;
	vector<int> arr; 
	arr.resize(len);
	for (int i = 0; i < len; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	if (len < 0)
		return 0;
	if (len == 1)
		return arr[0] + 1;
	int min = arr[0];
	int max = 0;
	for (int i = 0; i < len; i++)
	{
		max += arr[i];
	}
	int flag = 0;
	for (int i = min + 1; i < max; i++)
	{
		if (!findNum(i, arr, len))
		{
			flag = i;
			break;
		}
	}
	if (flag != 0)
		cout << flag << endl;
	else
		cout << max + 1 << endl;
	return 0;
}