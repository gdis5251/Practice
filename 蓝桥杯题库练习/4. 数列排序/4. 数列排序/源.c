#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>
#include <assert.h>
#include <stdlib.h>

int IntCmp(const void *x, const void *y)
{
	assert(x && y);

	return *(int *)x - *(int *)y;
}

int main(void)
{
	int n = 0;
	int i = 0;	
	scanf("%d", &n);
	int *arr = (int *)malloc(sizeof(int)*n);
	
	//需要排序的元素
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	qsort(arr, n, sizeof(int), IntCmp);

	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	free(arr);


	system("pause");
	return 0;
}