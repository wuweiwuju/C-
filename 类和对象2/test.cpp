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
//typedef int DataType;
//class SeqList
//{
//public:
//	SeqList(int capacity = 10)
//	{
//		//��ʼ��
//		_pData = (DataType*)malloc(capacity * sizeof(DataType));
//		assert(_pData);
//		_size = 0;
//		_capacity = capacity;
//	}
//	~SeqList()
//	{
//		//����
//		if (_pData)
//		{
//			free(_pData); // �ͷŶ��ϵĿռ�
//			_pData = nullptr; // ��ָ����Ϊ��
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	int* _pData;
//	size_t _size;
//	size_t _capacity;
//};
//int main()
//{
//	SeqList s1;
//	return 0;
//}
//6.�������캯��
//����ֻ��һ��
//�ǹ��캯����������ʽ
//Ĭ�ϵĿ������ǳ�Ϊֵ��������ǳ����
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	} 
//	Date(const Date& d)//�������ô���  const  �Ƿ�ֹ���������ͬʱ�޸���ԭ����
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2018,9,10);
//	d1.Print();
//
//	Date d2(d1);//��������
//	d2.Print();
//
//	return 0;
//}
//����ſ��Խ������������������⣬֮����ѧϰ
//class String
//{
//public:
//	String(const char* str = "jack")
//	{
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//	~String()
//	{
//		cout << "~String()" << endl;
//		free(_str);
//	}
//private:
//	char* _str;
//};
//int main()
//{
//	String s1("hello");
//	String s2(s1);//�����ͷ�����
//}
//7.�����������
// ȫ�ֵ�operator==
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	bool operator==(const Date& d) //�и�������thisָ�� ָ����ǵ�һ��d1   d2��������d
//	{
//		return (_year == d._year)
//			&& (_month == d._month)
//			&& (_day == d._day);
//	}
//	Date& operator=(const Date& d)//
//	{
//		if (this != &d)//��ֹ�Լ����Լ���ֵ
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;//�����������������÷���
//	}
//	/*bool operator<(const Date& d1, const Date& d2) {
//		return (d1._year < d2._year)
//			|| (d1._year == d2._year && d1._month < d2._month)
//			|| (d1._year == d2._year && d1._month == d2._month && d1._day < d2._day);
//	}*/
//private:
//	int _year;
//	int _month;
//	int _day;
//};
// ����ᷢ����������س�ȫ�ֵľ���Ҫ��Ա�����ǹ��еģ���ô�������ˣ���װ����α�֤��
// ������ʵ���������Ǻ���ѧϰ����Ԫ��������߸ɴ����سɳ�Ա������
//bool operator==(const Date& d1, const Date& d2) {
//	return (d1._year == d2._year)
//	&& (d1._month == d2._month)
//		&& (d1._day == d2._day);
//}
//bool operator<(const Date& d1, const Date& d2) {
//	return (d1._year < d2._year)
//		|| (d1._year == d2._year && d1._month < d2._month)
//		|| (d1._year == d2._year && d1._month == d2._month && d1._day < d2._day);
//}
//int main()
//{
//	Date d1(2018, 9, 26);
//	Date d2(2018, 9, 27);
//	cout << (d1 == d2) << endl;
//	d1 = d2;
//	cout << (d1 == d2) << endl;
//	//cout << (d1 < d2) << endl;
//}
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	// bool operator==(Date* this, const Date& d2)
//	// ������Ҫע����ǣ����������thisָ��ĵ��ú����Ķ���
//	bool operator==(const Date& d2)
//	{
//		return _year == d2._year
//			&& _month == d2._month
//			&& _day == d2._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void Test()
//{
//	Date d1(2018, 9, 26);
//	Date d2(2018, 9, 27);
//	cout << (d1 == d2) << endl;
//}