#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;
//1.���6��Ĭ�Ϻ���
//2.���캯�� ��ɶ���ĳ�ʼ��
//��������������ͬ
//��������
//�Զ�����
//�޷���ֵ
//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time()" << endl;
//		_hour = _minute = _second = 0;
//	}
//private:
//	int  _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//public:
//	//void Init(int year, int month, int day)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//	void Display()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	//������   ��������������ͬʱ����
//	//Date()//��һ��
//	//{
//	//	cout << "cout" << endl;
//	//	_year = 2018;
//	//	_month = 1;
//	//	_day = 1;
//	//}
//	//Date(int year,int month,int day)//�ڶ���  ��õķ�ʽ
//	//{
//	//	_day = day;
//	//	_month = month;
//	//	_year = year;
//	//}
//private:
//	//1.��������/��������   �����ʼ��
//	int _year;
//	int _month;
//	int _day;
//
//	//2.�Զ�������  Ĭ�Ϲ��캯�����ʼ��  
//	Time _t;
//};
//int main()
//{
//	Date d1;
//	//d1.Init(2018, 5, 1);
//	d1.Display();
//
//
//	//d2.Init(2018, 7, 1);
//	//Date d2(2018, 6, 6);
//	//d2.Display();
//	return 0;
//}
//3.�޲εĹ��캯��  / ȫȱʡ�Ĺ��캯�� / ûд��Ĭ�Ϲ��캯�� ��������Ϊ��Ĭ�Ϲ��캯��  ���� Ĭ�Ϲ��캯��ֻ����һ��
//4.��������   ���һЩ��Դ������   
//�޲��� �޷���ֵ
//�Զ�����
//����ֻ��һ��
//����ǰ���ַ� ~
//5.�ȹ���ĺ�����
typedef int DataType;
class SeqList
{
public:
	SeqList(int capacity = 10)
	{
		//��ʼ��
		_pData = (DataType*)malloc(capacity * sizeof(DataType));
		assert(_pData);
		_size = 0;
		_capacity = capacity;
	}
	~SeqList()
	{
		//����
		if (_pData)
		{
			free(_pData); // �ͷŶ��ϵĿռ�
			_pData = nullptr; // ��ָ����Ϊ��
			_capacity = 0;
			_size = 0;
		}
	}
private:
	int* _pData;
	size_t _size;
	size_t _capacity;
};
int main()
{
	SeqList s1;
	return 0;
}