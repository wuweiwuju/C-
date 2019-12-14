#include<iostream>
#include<vector>
using namespace std;
int findElement(vector<int> A, int n, int x)
{
	int mid = 0;
	int right = n - 1;
	int left = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (A[mid] == x)
			return mid;
		if (A[mid] < A[right])
		{
			if (A[right] >= x && x > A[mid])
				left = mid + 1;
			else
				right = mid - 1;
		}
		if (A[mid] > A[left])
		{
			if (A[left] <= x && x < A[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
	}
	return -1;
}
int main()
{
	vector<int> A;
	int n;
	int x;
	cin >> n >> x;
	A.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	int ret = findElement(A, n, x);
	cout << ret << endl;
	return 0;
}