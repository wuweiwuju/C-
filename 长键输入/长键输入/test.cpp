#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	bool isLongPressedName(string name, string typed) {
		int count = 0;
		for (int i = 0; i < name.size(); ++i)
		{
			for (int j = count; j < typed.size(); ++j)
			{
				if (name[i] == typed[j])
				{
					if (name[i + 1] == typed[j])
					{
						count++;
					}
					else
					{
						while (name[i] == typed[j++])
							count++;
					}
					break;
				}
				else
				{
					return false;
				}
			}
		}
		if (typed[count - 1] != name[name.size() - 1])
			return false;
		return true;
	}
};