#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
int myAtoi(string str) {
	if (str.size() == 0)
		return 0;
	int i = 0;
	while (str[i] == ' ')
	{
		++i;
	}
	if ((i > str.size() - 1)
		|| ((str[i] != '+')
			&& (str[i] != '-') &&
			(str[i] < '0' || str[i] > '9')))
		return 0;
	int flag = 0;
	while (str[i] == '0')
	{
		++i;
		flag++;
	}
	if (flag != 0)
	{
		if (str[i] < '0' || str[i] > '9')
			return 0;
	}
	string tmp;
	if (str[i] == '-')
	{
		tmp += '-';
		i = i + 1;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	else
	{
		i = i;
	}
	if (str[i] == ' ')
		return 0;
	while (str[i] == ' ')
	{
		++i;
	}
	while (str[i] == '0')
	{
		++i;
	}
	if ((i > str.size() - 1)
		|| (str[i] < '0' || str[i] > '9'))
		return 0;
	for (i = i; i < str.size(); ++i)
	{
		if (str[i] >= '0' && str[i] <= '9')
			tmp += str[i];
		else
			break;
	}
	long long sum = 0;
	int init_num = 0;
	int count = tmp.size();
	if (tmp[0] == '-')
	{
		count = tmp.size() - 1;
		init_num = 1;
	}
	long long j = 1;
	while (--count && count > 0)
	{
		j *= 10;
		if (j > 2147483648)
		{
			if (tmp[0] == '-')
				return 2147483648;
			else
				return 2147483647;
		}
	}
	for (int i = init_num; i < tmp.size(); ++i)
	{
		sum += (tmp[i] - '0') * j;
		j /= 10;
	}
	if (tmp[0] == '-')
		sum *= -1;
	if (sum >= 2147483648)
		return 2147483647;
	if (sum < 2147483648)
		return 2147483648;
	return sum;
}
int main()
{
	int ret = myAtoi("  0000000000012345678");
	return 0;
}