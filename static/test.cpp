#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A()
//	{
//		++_scount;
//	}
//	A(const A& t)
//	{
//		++_scount;
//	}
//	static int GetACount()
//	{
//		return _scount;
//	}
//private:
//	static int _scount;
//};
//int A::_scount = 0;
//void TestA()
//{
//	cout << A::GetACount() << endl; 
//	A a1, a2;
//	A a3(a1);
//	cout << A::GetACount() << endl;
//}
//int main()
//{
//	A d;
//	cout<<d.GetACount()<<endl;
//	TestA();
//	return 0;
//}
#include<stdio.h>
int judge_Fib(int n)
{
	int x = 0;
	int y = 1;
	int z = 1;
	while (1)
	{
		if (x == n)
			return 0;
		x = y;
		y = z;
		z = x + y;
		if ((z > n) && (n > y))
		{
			if ((n - y) < (z - n))
				return (n - y);
			return (z - n);
		}
	}
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = judge_Fib(n);
	printf("%d\n", ret);
	return 0;
}