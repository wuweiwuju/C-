#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//#include<string.h>
//class Student
//{
//public:
//	void SetStudentInfo(const char* name, const char* gender, int age)
//	{
//		strcpy(_name, name);
//		strcpy(_gender, gender);
//		_age = age;
//	}
//	void PrintStudentInfo()
//	{
//		cout << _name << " " << _gender << " " << _age << endl;
//	}
//	char _name[20];
/*	char _gender[3];
	int _age;
};
int main()
{
	Student s;
	s.SetStudentInfo("Peper", "��",19);
	s.PrintStudentInfo();
	return 0;
}*/
//1.nullptr �� ������ nullptr_t    Ҳ����int*
//2.NULL ������  int 
//3.auto���µ�����ָʾ��
//4.offsetof(A,a) �������ṹ��ƫ����
//ת�����忴���ģ��ʵ�ֺ�  offsetof
//class Student
//{
//public:
//	void InitStudent(/*Student* const this ,*/ int age)
//	{
//		this->_age = age;
//	}
//	void PrintStudent(/*Student* const this*/)
//	{
//		//this: Student*  const
//		cout <<this-> _age << endl;
//	}
//private:
//	int _name[20];
//	int _age;
//	char _gender[3];
//};
//int main()
//{
//	Student d1;
//	Student::InitStudent(&d1,10);
//	Student::PrintStudent(&d1);
//}
class Date
{
	//���治�ܷ����޶���������
public:
	void Display()
	{
			cout << this->_year << "-" << _month << "-" << _day << endl;
	}
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year; // ��
	int _month; // ��
	int _day; // ��
};
int main()
{
	Date d1, d2;
	d1.SetDate(2018, 5, 1);
	d2.SetDate(2018, 7, 1);
	d1.Display();
	d2.Display();

	Date* p = &d1;
	p->Display();

	Date* ps = nullptr;//
	ps->Display();
	return 0;
}
//5.this �ǲ��ܸ��ĵ� 
//6.thisָ�������?
//���ʴ���ջ��  ��Ϊ��Ҳ��һ���β�   ����ʱ�����������ecx�Ĵ���
//��ʵ�����������ɳ���ʱ�����˻�ȡ�����׵�ַ����ش��롣���ѻ�ȡ���׵�ַ������˼Ĵ���ECX��(VC++�������Ƿ���ECX�У������������п��ܲ�ͬ)��Ҳ���ǳ�Ա���������������������Ǵ����ջ�С���thisָ��������Ǵ���ڼĴ����С���ľ�̬��Ա������Ϊû��thisָ�����������������ľ�̬��Ա����Ҳ���޷�������ķǾ�̬��Ա������

//7.thisָ�����Ϊ����
//����Ϊ�գ��������ڵ��ú�����ʱ����������ڲ�������Ҫʹ�õ�this, Ҳ���ǲ���Ҫͨ��thisָ��ǰ���󲢶�����в���ʱ�ſ���Ϊ��(������������ʲô�����Ż�������������ӡһ���ַ���)��������õĺ�����Ҫָ��ǰ���󣬲����в�������ᷢ�����󣨿�ָ�����ã��͸�C��һ�����ܽ��п�ָ�������
