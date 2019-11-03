class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		/*if(array.size() == 1)
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
		return max;*/
		int res = array[0];
		int count = array[0];
		for (int i = 1; i < array.size(); i++)
		{
			res = max(res + array[i], array[i]);
			count = max(res, count);
		}
		return count;
	}
};