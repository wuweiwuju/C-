#include<iostream>
using namespace std;
int main()
{
	int n = 0;
	while (cin >> n)
	{
		int count = 1;
		int a = 0;
		int b = 0;
		int flag = 0;
		while(1)
		{
			int sum = count * 5 + 1;
			if (sum % 4 == 0)
			{
				a = sum;
				b++;
				flag++;
			}
			if (flag == 1)
				b += (sum / 5) * 4;
			if (flag == n)
				break;
			count++;
		}
		cout << a << b << endl;
	}
}
