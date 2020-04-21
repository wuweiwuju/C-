#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//通过vector创建的二维数组进行递归调用，把已经走过的结点标记成'1',避免访问过的
//结点重复计数
/*void BlackCount(vector<vector<char>>& v, int x, int y, int m, int n, int& count)
{
	//count通过引用的方式，正好递归调用进行计数
	if (x < 0 || y < 0 || x >= m || y >= n || v[x][y] == '1' || v[x][y] == '#')
		return;
	count++;
	v[x][y] = '1';
	BlackCount(v, x - 1, y, m, n, count);
	BlackCount(v, x, y - 1, m, n, count);
	BlackCount(v, x + 1, y, m, n, count);
	BlackCount(v, x, y + 1, m, n, count);
}

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		int x, y;
		int count = 0;
		vector<vector<char>> v(m, vector<char>(n, 0));
		for (size_t i = 0; i < m; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				cin >> v[i][j];
				if (v[i][j] == '@')
				{
					x = i;//x标记起始i结点
					y = j;//y表示起始j结点
				}
			}
		}
		BlackCount(v, x, y, m, n, count);
		cout << count << endl;
	}
	return 0;
}*/


void NumBlacktiles(vector < vector<char>>& v, int x, int y, int m, int n, int& count)
{
	if (x < 0 || y < 0 || x >= m || y >= n || v[x][y] == '#' || v[x][y] == '1')
		return;

	v[x][y] = '1';
	++count;
	NumBlacktiles(v, x - 1, y, m, n, count);
	NumBlacktiles(v, x, y - 1, m, n, count);
	NumBlacktiles(v, x + 1, y, m, n, count);
	NumBlacktiles(v, x, y + 1, m, n, count);
}
int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		vector < vector<char>> res(m, vector<char>(n, 0));
		int x = 0;
		int y = 0;
		int count = 0;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> res[i][j];
				if (res[i][j] == '@')
				{
					x = i;
					y = j;
				}
			}
		}
		NumBlacktiles(res, x, y, m, n, count);

		cout << count << endl;
	}
	return 0;
}