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
	long long sum = 0;	//������Ҫע��һ�£������sum����Ϊint���Ϳ��ܻᳬ��int�Ĵ洢��Χ
	vector<int> arr;
	cin >> n;
	arr.resize(n * 3);
	for (auto i = 0; i < n * 3; ++i)
		cin >> arr[i];

	sort(arr.begin(), arr.end());         //�Գ�Ա�ĳɼ��������� 
	//for (int i = 3 * n - 2; i >= n; i -= 2) //����ǰ���ͼ�ⶨ���ѭ����
	for (int i = n; i <= 3 * n - 2; i += 2)   //�������Ҹ��˷��ϰ�߽�i�ĳ�ʼ����һЩ  
	{
		sum += arr[i];
	}

	cout << sum << endl;
	return 0;
}*/
