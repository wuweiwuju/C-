//#define _CRT_SECURE_NO_WARNINGS 1
//class Solution {
//public:
//	int searchInsert(vector<int>& nums, int target) {
//		int count = 0;
//		int i = 0;
//		for (i = 0; i < nums.size(); ++i)
//		{
//			if (nums[i] == target)
//			{
//				count = i;
//				break;
//			}
//			else if (nums[i] < target)
//			{
//				count = i;
//			}
//			else
//			{
//				count = i;
//				break;
//			}
//		}
//		if (i == nums.size())
//			++count;
//		return count;
//	}
//};

//应该使用二分查找
#include<iostream>
#include<vector>
using namespace std;
int searchInsert(vector<int>& nums, int target) 
{
	int left = 0;
	int right = nums.size();
	int mid = 0;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		//mid = (left + right) / 2;
		if (nums[mid] == target)
			return mid;
		//这里的区间要注意一下不是mid - 1 而是mid
		else if (nums[mid] > target)
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}
int main()
{
	vector<int> nums{1,3,5,6};
	searchInsert(nums, 7);
	return 0;
}
