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
