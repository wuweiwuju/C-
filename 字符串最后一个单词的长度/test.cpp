#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	cout << s.substr(s.rfind(' ') + 1).size() << endl;
	return 0;
}