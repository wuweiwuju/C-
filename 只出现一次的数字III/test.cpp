#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> nums{ 1,2,1,3,2,5 };
	int num1 = 0;
	int num2 = 0;
	int count = 0;
	int flag = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		count ^= nums[i];
	}
	for (int i = 0; i < 32; i++)
	{
		if ((1 << i) & count)
		{
			flag = i;
			break;
		}
	}
	int k = 0;
	int l = 0;
	int cur = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if ((1 << flag) & nums[i])
			num1 ^= nums[i];
		else
			num2 ^= nums[i];
	}
	cout << num1 << " " << num2 << endl;
	return 0;
}