#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	int lengthOfLastWord(string s) {
		int count = 0;
		int later = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] != ' ')
			{
				++count;
				later = count;
			}
			else
			{
				count = 0;
			}
		}
		if (count == 0 && later != 0)
			return later;
		return count;
	}
};