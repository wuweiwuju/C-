#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
//int isValidchar(char s)
//{
//	if ((s <= 'z' && s >= 'a') ||
//		(s <= 'Z' && s >= 'A') ||
//		(s <= '9' && s >= '0'))
//		return 1;
//	return 0;
//}
//int main()
//{
//	string s;
//	getline(cin, s);
//	if (s.empty())
//		return 0;
//	int left = 0;
//	int right = s.size() - 1;
//	while (left < right)
//	{
//		//��ǰ������һ����Ч�ַ�
//		while (left < right)
//		{
//			if (isValidchar(s[left]))
//				break;
//			left++;
//		}
//		//�Ӻ���ǰ��һ����Ч�ַ�
//		while (left < right)
//		{
//			if (isValidchar(s[right]))
//				break;
//			right--;
//		}
//		if(left < right)
//		{
//			if (s[left] == s[right])
//				return true;
//			if ((s[left] + 32) % 32 != ((s[right])+32) % 32)
//				return false;
//		}
//		++left;
//		--right;
//}

//int main()
//{
//	/*int a = -3 % 5;
//	int b = 3 % 5;
//	cout << a <<" "<<b << endl;*/
//}

//int main()
//{
//	string num1;
//	string num2;
//	int LSize = num1.size();
//	int RSize = num2.size();
//	if (LSize < RSize)
//	{
//		num1.swap(num2);
//		swap(LSize, RSize);
//	}
//	string strRet(LSize + 1, '0');
//	char step = 0;
//	//��num1���ַ�������Ϊѭ��������
//	for (int idxL = LSize - 1, idxR = RSize - 1; idxL >= 0; --idxL, --idxR)
//	{
//		char cRet = num1[idxL] - '0' + step;
//		if (idxR >= 0)
//		{
//			cRet += num2[idxR] - '0';
//		}
//		step = 0;
//		if (cRet >= 10)
//		{
//			step = 1;
//			cRet -= 10;
//		}
//		strRet[idxL + 1] += cRet;
//	}
//	if (1 == step)
//		strRet[0] += 1;
//	else
//		//strRet.erase(strRet.begin());
//		strRet.erase(0,1);
//	return 0;
//}

