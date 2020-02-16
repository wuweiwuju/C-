#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int count[256] = { 0 };
		for (int i = 0; i < ransomNote.size(); ++i)
		{
			count[ransomNote[i]]++;
		}
		for (int i = 0; i < magazine.size(); ++i)
		{
			count[magazine[i]]--;
		}
		for (int i = 0; i < ransomNote.size(); ++i)
		{
			if (count[ransomNote[i]] > 0)
				return false;
		}
		return true;
	}
};