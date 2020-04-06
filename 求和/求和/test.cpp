#include<iostream>
#include<vector>
using namespace std;
vector<int> d;
void dfs(int, int);
int N,M;

void dfs(int index, int sum)
{
	if (sum > M) return;
	if (sum == M)
	{
		int i;
		for (i = 0; i < d.size() - 1; i++)
			cout << d[i] << " ";
		cout << d[i];
	}
	for (int i = index; i <= N; i++)
	{
		d.push_back(i);
		dfs(i + 1, sum + i);
		d.pop_back();
	}
}
int main() 
{
	while (cin >> N >> M)
		dfs(1, 0);
}