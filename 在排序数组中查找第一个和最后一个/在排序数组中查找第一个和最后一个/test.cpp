#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	int mid = 0;
	vector<int> arr;
	arr.resize(2);
	while (left < right)
	{
		if (nums[left] == nums[right] && nums[left] == target)
		{
			arr[0] = left;
			arr[1] = right - 1;
			return arr;
		}
		else if (nums[left] == nums[right] && nums[left] != target)
		{
			arr[0] = -1;
			arr[1] = -1;
			return arr;
		}
		mid = left + (right - left) / 2;
		if (nums[mid] == target)
		{
			int start = mid;
			while (start >= 0 && nums[start] == target)
			{
				arr[0] = start;
				--start;
			}
			while (mid < nums.size() && nums[mid] == target)
			{
				arr[1] = mid;
				++mid;
			}
			return arr;
		}
		else if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	arr[0] = -1;
	arr[1] = -1;
	return arr;
}
int main()
{
	vector<int> array{ 1,3 };
	searchRange(array , 1);
	return 0;
}


class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ans = { -1, -1 };
		if (nums.empty()) return ans; // ����Ϊ�յ����
		int l = 0, r = nums.size() - 1;
		if (nums[l] > target) return ans; // ��target�������鷶Χ��
		if (nums[r] < target) return ans;

		while (l < r) { // �Ȳ���Ԫ�صĵ�һ��λ��
			int mid = l + (r - l) / 2;
			if (nums[mid] >= target) r = mid;
			else l = mid + 1;
		} // ����ѭ��ʱ������ l �� r ��ͬһ��λ�ã�������Ԫ�صĵ�һ��λ��
		if (nums[l] == target)   ans[0] = l; // ��ֹ����Ԫ��������λ���� �� ������û��Ŀ��Ԫ��
		r = nums.size(); // ����� nums.size() - 1 ��ԭ���ǣ�Ӧ�������СΪһ���������������ᳬ��������
		while (l < r) { // ����Ԫ�ص����һ��λ��
			int mid = l + (r - l) / 2;
			if (nums[mid] > target) r = mid;
			else l = mid + 1;
		}
		// ����ѭ��ʱ��l��r ��ͬһ��λ�ã��� ����Ԫ�ص����һ��λ�õ���һλ
		if (nums[l - 1] == target)   ans[1] = l - 1;
		return ans;
	}
};