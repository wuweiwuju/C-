#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	void replaceSpace(char* str, int length) {
		if (NULL == str)
			return;
		int count = 0;
		int num = length;
		for (int i = 0; i < length; i++)
		{
			if (str[i] == ' ')
			{
				count++;
			}
		}
		length = length + 2 * count;
		while (num--)
		{
			if (str[num] != ' ')
			{
				str[num + count * 2 - 1] = str[num - 1];
			}
			else
			{
				str[num + count * 2 - 2] = '%';
				str[num + count * 2 - 1] = '2';
				str[num + count * 2] = '0';
				count--;
			}
		}

	}
};