#define _CRT_SECURE_NO_WARNINGS 1
//¼ÆÊýÅÅÐò
#include<iostream>
#include<stdlib.h>
using namespace std;
void CountSort(int* array, int size)
{
	int max = array[0];
	int min = array[0];
	for (int i = 1; i < size; ++i)
	{
		if (array[i] > max)
			max = array[i];

		if (array[i] < min)
			min = array[i];
	}
	
	int* count = new int[max - min + 1]{0};

	for (int i = 0; i < size; ++i)
	{
		int flag = array[i] - min;
		count[flag]++;
	}
	int j = 0;
	for (int i = 0; i < max - min + 1; ++i)
	{
		while (count[i] > 0)
		{
			array[j++] = min + i;
			--count[i];
		}
	}
	delete[] count;
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
	int array[5] = { 101,104,101,103,100 };
	PrintSort(array, sizeof(array) / sizeof(int));
	CountSort(array, sizeof(array) / sizeof(int));
	PrintSort(array, sizeof(array) / sizeof(int));
	return 0;
}