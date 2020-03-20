#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	int n = 0;
	stack<int> arr;
	while (cin >> n)
	{
		string str;
		getline(cin, str);
		getline(cin, str);
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				int num = 0;
				while (str[i] != ' ')
				{
					num = num * 10 + str[i] - '0';
					++i;
				}

				arr.push(num);
			}
			else if (str[i] == '+' || str[i] == '-'
				|| str[i] == '*' || str[i] == '/')
			{
				int x = arr.top();
				arr.pop();
				int y = arr.top();
				arr.pop();
				if (str[i] == '*')
					arr.push(x * y);
				else if (str[i] == '/')
					arr.push(y / x);
				else if (str[i] == '-')
					arr.push(y - x);
				else
					arr.push(x + y);
			}
		}
		cout << arr.top() << endl;
	}
	return 0;
}