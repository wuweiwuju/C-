#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int w, h;
	cin >> w >> h;
	vector<vector<int>> a(h, vector<int>(0));
	for (int i = 0;i < h;i++)
	{
		a[i].resize(w);
	}
	int count = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (a[i][j] == 0)
			{
				count++;
				if (i + 2 < h)
				{
					a[i + 2][j] = 2;
				}
				if (j + 2 < w)
				{
					a[i][j + 2] = 2;
				}
			}
		}
	}
	cout << count;
	return 0;
}