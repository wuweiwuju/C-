#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//ͨ��vector�����Ķ�ά������еݹ���ã����Ѿ��߹��Ľ���ǳ�'1',������ʹ���
//����ظ�����
/*void BlackCount(vector<vector<char>>& v, int x, int y, int m, int n, int& count)
{
	//countͨ�����õķ�ʽ�����õݹ���ý��м���
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
					x = i;//x�����ʼi���
					y = j;//y��ʾ��ʼj���
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