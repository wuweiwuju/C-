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
	//new: ����һ���ؼ���
	//1.����ռ�----->void* operator new(�ֽ���)
	//ѭ��ʹ��malloc(size)����ռ�
	//�ɹ�ֱ�ӷ���  ʧ�ܿռ䲻�� �ռ䲻���Ӧ�Դ�ʩ(����)  ---  �û�
	//2.���ù��캯��
	//delete pt;
	//delete
	//1.�ȵ�����������:�ͷŶ����е���Դ
	//2.�ͷſռ�void operator delete(void*)--->free
	Test* pt = new Test[10];
	delete[] pt;
	return 0;
}
//operator new  ����һ������
//malloc����ռ�
//1.�ɹ�--->ֱ�ӷ���
//2.ʧ��--->ִ���û��ṩ�Ŀռ䲻���Ӧ�Դ�ʩ:
//----------a.�û�δ�ṩ---���쳣
//----------b.�û��ṩ---ִ��---������malloc����---��1ѭ����ȥ---ֱ������ɹ�
//new T[N]
//1.����ռ� void* operator new[](�ֽ���)--->void* operator new(�ֽ���)--->malloc
//2.����N�ι��캯��
*/

//���һ���ֻ࣬���ڶ��ϴ�������
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