#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		vector<int> temp;
		for (int i = 0; i < array.size(); i++)
		{
			if (array[i] % 2 == 1)
				temp.push_back(array[i]);
		}
		for (int i = 0; i < array.size(); i++)
		{
			if (array[i] % 2 == 0)
				temp.push_back(array[i]);
		}
		for (int i = 0; i < array.size(); i++)
		{
			array[i] = temp[i];
		}
	}
};