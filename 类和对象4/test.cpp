#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//���й������˶��ٸ�����?
//�����ı���----���ܰ�����ÿ�������У�Ӧ�������ж�����
//1.ʹ��ȫ�ֱ���--->�ǿ���ʵ�ֵ�->ȱ�ݣ�����ȫ
//int g_count = 0;
//��ͨ��Ա������   �����ٳ�ʼ���б��н��г�ʼ��       ÿ�����󶼰���    ����ͨ���������
//static��Ա������ �������ٳ�ʼ���б��н��г�ʼ��     ֻ��һ�ݣ�û�а����ھ���Ķ����У������ж������  ����ͨ������ֱ�ӷ���/Ҳ����ͨ��������������ֱ�ӷ���
//class Test
//{
//public:
//	Test()
//		: _b(0)
//	{
//		g_count++;
//	}
//	Test(Test& t)
//	{
//		g_count++;
//	}
//	static int GetCount()
//	{
//		return g_count;
//	}
//	~Test()
//	{
//		g_count--;
//	}
//private:
//	int _b;
////public:
//	//����
//	static int g_count;//�ܷ���һ������ĳ�Ա����
//};
//int Test::g_count = 0; //���ٿռ�
//void TestCount()
//{
//	Test t1, t2;
//	cout << Test::GetCount() << endl;
//}
//int main()
//{
//	cout << Test::GetCount() << endl;
//	Test t1, t2;
//	cout << Test::GetCount() << endl;
//	TestCount();
//	//cout << &t1.g_count << "=" << &t2.g_count << endl;
//	//cout <<Test:: g_count << endl;
//	////��ɶ����
//
//
//	//int a = 10;
//	//a = t1.g_count;
//	//a = Test::g_count;
//	//ͨ������෢��  ����ûɶ����  ֻ�ǰѵ�һ��ת���ɵڶ��ַ�ʽ���ʵ�
//	cout << Test::GetCount() << endl;
//	return 0;
//}
//1.��̬��Ա����һ��Ҫ��������г�ʼ��
//����ͨ��Ա��ȫ
//��̬��Ա���� �� ��ͨ��Ա������ɶ����?
//class Test
//{
//public:
//	Test()
//		: _b(0)
//	{
//		g_count++;
//	}
//	Test(Test& t)
//		: _b(0)
//	{
//		g_count++;
//	}
//	//��ͨ��Ա����  ��һ�����ص�thisָ��
//	//��ͨ��Ա��������ͨ��thisָ�����
//	//���Է�����ͨ��Ա����
//	int GetB()
//	{
//		cout << this << endl;
//		return _b;
//	}
//	//��̬��Ա����  û��thisָ��
//	//���ܷ�����ͨ�ĳ�Ա����
//	static int GetCount()
//	{
//		//cout << this << endl;
//
//		//cout << _b << endl;
//		return g_count;
//	}
//	~Test()
//	{
//		g_count--;
//	}
//private:
//	int _b;
//	//�൱�������ж���һ��������޹ص�ȫ�ֱ���--�����
//	static int g_count;//�ܷ���һ������ĳ�Ա����
//};
//int Test::g_count = 0; //���ٿռ�
//void TestCount()
//{
//	Test t1, t2;
//	cout << Test::GetCount() << endl;
//}
//int main()
//{
//	Test t;
//	t.GetB();
//
//	Test::GetCount();//���Բ�ͨ��������ã�����û��thisָ��
//	return 0;
//}
//��̬��Ա�������������ݶ�
//�����ʱ���ü�static�ؼ���
//1. ��̬��Ա�������Ե��÷Ǿ�̬��Ա������
//������
//2. �Ǿ�̬��Ա�������Ե�����ľ�̬��Ա������
//����
//class Date
//{
//public:
//	//��Ԫ����
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date(int,int,int):" << this << endl;
//	}
//	void PrintDate()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	//void operator<<(ostream& _cout)
//	//{
//	//	cout << _year << "-" << _month << "-" << _day << endl;
//	//}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////����
////1.�������� �� ����һһ��Ϊostream&,���������������
////2.������ostream&�ķ���ֵ��֧���������
////3.������ʽ�����������绻��
////4.���ú�����Ϊ�����Ԫ����
//ostream& operator<<(ostream& _cout,const Date& d)
//{
//	//_cout<<d.GetYear()<<"-"<<d.GetMonth()<<"-"d.GetDay();
//	cout << d._year << "-" << d._month << "-" << d._day;
//	return _cout;
//}
//int main()
//{
//	Date d(2019, 3, 24);
//	d.PrintDate();
//	cout << 10 << endl;//cout<<10   cout<<endl;
//	cout << d << endl;
//	//cout << d;
//	//d.operator<<(cout);
//	//d << cout;
//	return 0;
//}
//https://www.zhihu.com/question/274746738
//1.��Ԫ�������ŵ㣺��ߴ����Ч��
//ȱ�㣺�ƻ��˷�װ��
//�������������
//2.istream&

//��Ԫ����������ĳ�Ա���������ܷ����޶�������
//��Ԫ����������const����

//3.��Ԫ��
//class Time 
//{
//	friend class Date;
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		:_hour(hour)
//		,_minute(minute)
//		,_second(second)
//	{
//		cout << this->_hour << endl;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date(int,int,int):" << this << endl;
//	}
//	void PrintDate()
//	{
//		cout << _year << "-" << _month << "-" << _day << _t._hour<<endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//int main()
//{
//	return 0;
//}
//��Ԫ��ϵ�ǵ���ģ����ܽ���
//��Ԫ��ϵ���ܴ���

//һ������η�ֹ������ ?
