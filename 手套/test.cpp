#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	// write code here
	vector<int> left;
	vector<int> right;
	int left_sum = 0;
	int right_sum = 0;
	int left_min = INT_MAX;
	int right_min = INT_MAX;
	int count = 0;
	left.resize(6);
	right.resize(6);
	left[0] = 1;
	left[1] = 2;
	left[2] = 0;
	left[3] = 1;
	left[4] = 3;
	left[5] = 1;
	right[0] = 0;
	right[1] = 0;
	right[2] = 0;
	right[3] = 2;
	right[4] = 0;
	right[5] = 1;
	for (int i = 0; i < 6; i++)
	{
		if (left[i] * right[i] == 0)
		{
			count += right[i] + left[i];
		}
		else
		{
			left_min = min(left_min, left[i]);
			left_sum += left[i];
			right_min = min(right_min, right[i]);
			right_sum += right[i];
		}
	}
	cout << min(left_sum - left_min + count + 2, right_sum - right_min + count + 2) << endl;
	return 0;
}