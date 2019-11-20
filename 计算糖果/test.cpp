/*#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> arr;
	arr.resize(4);
	for (int i = 0; i < 4; i++)
	{
		cin >> arr[i];
	}
	int A = (arr[0] + arr[2]) / 2;
	int B = (arr[1] + arr[3]) / 2;
	int C = (arr[3] - arr[1]) / 2;
	if (A - B == arr[0] && B - C == arr[1] && A + B == arr[2] && B + C == arr[3])
	{
		cout << A << " " << B << " " << C << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}*/

#include<iostream>
using namespace std;
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int A = (a + c) / 2;
	int C = (d - b) / 2;
	int B1 = (b + d) / 2;
	int B2 = (c - a) / 2;
	if (B1 != B2)
		cout << "No" << endl;
	else
		cout << A << ' ' << B1 << ' ' << C << endl;
	return 0;
}