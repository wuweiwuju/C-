#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	vector<int> array;
	array.resize(3 * n);
	for (int i = 0; i < 3 * n; i++)
	{
		cin >> array[i];
	}
	sort(array.begin(), array.end());
	reverse(array.begin(), array.end());
	long sum = 0;
	int i = 1;
	while (n--)
	{
		sum += array[i];
		i += 2;
	}
	cout << sum << endl;
	return 0;
}
/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n = 0;
	long long sum = 0;	//这里需要注意一下，如果将sum定义为int类型可能会超出int的存储范围
	vector<int> arr;
	cin >> n;
	arr.resize(n * 3);
	for (auto i = 0; i < n * 3; ++i)
		cin >> arr[i];

	sort(arr.begin(), arr.end());         //对成员的成绩进行排序 
	//for (int i = 3 * n - 2; i >= n; i -= 2) //这个是按照图解定义的循环，
	for (int i = n; i <= 3 * n - 2; i += 2)   //下面是我个人风格，习惯将i的初始化简单一些  
	{
		sum += arr[i];
	}

	cout << sum << endl;
	return 0;
}*/
