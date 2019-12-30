#include<iostream>
using namespace std;
int main()
{
	int n = 0;
	while (cin >> n)
	{
		int count = 1;
		if (n <= 0)
			break;
		else if (n == 1)
			cout << 0 << endl;
		else if (n > 1 && n <= 3)
			cout << count << endl;
		else
		{
			while (n > 3)
			{
				if (n % 3 == 0)
					n /= 3;
				else
					n = n / 3 + 1;
				count++;
			}
			cout << count << endl;
		}
	}
	return 0;
}