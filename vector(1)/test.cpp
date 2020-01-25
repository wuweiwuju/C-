#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
//int main()
//{
//	vector<int> v1;
//	vector<int> v2(10,5);
//	int array[] = { 1,2,3,4,5,6,7,8,9,0 };
//	vector<int> v3(array,array+sizeof(array)/sizeof(int));
//	vector<int> v4(v3);
//
//	v1 = v2;
//	return 0;
//}
#if 0
int main()
{
	vector<int> v{ 1,2,3,4,5,6,7,8,9,0 };
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;
	//auto it = v.begin();
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	v.resize(20, 9);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.resize(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.resize(10);//内置类型填充是0
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.reserve(10);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.reserve(100);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	return 0;
	
}
#endif
#if 0
//迭代器[ )
#include<string>
int main()
{
	vector<int> v{ 1,2,3,4,5,6,7,8,9,0 };
	cout << v.front() << endl;
	cout << v.back() << endl;

	//++操作：从begin--->end方向移动
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	vector<int>::reverse_iterator it2 = v.rbegin();
	while (it2 != v.rend())
	{
		cout << *it2 << " ";
		++it2;
	}
	cout << endl;

	v.insert(v.begin(), 0);
	cout << v[5] << endl;
	//at 和 operator[]的区别是第一个是抛异常，第二个是断言
	/*cout << v[100] << endl;
	cout << v.at(100) << endl;*/
	v.assign(10, 5);
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	string s("hello");
	vector<char> vv;
	vv.assign(s.begin(), s.end());


	return 0;
}
#endif


#if 0
#include <iostream>
#include <vector>
int main()
{
	size_t sz;
	std::vector<int> foo;
	sz = foo.capacity();
	//foo.reserve(100);
	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i) {
		foo.push_back(i);
		if (sz != foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
	return 0;
}
#endif
#include<algorithm>
//迭代器失效问题
int main()
{
	vector<int> v{ 1,2,3,4,5,6,7,8,9,0 };
	auto it = v.begin();

	v.push_back(1);//这里会扩容

	sort(v.begin(), v.end());
	it = v.begin();//重新赋值解决迭代器失效

	while (it != v.end())//it指向之前的容量所以迭代器失效
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	it = v.begin();
	while (it != v.end())
	{
		it = v.erase(it);
		//it++;
	}
	return 0;
}
//string:
//vector<char>
//分开的原因就是 不同的两种类型，还有就是vector没有'\0'  如果维护的话，它就不能实现其它类型了
//1.构造
//空构造函数
//n个值data元素的构造
//区间构造
//拷贝构造
//2.容量操作
//size() capacity() empty()
//resize(newSize,data):将vector中有效元素个数更新到newSize
//reserve(newCapacity):为vector预留空间，注意：不会改变有效元素的个数
//newCapacity <= oldCapacity ：返回
//newCapacity > oldCapacity: 真正的进行扩容  SGI：
//3.元素访问：
//T& operator[](size_t index) / const T& operator[](size_t index)const;
//at
//T& front() / const T& front()const
//T& back() / const T& back() const
 //4.修改
//5.迭代器 最主要提供给算法来使用的
//让算法可以透明化（不用关心底层的数据结构）的操作数据
//begin()/end()--->[begin,end) 正向迭代器
//rbegin() / rend()--->[rbegin,rend) 反向迭代器
//迭代器失效：
//vector中的迭代器的类型：typedef T* iterator;
//auto it = v.begin(); it实际已经指向vector底层空间的起始位置
//v.push_back(data);
//通过it迭代器访问vector中的元素--->可能会引起代码崩溃
//1.如果底层空间的改变---push_back/insert resize/reserve swap assign
//2.erase(pos)--pos的迭代器失效 pos-->vector中的某个位置-->T类型对象
//解决迭代器失效
//给迭代器重新赋值

// 常见的迭代器失效的场景
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	// 实现删除v中的所有偶数
	// 下面的程序会崩溃掉，如果是偶数，erase导致it失效
	// 对失效的迭代器进行++it，会导致程序崩溃
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			v.erase(it);
			++it;
	}
	// 以上程序要改成下面这样，erase会返回删除位置的下一个位置
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			it = v.erase(it);
		else
			++it;
	}
	return 0;
}