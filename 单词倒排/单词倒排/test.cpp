#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		stack<string> arr;
		string temp;
		for (int i = 0; i < str.size(); ++i)
		{
			while (i < str.size() && str[i] >= 'a' && str[i] <= 'z' ||
				str[i] >= 'A' && str[i] <= 'Z')
			{
				temp.push_back(str[i]);
				++i;
			}
			if (temp.size() != 0)
			{
				arr.push(temp);
				temp.clear();
			}
		}
		int i = 0;
		int max = arr.size();
		for (i = 0; i < max - 1; ++i)
		{
			cout << arr.top() << " ";
			arr.pop();
		}

		cout << arr.top() << endl;
		arr.pop();
	}
	return 0;
}