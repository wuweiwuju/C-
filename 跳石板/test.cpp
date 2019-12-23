#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<int> v(m + 1, INT_MAX); //v[i]Ϊ�ڵ�i��ʯ��ʱ������Ҫ�Ĳ���
		v[n] = 0;
		for (int i = n; i <= m; i++)
		{
			for (int j = 2; j <= sqrt(i); j++) //����iΪ8�����ҵ�i��һ��Լ��jΪ2ʱ����һ��Լ����Ϊi/j
			{ //��j*j<=i,����������������г�ʱ
				if (i % j == 0)
				{
					if (i + j <= m)
						v[i + j] = min(v[i + j], v[i] + 1);
					if (i + i / j <= m) //�ؼ�����
						v[i + i / j] = min(v[i + i / j], v[i] + 1);
				}
			}
		}
		if (v[m] == INT_MAX)
			cout << "-1" << endl;
		else
			cout << v[m] << endl;
	}
}