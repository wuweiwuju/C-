#include<iostream>
#include<vector>
using namespace std;
vector<int> clockwisePrint(vector<vector<int> >& mat, int n, int m) {
	// write code here
	vector<int> arr(n*m);
	int left = 0;
	int right = m - 1;
	int up = 0;
	int down = n - 1;
	int count = 0;
	while (left <= right && up <= down && count < n*m)
	{
		for (int i = left; i <= right; ++i)
		{
			arr[count] = mat[up][i];
			++count;
		}
		++up;
		if (up > down)
			break;
		for (int i = up; i <= down; ++i)
		{
			arr[count] = mat[i][right];
			++count;
		}
		--right;
		if (left > right)
			break;
		for (int i = right; i >= left; --i)
		{
			arr[count] = mat[down][i];
			++count;
		}
		--down;
		for (int i = down; i >= up; --i)
		{
			arr[count] = mat[i][left];
			++count;
		}
		++left;
	}
	return arr;
}
int main()
{
	vector<vector<int> > mat{ {1} , {4}, {7}  };
	int n = 3;
	int m = 1;
	vector<int> arr = clockwisePrint(mat, n,  m);
	return 0;
}