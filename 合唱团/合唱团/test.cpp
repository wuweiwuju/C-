#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() 
{
	int n, k, d;
	cin >> n;

	if (n < 1)
		return 0;
	vector<int> stud(n);
	for (int i = 0; i < n; i++) 
	{
		cin >> stud[i];
	}
	cin >> k >> d;
	if (k > n || k < 1 || d < 1) return 0;

	vector<vector<long long>> maxMul(n, vector<long long>(k + 1, 0));
	vector<vector<long long>> minMul(n, vector<long long>(k + 1, 0));

	for (int i = 0; i < n; i++) 
	{
		maxMul[i][1] = stud[i];
		minMul[i][1] = stud[i];
	}

	for (int i = 2; i <= k; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			for (int m = 1; m <= d && j >= m; m++) 
			{
				maxMul[j][i] = max(maxMul[j][i], max(maxMul[j - m][i - 1] * stud[j], minMul[j - m][i - 1] * stud[j]));
				minMul[j][i] = min(minMul[j][i], min(minMul[j - m][i - 1] * stud[j], maxMul[j - m][i - 1] * stud[j]));
			}
		}
	}

	long long maxMulResult = 1LL << 63;
	for (int i = 0; i < n; i++) 
	{
		maxMulResult = max(maxMulResult, maxMul[i][k]);
	}

	cout << maxMulResult;
	return 0;
}