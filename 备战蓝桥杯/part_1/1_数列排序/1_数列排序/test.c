#define _CRT_SECURE_NO_WARNINGS 1

#include "sort.h"

/*
问题描述
　　给定一个长度为n的数列，将这个数列按从小到大的顺序排列。1<=n<=200
	输入格式
  　	第一行为一个整数n。
		第二行包含n个整数，为待排序的数，每个整数的绝对值小于10000。
	输出格式
	  　输出一行，按从小到大的顺序输出排序后的数列。
	样例输入
		5
		8 3 6 4 9
	样例输出
		3 4 6 8 9
*/


int main(void)
{
	int i = 0;
	int n = 0;
	scanf("%d", &n);

	int *arr = (int *)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	//冒泡排序
	//bubbleSort(arr, n);

	//选择排序
	//selSort(arr, n);

	//快速排序
	quickSort(arr, 0, n - 1);

	print(arr, n);
	printf("\n");

	free(arr);

	system("pause");
	return 0;
}