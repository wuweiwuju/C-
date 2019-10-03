#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;
//1.通用的加法代码
//函数重载
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
//这样是写不完的
//由此我们引入函数模板

//template<typename T>
////template<class T>
//T Add(T left, T right)
//{
//	cout << typeid(right).name() << endl;//看right的类型
//	return left + right;
//}
//
//
//int main()
//{
//	//隐式的实例化
//	//在编译代码期间，必须推演实参的类型来确定模板参数列表中的T，根据确定的T的结果来生成代码
//	//不会进行隐式的类型转换
//	cout<<Add(1, 2)<<endl;
//	cout << Add(1.2, 2.3) << endl;
//	cout << Add((double)1, 2.0) << endl;
//
//	//显示实例化：明确指定T的类型为double
//	//尝试进行隐式类型转换,如果转换成功生成代码
//	//如果转换失败，就报错
//	cout << Add<double>(1, 2.0) << endl;
//	//Add<double>("hello", 1.2);
//	return 0;
//}
//什么是模板?
//模板分类：函数模板 和 类模板
//在模板中 struct不能用来修饰类型 class可以
//函数模板不是真正的函数，是编译器生成代码的规则。
//函数的实例化
//隐式实例化：没有明确指定类型 Add(1.0,1) 编译器不会进行隐式类型转换
//显示实例化：Add<double>(1.0,1)

//T1 Add(T1 left,T2 right); 这样不好 应该：返回left+right的实际类型
//显示实例化：
//Add<int>(1,2.0)
//int Add<int>(int left,int right)
//{return left+right;}//如果类型不匹配，编译器会尝试进行隐式类型转化
//成功：调用  失败：编译器报错


////函数模板和函数是可以同时存在的，但是调用先调用函数
//template<typename T>
////template<class T>
//T Add(T left, T right)
//{
//	cout << typeid(right).name() << endl;//看right的类型
//	return left + right;
//}
//int Add(int left, int right)
//{
//	return left + right;
//}
//
//int main()
//{
//	Add(1, 2);//调用用户自己写的函数
//	Add(1, 2.0);//调用函数模板
//	Add<>(1, 2); //调用函数模板 隐式类型的实例化
//	return 0;
//}
//// 专门处理int的加法函数
//int Add(int left, int right) {
//	return left + right;
//}
//// 通用加法函数
//template<class T1, class T2>
//T1 Add(T1 left, T2 right) {
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // 与非函数模板类型完全匹配，不需要函数模板实例化
//	Add(1, 2.0); // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
//}
//类模板
//typedef int DataType;
//template<typename T>
//class SeqList//SeqList 不是类型 只是类模板的名字
//	//要定义对象 必须实例化(按照所需操作的类型实例化)
//{
//public:
//	SeqList(size_t capacity = 10)
//		:_array(new T[capacity])
//		, _capacity(capacity)
//		, _size(0)
//	{
//
//	}
//	//拷贝构造函数
//	//赋值运算符的重载
//	//析构函数
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
//	//顺序表不适合头部的插入和删除  时间复杂度都是O(n)
//	T& operator [](size_t index)//下标运算符的重载
//	{
//		assert(index < _size);
//		return _array[index];
//	}
//	const T& operator [](size_t index)const//下标运算符的重载
//	{
//		assert(index < _size);
//		return _array[index];
//	}
//	void CheckCapacity()
//	{
//		if (_size == _capacity)
//		{
//			//申请新空间
//			size_t newCapacity = _capacity * 2;
//			T* temp = new T[newCapacity];
//			//拷贝元素
//			for (size_t i = 0; i < _size; ++i)
//			{
//				temp[i] = _array[i];
//			}
//			//释放旧空间
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
