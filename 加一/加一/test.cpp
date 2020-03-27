#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		for (int i = digits.size() - 1; i >= 0; i--)
		{
			digits[i]++;
			digits[i] = digits[i] % 10;
			if (digits[i] != 0)
				return digits;
		}
		digits.resize(digits.size() + 1);
		digits[0] = 1;
		return digits;
	}
};