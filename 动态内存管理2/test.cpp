#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
/*class Test
{
public:
	Test()
	{
		cout << "Test()" << endl;
	}
	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _data;
};
int main()
{
	//Test* pt = new Test;
	//new: 这是一个关键字
	//1.申请空间----->void* operator new(字节数)
	//循环使用malloc(size)申请空间
	//成功直接返回  失败空间不足 空间不足的应对措施(函数)  ---  用户
	//2.调用构造函数
	//delete pt;
	//delete
	//1.先调用析构函数:释放对象中的资源
	//2.释放空间void operator delete(void*)--->free
	Test* pt = new Test[10];
	delete[] pt;
	return 0;
}
//operator new  这是一个函数
//malloc申请空间
//1.成功--->直接返回
//2.失败--->执行用户提供的空间不足的应对措施:
//----------a.用户未提供---抛异常
//----------b.用户提供---执行---继续用malloc申请---到1循环下去---直到申请成功
//new T[N]
//1.申请空间 void* operator new[](字节数)--->void* operator new(字节数)--->malloc
//2.调用N次构造函数
*/

//设计一个类，只能在堆上创建对象
//class HeapOnly
//{
//public:
//	static HeapOnly* GetPbject()
//	{
//		return new HeapOnly;
//	}
//	~HeapOnly()
//	{
//
//	}
//private:
//	HeapOnly()
//	{
//
//	}
//};
//int main()
//{
//	HeapOnly* p = HeapOnly::GetPbject();
//
//	return 0;
//}