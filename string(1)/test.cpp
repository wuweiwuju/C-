#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
//STL����
//���Խṹ������---����ʽ����
//string: �ַ���
//array: ��̬��˳���------>C++11���˽⣩
//vector: ��̬��˳���
//list: ��ͷ���˫��ѭ������
//forward_list: ��ͷ���ѭ��������----->C++11���˽⣩
//deque: ˫�˶���---��̬�Ķ�ά����
//stack
//queue
//ΪʲôҪѧϰstring��
//string�ķ���
//����
//STL�е����䣺[ )

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

//C������
//char*  const char*
//'\0'
//�����ַ���ϵ�е�str����
//
//int main()
//{
//	const char* p = "hello";
//	//p[0] = 'H';
//	return 0;
//}
//C������������̵ģ�C++����������
//�п���Խ��

//string ������std

//int main()
//{
//	string s1;//����յ��ַ���
//
//	string s2("hello");//��������
//	cout << s2 << endl;
//
//	string s3(10,'a');
//	cout << s3 << endl;
//
//	string s4(s2, 1, 3);
//	cout << s4 << endl;
//
//	string s5(s2);//��������
//
//	cout << s4.size() << endl;
//	cout << s4.length() << endl;
//	cout << s4.capacity() << endl;
//	s4.clear();//�����ЧԪ�أ�����ı�����
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
//	//����
//	s.resize(10, '!');
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//	//����
//	s.resize(13);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//	//����
//	s.resize(20, '*');
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//	//��С  ����ı�������С
//	s.resize(18);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//	//��С
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
//	s.reserve(100);//ֻ�ı�������С
//	cout << s.capacity() << endl;//���ݻ���---�ο�
//
//	s.reserve(50);
//	cout << s.capacity() << endl;//������С ����ı�����
//
//	s[0] = 'H';
//	cout << s << endl;
//	//s[10] = 'W';//Խ��ᱨ�� ��assert���
//	//s.at(10);//������һ��  ������out of range���쳣
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
//	s.assign("world!!!!");//����ԭ����
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

//string�ǳ�Ա����

//
//int main()
//{
//	string s;
//	//cin >> s;//�Կո���Ϊ�ָ���
//	getline(cin,s);//����һ������  �����Կո���Ϊ�ָ���
//	cout << s << endl;
//	return 0;
//}