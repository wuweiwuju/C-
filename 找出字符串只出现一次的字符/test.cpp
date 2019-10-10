#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int firstUniqChar(string s) {
		int con[255] = { 0 };
		//
		for (int i = 0; i < s.size(); ++i)
		{
			con[s[i]]++;
		}
		//
		for (int i = 0; i < s.size(); ++i)
		{
			if (1 == con[s[i]])
				return i;
		}

		return -1;

	}
};
int main()
{
	Solution str;
	string s;
	while (getline(cin, s))
	{
		int ret = str.firstUniqChar(s);
		if (ret == -1)
		{
			cout << ret << endl;
		}
		else
		{
			cout << s[ret] << endl;
		}
	}
	return 0;
}