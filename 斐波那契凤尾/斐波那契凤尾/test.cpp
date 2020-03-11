// write your code here cpp
#include<iostream>
#include <iomanip>
using namespace std;
int main() {
	int Arr[100001];
	int n = 0;
	Arr[0] = 1;
	Arr[1] = 1;
	for (int i = 2; i <= 100000; i++)
	{
		Arr[i] = Arr[i - 1] + Arr[i - 2];
		Arr[i] = Arr[i] % 1000000;
	}
	while (cin >> n) {
		//前面补0,要用06d
		if (n < 29)
			cout << Arr[n] << endl;
		else
			cout << setfill('0') << setw(6) << Arr[n] << endl;
	}
	return 0;
}