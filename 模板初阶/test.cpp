#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;
//1.ͨ�õļӷ�����
//��������
//int Add(int left, int right)
//{
//	return left + right;
//}
//double Add(double left, double right)
//{
//	return left + right;
//}
//short Add(short left, short right)
//{
//	return left + right;
//}
//������д�����
//�ɴ��������뺯��ģ��

//template<typename T>
////template<class T>
//T Add(T left, T right)
//{
//	cout << typeid(right).name() << endl;//��right������
//	return left + right;
//}
//
//
//int main()
//{
//	//��ʽ��ʵ����
//	//�ڱ�������ڼ䣬��������ʵ�ε�������ȷ��ģ������б��е�T������ȷ����T�Ľ�������ɴ���
//	//���������ʽ������ת��
//	cout<<Add(1, 2)<<endl;
//	cout << Add(1.2, 2.3) << endl;
//	cout << Add((double)1, 2.0) << endl;
//
//	//��ʾʵ��������ȷָ��T������Ϊdouble
//	//���Խ�����ʽ����ת��,���ת���ɹ����ɴ���
//	//���ת��ʧ�ܣ��ͱ���
//	cout << Add<double>(1, 2.0) << endl;
//	//Add<double>("hello", 1.2);
//	return 0;
//}
//ʲô��ģ��?
//ģ����ࣺ����ģ�� �� ��ģ��
//��ģ���� struct���������������� class����
//����ģ�岻�������ĺ������Ǳ��������ɴ���Ĺ���
//������ʵ����
//��ʽʵ������û����ȷָ������ Add(1.0,1) ���������������ʽ����ת��
//��ʾʵ������Add<double>(1.0,1)

//T1 Add(T1 left,T2 right); �������� Ӧ�ã�����left+right��ʵ������
//��ʾʵ������
//Add<int>(1,2.0)
//int Add<int>(int left,int right)
//{return left+right;}//������Ͳ�ƥ�䣬�������᳢�Խ�����ʽ����ת��
//�ɹ�������  ʧ�ܣ�����������


////����ģ��ͺ����ǿ���ͬʱ���ڵģ����ǵ����ȵ��ú���
//template<typename T>
////template<class T>
//T Add(T left, T right)
//{
//	cout << typeid(right).name() << endl;//��right������
//	return left + right;
//}
//int Add(int left, int right)
//{
//	return left + right;
//}
//
//int main()
//{
//	Add(1, 2);//�����û��Լ�д�ĺ���
//	Add(1, 2.0);//���ú���ģ��
//	Add<>(1, 2); //���ú���ģ�� ��ʽ���͵�ʵ����
//	return 0;
//}
//// ר�Ŵ���int�ļӷ�����
//int Add(int left, int right) {
//	return left + right;
//}
//// ͨ�üӷ�����
//template<class T1, class T2>
//T1 Add(T1 left, T2 right) {
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // ��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
//	Add(1, 2.0); // ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����
//}
//��ģ��
//typedef int DataType;
//template<typename T>
//class SeqList//SeqList �������� ֻ����ģ�������
//	//Ҫ������� ����ʵ����(�����������������ʵ����)
//{
//public:
//	SeqList(size_t capacity = 10)
//		:_array(new T[capacity])
//		, _capacity(capacity)
//		, _size(0)
//	{
//
//	}
//	//�������캯��
//	//��ֵ�����������
//	//��������
//	~SeqList()
//	{
//		if (_array)
//		{
//			delete[] _array;
//			_array = nullptr;
//			_capacity = _size = 0;
//		}
//	}
//	void PushBack(const T& data);
//	void PopBack();
//	//˳����ʺ�ͷ���Ĳ����ɾ��  ʱ�临�Ӷȶ���O(n)
//	T& operator [](size_t index)//�±������������
//	{
//		assert(index < _size);
//		return _array[index];
//	}
//	const T& operator [](size_t index)const//�±������������
//	{
//		assert(index < _size);
//		return _array[index];
//	}
//	void CheckCapacity()
//	{
//		if (_size == _capacity)
//		{
//			//�����¿ռ�
//			size_t newCapacity = _capacity * 2;
//			T* temp = new T[newCapacity];
//			//����Ԫ��
//			for (size_t i = 0; i < _size; ++i)
//			{
//				temp[i] = _array[i];
//			}
//			//�ͷžɿռ�
//			delete[] _array;
//			_array = temp;
//			_capacity = newCapacity;
//		}
//	}
//	size_t Size()const
//	{
//		return _size;
//	}
//private:
//	T* _array;
//	size_t _capacity;
//	size_t _size;
//};
//
//template<class T>
//void SeqList<T>::PushBack(const T& data)
//{
//	CheckCapacity();
//	_array[_size++] = data;
//}
//
//template<class T>
//void SeqList<T>::PopBack()
//{
//	--_size;
//}
//
//int main()
//{
//	SeqList<int> s1;
//	s1.PushBack(1);
//	s1.PushBack(2);
//	s1.PushBack(3);
//	s1.PushBack(4);
//	s1.PushBack(5);
//	s1.PushBack(6);
//	s1.PushBack(7);
//	cout << s1.Size() << endl;
//	cout << s1[5] << endl;
//	s1[5] = 50;
//	s1.PopBack();
//	cout << s1.Size() << endl;
//	SeqList<double> s2;
//	s2.PushBack(1.0);
//	return 0;
//}
