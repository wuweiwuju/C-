#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	string reverseWords(string s) {
		string::iterator it = s.begin();
		int count = 0;
		while (it < s.end())
		{
			if (*it != ' ')
			{
				count = s.find(' ', count + 1);
				if (count == s.npos)
				{
					reverse(it, s.end());
					return s;
				}
				reverse(it, s.begin() + count);
				it = s.begin() + count;
			}
			else
			{
				it++;
			}
		}
		return s;
	}
};