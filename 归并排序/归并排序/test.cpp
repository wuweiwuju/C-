#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
//递归
void _MergeSort(int* array, int left, int right, int* tmp)
{
	if (left == right)
		return;

	int mid = left + (right - left) / 2;
	//分治成左右区间都是有序的
	_MergeSort(array, left, mid, tmp);
	_MergeSort(array, mid + 1, right, tmp);

	//归并成有序的
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (array[begin1] <= array[begin2])
		{
			tmp[i++] = array[begin1];
			++begin1;
		}
		else
		{
			tmp[i++] = array[begin2];
			++begin2;
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = array[begin1];
		++begin1;
	}
	while (begin2 <= end2)
	{
		tmp[i++] = array[begin2];
		++begin2;
	}

	//最后将其拷贝到原数组
	memcpy(array + left, tmp + left, sizeof(int) * (i - left));
	
}
void MergeSort(int* array, int size)
{
	int* tmp = new int[size];
	_MergeSort(array, 0, size - 1, tmp);
	delete[] tmp;
}
//非递归
void MergeSortNonR(int* array, int size)
{
	int* tmp = new int[size];
	int gap = 1;
	while (gap < size)
	{
		for (int begin = 0; begin < size; begin += (2 * gap))
		{
			//[0,1] [begin,begin+gap]
			int begin1 = begin, end1 = begin + gap - 1;
			if (end1 >= size)
				end1 = size - 1;

			int begin2 = begin + gap, end2 = begin + 2 * gap - 1;
			if (end2 >= size)
				end2 = size - 1;

			int i = begin1;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (array[begin1] <= array[begin2])
				{
					tmp[i++] = array[begin1];
					++begin1;
				}
				else
				{
					tmp[i++] = array[begin2];
					++begin2;
				}
			}
			while (begin1 <= end1)
			{
				tmp[i++] = array[begin1];
				++begin1;
			}
			while (begin2 <= end2)
			{
				tmp[i++] = array[begin2];
				++begin2;
			}
		}
		gap *= 2;
		memcpy(array, tmp, sizeof(int) * size);
	}
	delete[] tmp;
}
void PrintSort(int* array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
int main()
{
	int array[10] = { 1,3,2,4,6,8,7,9,5,0 };
	PrintSort(array, sizeof(array) / sizeof(int));
	//MergeSort(array, sizeof(array) / sizeof(int));
	MergeSortNonR(array, sizeof(array) / sizeof(int));
	PrintSort(array, sizeof(array) / sizeof(int));
	return 0;
}