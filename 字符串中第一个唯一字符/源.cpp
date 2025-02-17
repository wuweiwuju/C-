#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	int firstUniqChar(string s) {
		int count[256] = { 0 };
		int size = s.size();
		for (int i = 0; i < size; ++i)
			count[s[i]] += 1;
		// 按照字符次序从前往后找只出现一次的字符
		for (int i = 0; i < size; ++i)
			if (1 == count[s[i]])
				return i;
		return -1;

	}
};