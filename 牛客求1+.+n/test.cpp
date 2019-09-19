#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	Solution()
	{
		count++;
		sum += count;
	}
	static void SetSum()
	{
		count = 0;
		sum = 0;
	}
	static int GetSum()
	{
		return sum;
	}
	int Sum_Solution(int n)
	{
		Solution::SetSum();
		Solution s[n];
		return Solution::GetSum();
	}
private:
	static int count;
	static int sum;
};
int Solution::count = 0;
int Solution::sum = 0;