#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//逆置字符串
//int main()
//{
//	string s("hello world");
//	//reverse(s.begin(), s.end());
//	char* begin = (char*)s.c_str();
//	char* end = begin + s.size() - 1;
//	while (begin < end)
//	{
//		swap(*begin, *end);
//		begin++;
//		end--;
//	}
//	cout << s << endl;
//	return 0;
//}
//第一个出现一次的字符
//int main()
//{
//	string s("eetcode");
//	int count[256] = { 0 };
//	//统计每个字符出现的次数
//	for (int i = 0; i < s.size(); ++i)
//	{
//		count[s[i]]++;
//	}
//	//从前往后依次遍历字符串，如果那个字符出现的次数为1，找到
//	for (int i = 0; i < s.size(); ++i)
//	{
//		if (1 == count[s[i]])
//		{
//			cout << i << endl;
//			return i;
//		}
//	}
//	return -1;
//}
//字符串最后一个单词的长度
//一行
int main()
{
	string str;
	//多行
	while (getline(cin, str))
	{
		cout << str.substr(str.rfind(' ') + 1).size() << endl;
	}
	return 0;
}