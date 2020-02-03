#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Solution {
public:
	string toLowerCase(string str) {
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] |= 32;
		}
		return str;
	}
};
int main()
{

}