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
//	// ���뵥��Test���͵Ŀռ�
//	Test* p1 = (Test*)malloc(sizeof(Test));
//	free(p1);
//	// ����10��Test���͵Ŀռ�
//	Test* p2 = (Test*)malloc(sizeof(Test) * 10);
//	free(p2);
//}
//void Test2()
//{
//	// ���뵥��Test���͵Ķ���
//	Test* p1 = new Test;
//	delete p1;
//	// ����10��Test���͵Ķ���
//	Test* p2 = new Test[10];
//	delete[] p2;
//}
//void Test()
//{
//	// ��̬����һ��int���͵Ŀռ�
//	int* ptr4 = new int;
//	// ��̬����һ��int���͵Ŀռ䲢��ʼ��Ϊ10
//	int* ptr5 = new int(10);
//	// ��̬����10��int���͵Ŀռ�
//	int* ptr6 = new int[3];
//	delete ptr4;
//	delete ptr5;
//	delete[] ptr6;
//}
//int main()
//{

//}
//malloc���� ���� 
//new/delete->�������� new[]/delete[]->�����ռ�
//malloc / free            new / delete
// C��׼�⺯��              C++�еĲ�����
//void*->ǿת               ����Ҫǿת
// �ֽ���                    new ����
//����ʧ��->NULL->�п�       ����Ҫ�п�
//malloc ������ù��캯��    new ����ù��캯��
//���Բ���˵�����˶���
//free ���������������      delete �������������
//malloc����Ŀռ��ڶ���     newĬ�������ڶ���
//���� �� malloc/free  new/delete  new[]/delete[]
//���� �ڴ�й©  �������

//���û��ƥ��ʹ��  �������ɶ���
//�����������ͣ��Ƿ�ƥ��ʹ��û��ʲôӰ��
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
//	//_CrtDumpMemoryLeaks();//����Ƿ����ڴ�й©
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
//	//����
//	Test* p1 = (Test*)malloc(sizeof(int));
//	delete p1;
//
//	//����
//	Test* p2 = (Test*)malloc(sizeof(int));
//	delete[] p2;
//
//	//�ڴ�й©
//	Test* p3 = new Test;
//	free(p3);
//	//_CrtDumpMemoryLeaks();//����Ƿ����ڴ�й©
//
//	//����
//	Test* p4 = new Test;
//	delete[] p4;
//
//	//����  �ڴ�Ҳй©
//	Test* p5 = new Test[10];
//	free(p5);
//
//	//����+�ڴ�й©
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
//	//û������
//	Test* p1 = (Test*)malloc(sizeof(int));
//	delete p1;
//
//	//����
//	Test* p2 = (Test*)malloc(sizeof(int));
//	delete[] p2;
//
//	//�����ڴ�й©����Ϊ��������û����Դ
//	Test* p3 = new Test;
//	free(p3);
//
//	//����
//	Test* p4 = new Test;
//	delete[] p4;
//
//	//����
//	Test* p5 = new Test[10];
//	free(p5);
//
//	//����
//	Test* p6 = new Test[10];
//	delete p6;
//}
//int main()
//{
//	TestFunc();
//	return 0;
//}
//1.���й�����Դ
//���ۣ�new+delete����Ҫƥ��ʹ�� new[]+delete[]����ƥ��ʹ��
//malloc -> delete  ����
//malloc -> delete[] ����
//new -> free ����Ŀռ��ͷţ������е���Դû������ ��Դй©
//new -> delete[] ����
//new[] -> free ����
//new -> delete ����
//2.����û�й�����Դ
//���ۣ�new+delete����Ҫƥ��ʹ�� new[]+delete[]����ƥ��ʹ��
//malloc -> delete  û������
//malloc -> delete[] ����
//new -> free  û������
//new -> delete[] ����
//new[] -> free ����
//new[] -> delete ����

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
//1.����ռ�
//2.���ù��캯��

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
//1. ѡ���⣺
//ѡ�� : A.ջ B.�� C.���ݶ� D.�����
//	globalVar�����__C__ staticGlobalVar�����_C___
//	staticVar�����_C___ localVar�����__A__
//	num1 �����_A___
//	char2�����__A__ * char2�����A___
//	pChar3�����_A___ * pChar3�����__D__
//	ptr1�����_A___ * ptr1�����__B__
//	2. ����⣺
//	sizeof(num1) = __40__;
//sizeof(char2) = __5__; strlen(char2) = __4__;
//sizeof(pChar3) = _4___; strlen(pChar3) = _4___;
//sizeof(ptr1) = __4__;