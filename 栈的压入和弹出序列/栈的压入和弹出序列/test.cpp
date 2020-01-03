#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.size() == 0 || popV.size() == 0)
			return false;
		stack<int> s;
		int j = 0;
		for (int i = 0; i < pushV.size(); i++)
		{
			if (pushV[i] != popV[j])
			{
				s.push(pushV[i]);
			}
			else
			{
				j++;
			}
		}
		if (j < popV.size())
		{
			for (int i = j; i < popV.size(); i++)
			{
				if (popV[i] == s.top())
					s.pop();
				else
					return false;
			}
		}
		return true;
	}
};