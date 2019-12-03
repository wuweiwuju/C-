#include<iostream>
using namespace std;
int getTotalCount(int monthCount)
{
	if (monthCount == 1 || monthCount == 2)
		return 1;
	return getTotalCount(monthCount - 1) + getTotalCount(monthCount - 2);
}
int main()
{
	int month = 0;
	while (cin >> month)
	{
		int ret = getTotalCount(month);
		cout << ret << endl;
	}
	return 0;
}