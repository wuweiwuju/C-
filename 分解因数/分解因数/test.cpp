#include<iostream>
using namespace std;
int main()
{
	int n = 0;
	while (cin >> n)
	{
		if (n >= 2)
		{
			int count = 2;
			int sum = n;
			int flag = 0;
			while (n != 1)
			{
				while (n % count == 0)
				{
					flag += 1;
					if (flag == 1)
						cout << sum << " " << "=" << " " << count;
					else
						cout << " " << "*" << " " << count;
					n /= count;
				}
				count++;
			}
			cout << endl;
		}
	}

	return 0;
}