#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int target;
	vector<vector<int> > array;
	cin >> target;
	array.resize(4);
	for (int i = 0; i < 4; i++)
	{
		array[i].resize(4);
	}
	for (int i = 0; i < array.size(); i++)
	{
		for (int j = 0; j < array.size(); j++)
		{
			cin >> array[i][j];
		}
	}
	int row = array.size() - 1;
	int column = 0;
	while (row >= 0 && column < array[0].size())
	{
		if (array[row][column] < target)
		{
			column++;
		}
		else if (array[row][column] > target)
		{
			row--;
		}
		else
		{
			cout << "true" << endl;
			return 0;
		}
	}
	cout << "false" << endl;
	return 0;
}