#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
//STL初阶
//线性结构的容器---序列式容器
//string: 字符串
//array: 静态的顺序表------>C++11（了解）
//vector: 动态的顺序表
//list: 带头结点双向循环链表
//forward_list: 带头结点循环单链表----->C++11（了解）
//deque: 双端队列---动态的二维数组
//stack
//queue
//为什么要学习string类
//string的方法
//构造
//STL中的区间：[ )

//int main()
//{
//	string s1;
//
//	string s2("hello");
//	cout << s2 << endl;
//
//	string s3(10,'a');
//	cout << s3 << endl;
//
//	string s4(s2, 1, 3);
//	cout << s4 << endl;
//	return 0;
//}

//C语言中
//char*  const char*
//'\0'
//操作字符串系列的str函数
//
//int main()
//{
//	const char* p = "hello";
//	//p[0] = 'H';
//	return 0;
//}
//C语言是面向过程的，C++是面向对象的
//有可能越界

//string 定义在std

//int main()
//{
//	string s1;//构造空的字符串
//
//	string s2("hello");//拷贝构造
//	cout << s2 << endl;
//
//	string s3(10,'a');
//	cout << s3 << endl;
//
//	string s4(s2, 1, 3);
//	cout << s4 << endl;
//
//	string s5(s2);//拷贝构造
//
//	cout << s4.size() << endl;
//	cout << s4.length() << endl;
//	cout << s4.capacity() << endl;
//	s4.clear();//清空有效元素，不会改变容量
//	cout << s4.size() << endl;
//	cout << s4.capacity() << endl;
//
//	return 0;
//}

//

//resize(n,c)
//int main()
//{
//	string s("hello");
//	cout << s.size()<< endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//	//增大
//	s.resize(10, '!');
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//	//增大
//	s.resize(13);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//	//增大
//	s.resize(20, '*');
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//	//缩小  不会改变容量大小
//	s.resize(18);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//	//缩小
//	s.resize(13);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//	return 0;
//}

//int main()
//{
//	string s("hello");
//	cout << s.capacity() << endl;
//	s.reserve(100);//只改变容量大小
//	cout << s.capacity() << endl;//增容机制---参考
//
//	s.reserve(50);
//	cout << s.capacity() << endl;//容量缩小 不会改变容量
//
//	s[0] = 'H';
//	cout << s << endl;
//	//s[10] = 'W';//越界会报错 用assert检测
//	//s.at(10);//其它都一样  但是用out of range报异常
//	return 0;
//}
//

//int main()
//{
//	string s1("hello");
//	s1 += ' ';
//	s1 += "world";
//	cout << s1 << endl;
//
//	string s2("!!!");
//	s1 += s2;
//	cout << s1 << endl;
//	return 0;
//}
//void TestPushBack()
//{
//	string s;
//	size_t sz = s.capacity();
//	s.reserve(100);
//	cout << "making s grow:\n";
//	for (int i = 0; i < 100; i++)
//	{
//		//s += 'c';
//		s.push_back('c');
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//}
//int main()
//{
//	TestPushBack();
//	return 0;
//}

//int main()
//{
//	string s("hello");
//	s.assign("world!!!!");//重置原内容
//	cout << s << endl;
//	string s1 = s.substr(0, 5);
//	cout << s1 << endl;
//	return 0;
//}

//int main()
//{
//	string s("20190331Test.cpp");
//	string strFilePostFix;
//	size_t pos = s.rfind('.');
//	strFilePostFix = s.substr(pos,s.size()-pos);
//	cout << strFilePostFix << endl;
//	return 0;
//}

//int main()
//{
//	string url("http://www.cplusplus.com/reference/string/string/find/");
//	size_t pos = url.find("://")+3;
//	string str = url.substr(pos, url.find('/', pos) - pos);
//	cout << str << endl;
//	return 0;
//}

//string非成员函数

//
//int main()
//{
//	string s;
//	//cin >> s;//以空格作为分隔符
//	getline(cin,s);//输入一行内容  不是以空格作为分隔符
//	cout << s << endl;
//	return 0;
//}