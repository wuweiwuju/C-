#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//class Data
//{
//	public:
//		void Print()
//		{
//			cout << _year << "-" << _month << "-" << _day << endl;
//		}
//		//void Init(int year = 2000, int month = 2, int day = 2)
//		//{
//		//	_year = year;
//		//	_month = month;
//		//	_day = day;
//		//}
//	private:
//		int _year;
//		int _month;
//		int _day;
//};
//int main()
//{
//	Data d1;
//	/*d1.Init(2018, 11, 10);*/
//	d1.Print();
//
//	Data d2;
//	d2.Print();
//	/*d2.Init(2018, 11, 10);*/
//
//	Data d3;
//	/*d3.Init();*/
//	d3.Print();
//
//	return 0;
//}
//���캯��(�����幹�캯������������Ĭ��һ���޲εĹ��캯��)
//class Time
//{
//public:
//	Time(int hour = 0)
//	{
//		cout << "Time()" << endl;
//		_hour = _minute = _second = 0;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//public:
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	//���캯����1.�޷���ֵ 2.��������������ͬ 3.����ʵ������ʱ��������Զ����ù��캯�� 4.�����������أ�
//	//��ɶ���ĳ�ʼ��
//	//Date()
//	//{
//	//	_year = 2018;
//	//    _month = 1;
//	//    _day = 1;
//	//}
//	Date(int year = 2010,int month = 2,int day = 2)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	//1.�������� ���� ��������
//	int _year;
//	int _month;
//	int _day;
//	//2.�Զ�������
//	Time _t;
//};
//int main()
//{
//	Date d1;//����d1����
//	d1.Print();
//
//	Date d2(2018, 11, 10);
//	d2.Print();
//
//	return 0;
//}
// ���ǿ�������������ǲ��Ǻܽ�Ӳ��
//class Date
//{
//public:
//	Date(int year)
//	{
//		 �����year�����ǳ�Ա���������Ǻ����βΣ�
//		_year = year;
//	}
//private:
//	int _year;
//};
//int main()
//{
//	Date d1(10);
//}
//��������
//class Date
//{
//public:
//	//���
//	Date(int year = 2018,int month = 2,int day = 2)
//	{
//		// ��ʼ��
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	
//	//~Date()
//	//{
//	//	//����
//	//	cout << "~Date" << endl;
//	//}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	//1.�������� ���� ��������
//	int _year;
//	int _month;
//	int _day;
//};
//class SeqList
//{
//public:
//	SeqList(size_t capacity = 10)
//	{
//		_a = (int*)malloc(capacity * sizeof(int));
//		_size = 0;
//		_capacity = capacity;
//	}
//	~SeqList()
//	{
//		free(_a);
//		_a = nullptr;
//		_size = _capacity = 0;
//	}
//private:
//	int* _a;
//	size_t _size;
//	size_t _capacity;
//};
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
//class Person
//{
//private:
//	String _name;
//	int _age;
//};
//int main()
//{
//	Date d1;
//	d1.Print();
//	
//	Date d2(2018, 11, 10);
//	d2.Print();
//
//	SeqList s1;
//
//	Person p;
//
//	return 0;
//}

//�������캯��
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//d2(d1)  �������캯��һ���ǵ�������
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	d1.Print();
//
//	Date d2(d1);//��������
//	d2.Print();
//
//	return 0;
//}
// ����ᷢ������ĳ������������������Ҫ�����Ժ󽲵����ȥ�����
//ǳ���� ֵ����
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
//	//���ͷ��������Ի��������� �ڴ�ֻ���ͷ�һ��
//	String s1("hello");
//	String s2(s1);
//}
//��ֵ���������
//���������
// ȫ�ֵ�operator==
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	// d1 == d2
	bool operator==(const Date& d)
	{
		return _year == d._year &&
			_month == d._month &&
			_day == d._day;
	}
	/*Date(const Date& d)
	{
		cout << "Date(const Date& d)" << endl;
	}*/
	//d1 = d2  ��ֵ���������
	//Date& operator=(const Date& d)
	//{
	//	if (this != &d)//d1 = d1 ��ֹ�Լ����Լ���ֵ
	//	{
	//		_year == d._year;
	//		_month == d._month;
	//		_day == d._day;
	//	}
	//	return *this;
	//}
private:
	int _year;
	int _month;
	int _day;
};

//bool operator==(const Date& d1,const Date& d2)
//{
//	return d1._year == d2._year &&
//		d1._month == d2._month &&
//		d1._day == d2._day;
//}
//
//bool operator<(const Date& d1, const Date& d2)
//{
//	return (d1._year < d2._year) ||
//		(d1._year == d2._year &&d1._month < d2._month) ||
//		(d1._year == d2._year && d1._month == d2._month && d1._day < d2._day);
//}
int main()
{
	//Date d1, d2;
	//d1.operator==(&d1,d2)
	//cout <<d1.operator==(d2) << endl;
	//cout << (d1 == d2) << endl;
	//cout << operator==(d1, d2) << endl;
	//cout << (d1 == d2) << endl;
	//cout << (d1 < d2) << endl;
	//d1 == d2;
	//d1 < d2;

	Date d1(2018, 11, 10);
	Date d2(2018, 11, 11);

	d1 = d2;
	//cout << d1.operator==(d2) << endl;
	/*d1 = d1;
	Date d3;
	d1 = d2 = d3;*/
}