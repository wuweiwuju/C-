#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//�����ַ���
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
//��һ������һ�ε��ַ�
//int main()
//{
//	string s("eetcode");
//	int count[256] = { 0 };
//	//ͳ��ÿ���ַ����ֵĴ���
//	for (int i = 0; i < s.size(); ++i)
//	{
//		count[s[i]]++;
//	}
//	//��ǰ�������α����ַ���������Ǹ��ַ����ֵĴ���Ϊ1���ҵ�
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
//�ַ������һ�����ʵĳ���
//һ��
int main()
{
	string str;
	//����
	while (getline(cin, str))
	{
		cout << str.substr(str.rfind(' ') + 1).size() << endl;
	}
	return 0;
}