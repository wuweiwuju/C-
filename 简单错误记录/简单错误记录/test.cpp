#include<iostream>
#include<stack>
#include<string>
#include<unordered_map>
using namespace std;

int main()
{
	string str;
	stack<string> arr1;
	int count = 0;
	unordered_map<string, int> fib;
	while (cin >> str)
	{
		string num;
		cin >> num;
		int pos = str.find_last_of('\\');
		string str1;
		str1 = str.substr(pos + 1);
		if (str1.size() > 16)
			str1 = str1.substr(str1.size() - 16);

		str1 += ' ';
		str1 += num;
		fib[str1]++;
		if (count != fib.size())
			arr1.push(str1);

		count = fib.size();
	}

	stack<string> arr2;
	if (fib.size() < 8)
	{
		for (int i = 0; i < fib.size(); ++i)
		{
			arr2.push(arr1.top());
			arr1.pop();
		}
	}
	else
	{
		for (int i = 0; i < 8; ++i)
		{
			arr2.push(arr1.top());
			arr1.pop();
		}
	}

	while (!arr2.empty())
	{
		for (auto i : fib)
		{
			if (arr2.top() == i.first)
			{
				cout << i.first << " " << i.second << endl;
				arr2.pop();
				break;
			}
		}
	}

	return 0;
}