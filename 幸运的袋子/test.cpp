#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n = 0;
	while (cin >> n)
	{
		vector<int> arr;
		arr.resize(n);
		int num1 = 0;
		int num2 = 1;
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		while (n && n != 1)
		{
			for (int i = 0; i < n; i++)
			{
				num1 += arr[i];
			}
			for (int j = 0; j < n; j++)
			{
				num2 *= arr[j];
			}
			if (num1 > num2)
			{
				count++;
				num1 = 0;
				num2 = 0;
			}
			num1 = 0;
			num2 = 0;
			n--;
		}
		cout << count << endl;
		arr.clear();
	}
	return 0;
}