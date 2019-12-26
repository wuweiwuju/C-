#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stack>
using namespace std;
class Solution
{
public:
	void push(int node) {
		stack2.push(node);
	}

	int pop() {
		if (stack1.empty())
		{
			int temp = stack2.size();
			for (int i = 0; i < temp; i++)
			{
				stack1.push(stack2.top());
				stack2.pop();
			}
		}

		int val = stack1.top();
		stack1.pop();
		return val;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};
int main()
{
	Solution queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);
	cout << queue.pop() << " ";
	cout << queue.pop() << " ";
	queue.push(4);
	cout << queue.pop() << " ";
	queue.push(5);
	cout << queue.pop() << " ";
	cout << queue.pop() << " ";
	return 0;
}