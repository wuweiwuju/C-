#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//���й������˶��ٸ�����?
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