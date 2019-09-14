#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//类中共创建了多少个对象?
class Test
{
public:
	Test()
		:_count(0)
	{
		_count++;
	}
	Test(Test& t)
	{
		_count++;
	}
	~Test()
	{
		_count--;
	}
private:
	int _b;
	int _count;
};
int main()
{
	Test t1, t2;
	return 0;
}