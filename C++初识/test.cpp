#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;//C++标准库命名空间 
//using std:: 这样也可以用标准库里面的东西
//using std::cout;展开部分
//1.不同作用域可以定义同名变量
//2.就近原则 打印
//3.:: 预作用限定符
//4.C语言函数变量的名称不能是关键字
//namespace bie
//{
//	int printf = 10;
//}
//int main()
//{
//	printf("%d\n", bie::printf);
//	return 0;
//}
//5.using namespace bie 的意思就是把bie展开成全局变量   这样会有冲突的风险，所以一般不这样。
//6.using bie::a;  只展开a
//7.命名空间可以嵌套但是一般不要这样用  也可以在里面定义函数 
//8.cout<<""<<endl;  输出的时候自己识别类型
//9.cin>>"";  
//10.缺省参数  不传参数使用默认值
//11.全缺省参数   半缺省参数
//12.缺省参数不能在声明和定义同时出现  一般是在声明的时候出现定义的时候就不要出现了
//13.缺省参数必须是常量或者全局变量  全局变量初始值一般默认为0
//14.C语言不支持缺省参数
//15.函数重载 C++允许同一作用域两个函数的名字相同  但是同名函数的形参列表（个数或者类型或者顺序）必须不同

//F.h  F.CPP Main.cpp
//16.预处理// 展开头文件 / 宏替换  / 条件编译 / 去掉注释...
// F.i  Main.i

//17.编译 // 检查语法,生成汇编代码 
// F.s   Main.s

//18.汇编 // 汇编代码生成二进制机器码
//目标文件 F.o   Main.o
//符号表 F：0x11122222    main: Ox22222222  一般先找main

//19.链接 // 生成可执行程序
// a.out

//20. call(?)有时会出现链接错误   有声明没有定义
//21.C语言不支持函数重载

//22.Linux修饰规则  3代表字节数
////_Z3Addlr
//int Add(int left, int right)
//{
//	return left + right;
//}
////_Z3Addd
//double Add(double left, double right)
//{
//	return left + right;
//}
//23.extern"C"  这样C就可以调用C++的内容了   但是不能函数重载
//24.引用  引用不是新定义一个变量，而是给已存在变量取了一个别名
//类型& 引用变量名（对象名） = 引用实体；
//void TestRef()
//{
//	int a = 1;
//	int& b = a;
//	printf("%p %p", &a, &b);
//	system("pause");
//}
//int main()
//{
//	TestRef();
//	return 0;
//}
//25.引用特性：必须初始化 / 一个变量可以有多个引用 / 引用只能引用一个实体，而且一旦引用就不能更改
//26.常引用   只能缩小不能放大
//void TestRef()
//{
//	//const int a = 10;
//	//int& b = a;//类型一样不会生成临时变量
//
//	int c = 20;
//	const int& d = c;
//
//	int i = 0;
//	//double& j = i;//不行的原因就是  i会生成一个常量空间(临时变量) 引用的是这个空间 而这个空间是常量不可以修改  因此 加const才可以
//	const double& j = i;
//}
//int main()
//{
//	TestRef();
//}
//27.引用的使用场景
//做参数
//void swap(int& left, int& right)
//{
//	int tmp = left;
//	left = right;
//	right = tmp;
//}
//int main()
//{
//	int left = 4;
//	int right = 5;
//	swap(left,right);
//	system("pause");
//	return 0;
//}
//做返回值
//int& TestRefReturn(int& a)
//{
//	a += 10;
//	return a;//返回会生成一个临时变量 它的生命周期在main中
//}
//int main()
//{
//	int a = 10;
//	int ret = TestRefReturn(a);
//	TestRefReturn(a);
//	cout << ret << endl;
//	system("pause");
//	return 0;
//}
//28.库里面有交换这个函数   一般都是小写 swap()
//29.声明 和 定义 的区别  声明就是告诉有这个东西，但是没有开辟空间 定义就是开了空间
//30.以引用做函数参数和指针做函数参数 会发现引用的效率是非常快的  因为不开辟临时空间
//31.传参一般用引用，出了作用域还在的话用引用做返回值效率更好
//32.引用在概念 语法上 是另一个别名  但实际上它也是用指针的方式实现的    它和指针概念上是不一样的
//33.指针在不同平台所占的字节数不同  一般都是32bit位平台占4个字节
//34.内联函数  inline修饰的函数是内联函数
//1.实现一个宏函数  
#define ADD(a,b) ((a)+(b))
//2.宏优点：没有压栈的开销   缺点：复杂 、不能调试 、 没有类型安全的检查
//3.如何解决? 用 enum、 const、 inline去替代宏。
//inline int Add(int left,int right)
//{
//	return left + right;
//}
//int main()
//{
//	ADD(3, 5);
//	return 0;
//}
//35.inline是空间换时间的做法，省去调用函数额外开销
//36.内联对于编译器而言只是一个建议  递归/循环 编译器会省略内联函数
//37.内联函数定义和声明一般不要分开  否则会找不到函数的地址  会导致链接错误
//38.auto关键字（C++11）
//auto 是自动推导类型
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//}
//auto不能做形参类型
//auto不能用来声明数组
//39.基于范围for的循环
//for循环迭代的范围必须是确定的
//int main()
//{
//	int array[] = { 1,2,3,4,5 };
//	//C++11支持   语法糖
//	for (auto& e : array)
//		e *= 2;
//	for (auto e : array)
//		cout << e << endl;
//}
//40.指针空值nullptr(C++11)
//NULL 0 '\0' "\0" '0'有啥区别?  在数值上是一样的 第一个和第二个类型是int 第三四个是类型char第三四个没啥区别 第五个是字符0内存存储是48
