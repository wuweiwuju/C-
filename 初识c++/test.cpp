#define _CRT_SECURE_NO_WARNINGS 1
//namespace N1//1.普通命名空间
//{
//	//命名空间的内容，即可以定义变量，也可以定义函数。
//	int a;
//	int Add(int left, int right) 
//	{
//		return left + right;
//	}
//}
//
//namespace N2//2.命名空间可以嵌套
//{
//	int a;
//	int b;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	namespace N3
//	{
//		int c;
//		int d;
//		int Sub(int left, int right)
//		{
//			return left - right;
//		}
//	}
//}
//
//namespace N1//3.命名空间可以重名，编译器会认为它们是在一个空间内
//{
//	int Mul(int left, int right)
//	{
//		return left * right;
//	}
//}
////注意：一个命名空间就定义了一个新的作用域，命名空间中的所有内容都局限于该命名空间中
//namespace N 
//{
//	int a = 10;
//	int b = 20;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	int Sub(int left, int right)
//	{
//		return left - right;
//	}
//}
//int main()
//{
//	printf("%d\n", N::a);
//	return 0;
//}
//namespace N
//{
//	int a = 10;
//	int b = 20;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	int Sub(int left, int right)
//	{
//		return left - right;
//	}
//}
//using namespace N;
//int main()
//{
//	printf("%d\n",a);
//	printf("%d\n",N:: b);
//	Add(10, 20);
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	cout << "Hello world!!!" << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a;
//	double b;
//	char c;
//	cin >> a >> b >> c;
//	cout << a << endl;
//	cout << b << endl;
//	cout << c;
//	return 0;
//}

//void TestFunc(int a = 0) 
//{
//	cout << a << endl;
//}
//int main()
//{
//	TestFunc(); // 没有传参时，使用参数的默认值
//	TestFunc(10);// 传参时，使用指定的实参
//}
//#include<iostream>
//using namespace std;
//void TestFunc(int a, int b = 10, int c = 20)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}

////a.h
//void TestFunc(int a = 10);
//// a.c
//void TestFunc(int a = 20)
//{}
//// 注意：如果生命与定义位置同时出现，恰巧两个位置提供的值不同，那编译器就无法确定到底该用那个缺省
//int Add(int left, int right) 
//{
//	return left + right;
//}
//double Add(double left, double right) 
//{
//	return left + right;
//}
//long Add(long left, long right) 
//{
//	return left + right;
//}
//int main()
//{
//	cout<<Add(10, 20)<<endl;
//	cout<<Add(10.0, 20.0)<<endl;
//	cout<<Add(10L, 20L);
//	return 0;
//}
//short Add(short left, short right)
//{
//	return left + right;
//}
//int Add(short left, short right)
//{
//	return left + right;
//}
//extern "C" int Add(int left, int right);
//int Add(int left, int right)
//{
//	return left + right;
//}
//int main()
//{
//	Add(1, 2);
//	return 0;
//}
//void TestFunc(int a = 10)
//{
//	cout << "void TestFunc(int)" << endl;
//}
//void TestFunc(int a) 
//{
//	cout << "void TestFunc(int)" << endl;
//}
//int main()
//{
//	TestFunc(5);
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	//int a = 10;
//	//int& ra = a;//<====定义引用类型
//	//printf("%p\n", &a);
//	//printf("%p\n", &ra);
//	/*int a = 10;
//	int& ra;
//	int& ra = a;
//	int& rra = a;
//	printf("%p %p %p\n", &a, &ra, &rra);*/
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	const int a = 10;
//	//int& ra = a;// 该语句编译时会出错，a为常量
//	const int& ra = a;
//	int& b = 10;// 该语句编译时会出错，b为常量
//	//const int& b = 10;
//	double d = 12.34;
//	//int& rd = d;// 该语句编译时会出错，类型不同
//	const int& rd = d;
//}
#include<iostream>
using namespace std;
//void Swap(int& left, int& right) 
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//int& TestRefReturn(int& a)
//{
//	a += 10;
//	return a;
//}
//int main()
//{
//	int b = 10;
//	TestRefReturn(b);
//	cout << b ;
//}

//int& Add(int a, int b) 
//{
//	static int c = a + b;
//	return c;
//}
//int main()
//{
//	int& ret = Add(1, 2);
//	Add(3, 4);
//	cout << "Add(1, 2) is :" << ret << endl;
//	return 0;
//}
//#include <time.h>
//struct A {
//	int a[10000];
//};
//void TestFunc1(A a)
//{}
//void TestFunc2(A& a)
//{}
//void TestRefAndValue()
//{
//	A a;
//	 以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	 以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	 分别计算两个函数运行结束后的时间
//		cout << "TestFunc1(int*)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(int&)-time:" << end2 - begin2 << endl;
//}
// 运行多次，检测值和引用在传参方面的效率区别
//int main()
//{
//	for (int i = 0; i < 10; ++i)
//	{
//		TestRefAndValue();
//	}
//	return 0;
//}
//#include <time.h>
//struct A {
//	int a[10000];
//};
//A a; A TestFunc1()
//{
//	return a;
//}A& TestFunc2()
//{
//	return a;
//}
//void TestReturnByRefOrValue()
//{
//	 以值作为函数的返回值类型
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//	 以引用作为函数的返回值类型
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//	 计算两个函数运算完成之后的时间
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}
// 测试运行10次，值和引用作为返回值效率方面的区别
//int main()
//{
//	for (int i = 0; i < 10; ++i)
//		TestReturnByRefOrValue();
//	return 0;
//}



//#include "F.h"
//void f(int i) 
//{
//	cout << i << endl;
//}

//int TestAuto()
//{
//	return 10;
//}
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = TestAuto();
//		cout << typeid(a).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	auto e;//无法通过编译，使用auto定义变量时必须对其进行初始化
//	return 0;
//}
//int main()
//{
//	int x = 10;
//	auto a = &x;
//	auto* b = &x;
//	auto& c = x;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	*a = 20;
//	*b = 30;
//	c = 40;
//	return 0;
//}
//void TestAuto()
//{
//	auto a = 1, b = 2;
//	auto c = 3, d = 4.0;// 该行代码会编译失败，因为c和d的初始化表达式类型不同
//}
// 此处代码编译失败，auto不能作为形参类型，因为编译器无法对a的实际类型进行推导
//void TestAuto(auto a){}
//void TestAuto()
//{
//	int a[] = { 1,2,3 };
//	auto b[] = { 4，5，6 };
//}
//在C++98中如果要遍历一个数组，可以按照以下方式进行：
//int main()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
//		array[i] *= 2;
//	for (int* p = array; p < array + sizeof(array) / sizeof(array[0]); ++p)
//		cout << *p << endl;
//}
/*对于一个有范围的集合而言，由程序员来说明循环的范围是多余的，有时候还会容易犯错误。因此C++11中引
入了基于范围的for循环。for循环后的括号由冒号“ ：”分为两部分：第一部分是范围内用于迭代的变量，第二
部分则表示被迭代的范围。*/
//int main()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//	for(auto& e : array)
//		e *= 2;
//	for (auto e : array)
//		cout << e << " ";
//	return 0;
//}
//注意：与普通循环类似，可以用continue来结束本次循环，也可以用break来跳出整个循环。
//void TestFor(int array[])
//{
//	for (auto& e : array)
//		cout << e << endl;
//}
//int main()
//{
//	int array[] = { 1,2,3,4,5 };
//	TestFor(array);
//}
void f(int)
{
	cout << "f(int)" << endl;
}
void f(int*)
{
	cout << "f(int*)" << endl;
}
int main()
{
	f((int *)0);
	f(NULL);
	f((int*)NULL);
	return 0;
}