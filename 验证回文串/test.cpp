#define _CRT_SECURE_NO_WARNINGS 1
#include<string>
#include<iostream>
using namespace std;
int Valid_characters(char s)
{
	if ((s >= '0' && s <= '9') ||
		(s >= 'a' && s <= 'z') ||
		(s >= 'A' && s <= 'Z'))
	{
		return 0;
	}
	return -1;
}
class Solution {
public:
	bool isPalindrome(string s) {
		if (s.empty())
			return true;
		int front = 0;
		int back = s.size() - 1;
		while (front < back)
		{
			//从前到后 找有效字符
			while (front < back)
			{
				if (Valid_characters(s[front]) == 0)
				{
					break;
				}
				front++;
			}
			//从后到前 找有效字符
			while (front < back)
			{
				if (Valid_characters(s[back]) == 0)
				{
					break;
				}
				back--;
			}
			if ((s[front] + 32 - 'a')%32 == (s[back] + 32 - 'a')%32)
			{
				front++;
				back--;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
};
int main()
{
	Solution str;
	string s;
	getline(cin, s);
	str.isPalindrome(s);
	return 0;
}