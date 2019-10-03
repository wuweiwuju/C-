#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//
//class Test
//{
//public:
//	Test()
//		: _data(0)
//	{
//		cout << "Test():" << this << endl;
//	}
//	~Test()
//	{
//		cout << "~Test():" << this << endl;
//	}
//private:
//	int _data;
//};
//void Test2()
//{
//	// 申请单个Test类型的空间
//	Test* p1 = (Test*)malloc(sizeof(Test));
//	free(p1);
//	// 申请10个Test类型的空间
//	Test* p2 = (Test*)malloc(sizeof(Test) * 10);
//	free(p2);
//}
//void Test2()
//{
//	// 申请单个Test类型的对象
//	Test* p1 = new Test;
//	delete p1;
//	// 申请10个Test类型的对象
//	Test* p2 = new Test[10];
//	delete[] p2;
//}
//void Test()
//{
//	// 动态申请一个int类型的空间
//	int* ptr4 = new int;
//	// 动态申请一个int类型的空间并初始化为10
//	int* ptr5 = new int(10);
//	// 动态申请10个int类型的空间
//	int* ptr6 = new int[3];
//	delete ptr4;
//	delete ptr5;
//	delete[] ptr6;
//}
//int main()
//{

//}
//malloc整理 深入 
//new/delete->单个对象 new[]/delete[]->连续空间
//malloc / free            new / delete
// C标准库函数              C++中的操作符
//void*->强转               不需要强转
// 字节数                    new 类型
//申请失败->NULL->判空       不需要判空
//malloc 不会调用构造函数    new 会调用构造函数
//所以不能说创建了对象
//free 不会调用析构函数      delete 会调用析构函数
//malloc申请的空间在堆上     new默认申请在堆上
//建议 ： malloc/free  new/delete  new[]/delete[]
//否则： 内存泄漏  程序崩溃

//如果没有匹配使用  代码会有啥后果
//对于内置类型，是否匹配使用没有什么影响
//void TestFunc()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//
//	delete p1;
//
//	int* p2 = (int*)malloc(sizeof(int));
//	delete[] p2;
//
//	int* p3 = new int;
//	free(p3);
//
//	int* p4 = new int;
//	delete[] p4;
//
//	int* p5 = new int[10];
//	free(p5);
//
//	int* p6 = new int[10];
//	delete p6;
//}
//int main()
//{
//	TestFunc();
//	//_CrtDumpMemoryLeaks();//检测是否有内存泄漏
//	return 0;
//}
//class Test
//{
//public:
//	Test()
//	{
//		_ptr = new int;
//	}
//	~Test()
//	{
//		delete _ptr;
//		_ptr = nullptr;
//	}
//private:
//	int* _ptr;
//};
//void TestFunc()
//{
//	//崩溃
//	Test* p1 = (Test*)malloc(sizeof(int));
//	delete p1;
//
//	//崩溃
//	Test* p2 = (Test*)malloc(sizeof(int));
//	delete[] p2;
//
//	//内存泄漏
//	Test* p3 = new Test;
//	free(p3);
//	//_CrtDumpMemoryLeaks();//检测是否有内存泄漏
//
//	//崩溃
//	Test* p4 = new Test;
//	delete[] p4;
//
//	//崩溃  内存也泄漏
//	Test* p5 = new Test[10];
//	free(p5);
//
//	//崩溃+内存泄漏
//	Test* p6 = new Test[10];
//	delete p6;
//}
//int main()
//{
//	TestFunc();
//	return 0;
//}
//class Test
//{
//public:
//	Test()
//	{
//		cout << "Test()" << endl;
//	}
//	~Test()
//	{
//		cout << "~Test():" << this << endl;
//	}
//private:
//	int _data;
//};
//void TestFunc()
//{
//	//没有问题
//	Test* p1 = (Test*)malloc(sizeof(int));
//	delete p1;
//
//	//崩溃
//	Test* p2 = (Test*)malloc(sizeof(int));
//	delete[] p2;
//
//	//不会内存泄漏，因为对象里面没有资源
//	Test* p3 = new Test;
//	free(p3);
//
//	//崩溃
//	Test* p4 = new Test;
//	delete[] p4;
//
//	//崩溃
//	Test* p5 = new Test[10];
//	free(p5);
//
//	//崩溃
//	Test* p6 = new Test[10];
//	delete p6;
//}
//int main()
//{
//	TestFunc();
//	return 0;
//}
//1.类中管理资源
//结论：new+delete必须要匹配使用 new[]+delete[]必须匹配使用
//malloc -> delete  崩溃
//malloc -> delete[] 崩溃
//new -> free 对象的空间释放，对象中的资源没有销毁 资源泄漏
//new -> delete[] 崩溃
//new[] -> free 崩溃
//new -> delete 崩溃
//2.类中没有管理资源
//结论：new+delete必须要匹配使用 new[]+delete[]必须匹配使用
//malloc -> delete  没有问题
//malloc -> delete[] 崩溃
//new -> free  没有问题
//new -> delete[] 崩溃
//new[] -> free 崩溃
//new[] -> delete 崩溃

class Test
{
public:
	Test()
	{
		cout << "Test()" << endl;
	}
	/*~Test()
	{
		cout << "~Test():" << this << endl;
	}*/
private:
	int _data;
};
void TestFunc()
{
	//
	Test* p1 = (Test*)malloc(sizeof(int));
	delete p1;

	//
	Test* p2 = (Test*)malloc(sizeof(int));
	delete[] p2;

	//
	Test* p3 = new Test;
	free(p3);

	//
	Test* p4 = new Test;
	delete[] p4;

	//
	Test* p5 = new Test[10];
	free(p5);

	//
	Test* p6 = new Test[10];
	delete p6;
}
int main()
{
	TestFunc();
	return 0;
}
//new
//1.申请空间
//2.调用构造函数

//int globalVar = 1;
//static int staticGlobalVar = 1;
//void Test()
//{
//	static int staticVar = 1;
//	int localVar = 1;
//	int num1[10] = { 1, 2, 3, 4 };
//	char char2[] = "abcd";
//	char* pChar3 = "abcd";
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
//	free(ptr1);
//	free(ptr3);
//}
//1. 选择题：
//选项 : A.栈 B.堆 C.数据段 D.代码段
//	globalVar在哪里？__C__ staticGlobalVar在哪里？_C___
//	staticVar在哪里？_C___ localVar在哪里？__A__
//	num1 在哪里？_A___
//	char2在哪里？__A__ * char2在哪里？A___
//	pChar3在哪里？_A___ * pChar3在哪里？__D__
//	ptr1在哪里？_A___ * ptr1在哪里？__B__
//	2. 填空题：
//	sizeof(num1) = __40__;
//sizeof(char2) = __5__; strlen(char2) = __4__;
//sizeof(pChar3) = _4___; strlen(pChar3) = _4___;
//sizeof(ptr1) = __4__;