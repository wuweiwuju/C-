#define _CRT_SECURE_NO_WARNINGS 1
���ӣ�https://www.nowcoder.com/questionTerminal/f72adfe389b84da7a4986bde2a886ec3
		 ��Դ��ţ����

			 /*����֮ǰ50����𰸣����ִ󲿷ֶ��Ǵ���ģ������Լ�����Ŀ����⣬����������˼·��Ŀǰ
			 �һ�û���ҵ�bug����ӭţ���Ǽ�飬����bug���Ҽ����޸ģ�����˼·�ǶԵ�*/
			 /*�����Ǵ�֮ǰ�ļ���������������������һ��Ϊ str1 = cpqejrrgp, str2 = cpqejtrdg,
			 len1 = 9, len2 = 9������������������ַ�������Ϊ str��str��35064�֣���
			 ��һ���������ҵ������ַ������Ӧλ�õĵ�һ������ȵ�λ�ã�����ab �� ce,
			 ��һ�����λ�ò���ȵ�Ϊֵ�����±�Ϊ0�ĵط� a �� c ��һ����str1��str2�е�һ����Բ����
			 ��λ�����±�Ϊ5�ĵط����� r �� t�����±�Ϊk��
			 �ڶ����������ڴ��±괦���ַ������±�λ���ַ�֮����������str[k]>str1[k] && str[k]<str2[k]
			 ��������������㣬ֻҪkλ�ô���str1С��str2��Ӧ��kλ�ã��������һλ�ÿ�������ȡ��ÿ��
			 λ����26�֣�����str1[5]��str2[5]֮�乲��num1�֣���t��-'r'-1=1�ּ�Ϊ's'��һ���������
			 str[5]Ϊs��ʱ�򣬺�����λ��������ȡ������(str2[k] - str1[k] - 1)*pow(26, i - k)�֣�
			 ����iΪlen1��len2֮���ȡֵ��������һ��forѭ���ۼӣ�
			 ���������������str[k]==str1[k]ʱ�ж����֣���ʱ��str[k+1]�����str1[k+1],k+2λ��k+3λ...
			 ��������ȡ����������str[k]==str1[k]&&str[k+1]==str1[k+1]���������str[k+2]����str1[k+2]
			 ��k+3�Լ�֮���λ������ȡ���Դ����ƣ�ֱ���㵽k==len2-1��λ��Ϊֹ;
			 ���Ĳ��������str[k]==str2[k]���������ʱ��str[k+1]��ҪС��str2[k+1],k+2��k+3��֮���
			 λ������ȡ����������str[k]==str2[k]&&str[k+1]==str2[k+1]���������Ҫstr[k+2]С��str2[k+2],
			 �����λ������ȡ���Դ����ƣ�ֱ���㵽k==len2-1��λ��Ϊֹ��
			 ���岽�������������ӣ�ע�⻹�м����߽�λ����Ҫ��������ο����´���
			 */
#include<iostream>
#include<string>
#include<math.h>
			 using namespace std;
		 int main()
		 {
			 string str1, str2;
			 int len1, len2;
			 while (cin >> str1 >> str2 >> len1 >> len2)
			 {
				 if (str1.length() < len2)
					 str1.append(len2 - str1.length(), 'a' - 1);
				 if (str2.length() < len2)
					 str2.append(len2 - str2.length(), 'z' + 1);
				 long long sum = 0;
				 int k = 0;
				 //��һ�����ҵ�һ�����λ�ò���ȵ�λ���±�
				 while (str1[k] == str2[k])
				 {
					 k++;
				 }
				 if (str1[k] < str2[k] && len1 <= len2)
				 {
					 //�ڶ���������str[k]>str1[k] && str[k]<str2[k]�����
					 for (int i = len1 - 1; i < len2; i++)
					 {
						 if (i == k)
						 {
							 if (k == len1 - 1 && k == len2 - 1)
								 sum += str2[k] - str1[k] - 1;
							 else
								 sum += str2[k] - str1[k];
						 }
						 else
							 sum += (str2[k] - str1[k] - 1)*pow(26, i - k);
					 }
					 k++;
					 //������������str[k]==str1[k]ʱ�������str[k]==str2[k]�����
					 for (int i = len1; i <= len2; i++)
					 {
						 for (int j = k; j < i; j++)
							 sum += ('z' - str1[j])*pow(26, i - j - 1);
						 for (int j = k; j < i; j++)
							 sum += (str2[j] - 'a')*pow(26, i - j - 1);
					 }
				 }
				 cout << sum << endl;//������û�ж�1000007ȡģ����Ҳ���ܹ��ģ�ţ���ǿ��������
			 }
			 system("pause");
			 return 0;
		 }