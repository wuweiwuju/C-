#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		int start = 0;
		int end = A.size() - 1;
		while (start < end)
		{
			if (A[start] % 2 == 0 && A[end] % 2 == 1)
			{
				start++;
				end--;
			}
			else if (A[start] % 2 == 1 && A[end] % 2 == 0)
			{
				swap(A[start++], A[end--]);
			}
			else if (A[start] % 2 == 1 && A[end] % 2 == 1)
			{
				end--;
			}
			else
			{
				start++;
			}
		}
		return A;
	}
};