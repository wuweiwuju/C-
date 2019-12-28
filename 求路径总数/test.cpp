#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int PathName(int x, int y)
{
	if (x > 1 && y > 1)
		return PathName(x, y - 1) + PathName(x - 1, y);
	else if (x >= 1 && y == 1 || x == 1 && y >= 1)
		return x + y;
	else
		return 0;
}
int main()
{
	int n = 0;
	int m = 0;
	while (cin >> n >> m)
	{
		int ret = PathName(n, m);
		cout << ret << endl;
	}
	return 0;
}