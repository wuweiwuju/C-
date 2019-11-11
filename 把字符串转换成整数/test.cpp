class Solution {
public:
	int StrToInt(string str) {
		if (str.size() == 0)
			return 0;
		int sum = 0;
		int j = 1;
		int k = 0;
		if (str[0] == '+')
		{
			k = 1;
		}
		else if (str[0] == '-')
		{
			k = 1;
		}
		else
		{
			k = 0;
		}
		for (int i = str.size() - 1; i >= k; i--)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				sum += (str[i] - '0') * j;
				j *= 10;
			}
			else
			{
				return 0;
			}
		}
		if (str[0] == '-')
			return sum * (-1);
		return sum;
	}
};