class Solution {
public:
	string addStrings(string num1, string num2) {
		if (num1.size() < num2.size())
		{
			num1.swap(num2);
		}
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		string num;
		num.reserve(num1.size() + 1);
		char cret = 0;
		char flag = 0;
		for (int i = 0; i < num1.size(); i++)
		{
			if (num2.size() < i + 1)
				cret = (num1[i] - '0') + flag;
			else
				cret = (num1[i] - '0') + (num2[i] - '0') + flag;
			flag = 0;
			if (cret > 9)
			{
				cret -= 10;
				flag = 1;
			}
			num += cret + '0';
		}
		if (flag == 1)
			num += '1';
		reverse(num.begin(), num.end());
		return num;
	}
};