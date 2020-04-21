//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int T = 0;
//	cin >> T;
//	while (T--)
//	{
//		int n = 0;
//		cin >> n;
//		vector<int> arr(n);
//		for (int i = 0; i < n; ++i)
//			cin >> arr[i];
//
//		if (n == 1 && arr[0] == 0)
//			cout << "woman" << endl;
//		else if (n == 1 && arr[0] % 2 != 0)
//			cout << "woman" << endl;
//		else if (n == 1 && arr[0] % 2 != 0)
//			cout << "man" << endl;
//		else
//			cout << "woman" << endl;
//		/*else
//		{
//			long long sum = 0;
//			for(int i = 0; i < n; ++i)
//				sum += arr[i];
//
//			if(sum % 2 != 0)
//				cout << "woman" << endl;
//			else
//				cout << "man" << endl;
//		}*/
//	}
//	return 0;
//}


#include<iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int a, b;
		a = n - 1;
		b = n;
		cout << a * b - 1 << endl;
	}
	return 0;
}

