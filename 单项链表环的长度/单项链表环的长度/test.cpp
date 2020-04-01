#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<vector<int>> temp(100, vector<int>(2));
	vector<vector<int>> arr;
	arr.reserve(100);
	int i = 0;
	int j = 0;
	while (cin >> temp[i][j])
	{
		if (j == 1)
		{
			++i;
			j = 0;
		}

		arr[i].push_back(arr[i][j]);
		++j;
	}
	int count = 0;
	int flag = 0;
	for (int i = 0; i < arr.size(); ++i)
	{
		for (int j = i; j < arr.size(); ++j)
		{
			if (arr[i][0] == arr[j][1])
			{
				count = j - i + 1;
				flag = 1;
				break;
			}
		}

		if (flag == 1)
			break;
	}
	cout << count << endl;
	return 0;
}