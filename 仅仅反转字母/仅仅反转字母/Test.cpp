#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	string reverseOnlyLetters(string S) {
		string Temp;
		Temp = S;
		reverse(Temp.begin(), Temp.end());
		int j = 0;
		for (int i = 0; i < S.size(); ++i)
		{
			if ((S[i] >= 'a' && S[i] <= 'z') ||
				(S[i] >= 'A' && S[i] <= 'Z'))
			{
				while ((Temp[j] < 'a' || Temp[j] > 'z') &&
					(Temp[j] < 'A' || Temp[j] > 'Z'))
				{
					j++;
				}
				S[i] = Temp[j++];
			}
		}
		return S;
	}
};