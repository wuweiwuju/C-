#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	int n = 0;
//	string A;
//	cin >> n;
//	cin >> A;
//	if (n % 2 != 0)
//	{
//		cout << "false" << endl;
//		return 0;
//	}
//	if (A[0] != '(' || A[A.size() - 1] != ')')
//	{
//		cout << "false" << endl;
//		return 0;
//	}
//	int count = 0;
//	int tmp = 0;
//	for (int i = 0; i < A.size(); i++)
//	{
//		if (A[i] != '(' && A[i] != ')')
//		{
//			cout << "false" << endl;
//			return 0;
//		}
//		if (A[i] == '(')
//			count++;
//		if (A[i] == ')')
//			tmp++;
//	}
//	if (tmp != count)
//	{
//		cout << "false" << endl;
//		return 0;
//	}
//	for (int i = 0; i < A.size(); i++)
//	{
//		if (A[i] == '(')
//			count--;
//		else
//			tmp--;
//		if (tmp < count)
//		{
//			cout << "false" << endl;
//			return 0;
//		}
//	}
//	cout << "true" << endl;
//	return 0;
//}

#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
	string A;
	cin >> A;
	stack<char> str;
	for (auto i : A)
	{
		switch (i)
		{
		case '(':
			str.push(i);
				break;
		case ')':
			if (str.empty() || str.top() != '(')
				return 0;
			else
				str.pop();
			break;
		default:
			return 0;
		}
	}
	cout << "true" << endl;
	return 0;
}