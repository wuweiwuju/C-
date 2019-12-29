#define _CRT_SECURE_NO_WARNINGS 1
/*#include <iostream>
#include <string>
using namespace std;
int get_root(int origin) {
	if (origin < 10) {
		return origin;
	}
	int sum = 0;
	while (origin > 0) {
		sum += origin % 10;
		origin /= 10;
	}
	if (sum >= 10) {
		sum = get_root(sum);
	}
	return sum;
}
int main()
{
	string origin;
	while (cin >> origin) {
		int sum = 0;
		for (auto t = origin.begin(); t != origin.end(); t++) {
			sum = sum + (*t) - '0';
		}
		sum = get_root(sum);
		cout << sum << endl;
	}
}*/
#include<iostream>
using namespace std;
int numRoot(int n)
{
	int sum = 0;
	while (n)
	{
		sum += n % 10;
		n = n / 10;
	}
	if (sum > 9)
		return numRoot(sum);
	else
		return sum;
}
int main()
{
	string n;
	while (cin >> n)
	{
		int sum = 0;
		for (int i = 0; i < n.size(); i++)
		{
			sum += n[i] - '0';
		}
		int ret = numRoot(sum);
		cout << ret << endl;
	}
	return 0;
}