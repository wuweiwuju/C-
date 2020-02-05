#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	bool isPalindrome(int x) {

		//int ×ª»»³É string
		string str1 = to_string(x);
		string str2 = to_string(x);

		reverse(str2.begin(), str2.end());
		if (str1 == str2)
			return true;
		return false;
	}
};