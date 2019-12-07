#include<iostream>
using namespace std;
int main()
{
	double n = 0;
	double r = 0;
	while (cin >> n >> r)
	{
		if (2 * 3.14 * r >= n)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}