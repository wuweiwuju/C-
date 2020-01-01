#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		int size = rotateArray.size();
		if (size == 0) {
			return 0;
		}//if
		int left = 0, right = size - 1;
		int mid = 0;
		// rotateArray[left] >= rotateArray[right] ȷ����ת
		while (rotateArray[left] >= rotateArray[right]) {
			// �ֽ��
			if (right - left == 1) {
				mid = right;
				break;
			}//if
			mid = left + (right - left) / 2;
			// rotateArray[left] rotateArray[right] rotateArray[mid]�������
			// �޷�ȷ���м�Ԫ��������ǰ�滹�Ǻ���ĵ���������
			// ֻ��˳�����
			if (rotateArray[left] == rotateArray[right] && rotateArray[left] == rotateArray[mid]) {
				return MinOrder(rotateArray, left, right);
			}//if
			// �м�Ԫ��λ��ǰ��ĵ���������
			// ��ʱ��СԪ��λ���м�Ԫ�صĺ���
			if (rotateArray[mid] >= rotateArray[left]) {
				left = mid;
			}//if
			// �м�Ԫ��λ�ں���ĵ���������
			// ��ʱ��СԪ��λ���м�Ԫ�ص�ǰ��
			else {
				right = mid;
			}//else
		}//while
		return rotateArray[mid];
	}
private:
	// ˳��Ѱ����Сֵ
	int MinOrder(vector<int> &num, int left, int right) {
		int result = num[left];
		for (int i = left + 1; i < right; ++i) {
			if (num[i] < result) {
				result = num[i];
			}//if
		}//for
		return result;
	}
};
/*class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0)
			return 0;
		int left = 0;
		int right = rotateArray.size() - 1;
        int mid = 0;
		while (rotateArray[left] >= rotateArray[right])
		{
            if (left + 1 == right)
			{
				mid = right;
				break;
			}
            mid = (left + right) >> 1;
			if (rotateArray[mid] >= rotateArray[left])
				left = mid;
			else
				right = mid;
		}
		return rotateArray[mid];
	}
};*/
int main()
{
	Solution arr;
	vector<int> rotateArray;
	rotateArray.resize(5);
	for (int i = 0; i < rotateArray.size(); i++)
	{
		cin >> rotateArray[i];
	}
	int ret = arr.minNumberInRotateArray(rotateArray);
	cout << ret << endl;
	return 0;
}