/*class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		if(array.size() == 1)
			return array[0];
		int max = array[0];
		int sum = 0;
		for(int i = 0; i < array.size();i++)
		{
			sum += array[i];
			if(sum < array[i])
				sum = array[i];
			if(sum > max)
				max = sum;
		}
		return max;
		int res = array[0];
		int count = array[0];
		for (int i = 1; i < array.size(); i++)
		{
			res = max(res + array[i], array[i]);
			count = max(res, count);
		}
		return count;
	}
};*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	vector<int> array;
	array.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	int res = array[0];
	int count = array[0];
	for (int i = 1; i < array.size(); i++)
	{
		res = max(res + array[i], array[i]);
		count = max(res, count);
	}
	cout << count << endl;
	return 0;
}
