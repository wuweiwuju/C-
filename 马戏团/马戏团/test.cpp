#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
struct unit
{
	int id;
	int weight;
	int height;
};
bool cmp(unit u1, unit u2) {
	if (u1.weight != u2.weight) return u1.weight < u2.weight;
	else return u1.height > u2.height;
}
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		vector<unit> vec(n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d", &vec[i].id, &vec[i].weight, &vec[i].height);
		}
		sort(vec.begin(), vec.end(), cmp);
		vector<int> dp(n, 1);
		int max = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (dp[j] + 1 > dp[i] && vec[i].height >= vec[j].height) {
					dp[i] = dp[j] + 1;
				}
			}
			if (dp[i] > max) max = dp[i];
		}
		printf("%d\n", max);
	}
}