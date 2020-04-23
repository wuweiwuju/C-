#define _CRT_SECURE_NO_WARNINGS 1

/*#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string A, B;
	while (cin >> A >> B) {
		int aLength = A.length();
		int bLength = B.length();
		vector<vector<int> > dp(aLength, vector<int>(bLength, 0));
		// 初始化边界
		dp[0][0] = (A[0] == B[0]) ? 1 : 0;
		for (int i = 1; i < aLength; i++) {
			dp[i][0] = (A[i] == B[0]) ? 1 : 0;
			dp[i][0] = max(dp[i - 1][0], dp[i][0]);
		}
		for (int j = 1; j < bLength; j++) {
			dp[0][j] = (A[0] == B[j]) ? 1 : 0;
			dp[0][j] = max(dp[0][j - 1], dp[0][j]);
		}
		// 计算
		for (int i = 1; i < aLength; i++) {
			for (int j = 1; j < bLength; j++) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				if (A[i] == B[j]) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
				}
			}
		}
		cout << dp[aLength - 1][bLength - 1] << endl;
	}

return 0;
}*/

#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1001;
int n, m;
char a[N], b[N];
int f[N][N];

int main()
{
	cin >> n >> m >> a + 1 >> b + 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			if (a[i] == b[j])    f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
		}

	cout << f[n][m] << endl;

	return 0;
}