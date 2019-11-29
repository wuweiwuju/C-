#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	string addend;
	string augend;
	string sum;
	while (cin >> addend >> augend)
	{
		int flag = 0;
		int count = 0;
		reverse(addend.begin(), addend.end());
		reverse(augend.begin(), augend.end());
		if (addend.size() > augend.size())
			swap(addend, augend);
		int small = addend.size();
		for (int i = 0; i < small; i++)
		{
			count = (addend[i] + augend[i]) - '0' - '0' + flag;
			flag = 0;
			if (count > 9)
			{
				flag = 1;
				count -= 10;
			}
			sum += count + '0';
		}
		count = 0;
		for (int i = small; i < augend.size(); i++)
		{
			count = augend[i] - '0' + flag;
			flag = 0;
			if (count > 9)
			{
				flag = 1;
				count -= 10;
			}
			sum += count + '0';
		}
		if (flag == 1)
			sum += '1';
		reverse(sum.begin(), sum.end());
		cout << sum << endl;
		sum.clear();
	}
	return 0;
}