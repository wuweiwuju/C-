#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	int thirdMax(vector<int>& nums) {
		long long one = LONG_MIN;
		long long two = LONG_MIN;
		long long three = LONG_MIN;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] > one)
				one = nums[i];
		}
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] != one && nums[i] > two)
				two = nums[i];
		}
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] != one && nums[i] != two && nums[i] > three)
				three = nums[i];
		}
		if (three != LONG_MIN)
			return three;
		return one;
	}
};