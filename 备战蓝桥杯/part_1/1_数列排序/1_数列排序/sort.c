#define _CRT_SECURE_NO_WARNINGS 1

#include "sort.h"





//print arr
void print(int *arr, int n)
{
	int i_ = 0;

	for (i_ = 0; i_ < n; i_++)
	{
		printf("%d ", arr[i_]);
	}
}




static void swap(int *x, int *y)
{
	assert(x && y);

	int tmp = *x;
	*x = *y;
	*y = tmp;
}





void bubbleSort(int *arr, int n)
{
	assert(arr);

	int i_ = 0;
	int j_ = 0;

	for (i_ = 0; i_ < n; i_++)
	{
		for (j_ = 0; j_ < n - i_ - 1; j_++)
		{
			if (arr[j_] > arr[j_ + 1])
				swap(&arr[j_], &arr[j_ + 1]);
		}
	}

	print(arr, n);
}





void selSort(int *arr, int n)
{
	assert(arr);

	int i_ = 0;
	int j_ = 0;
	int num_ = 0;

	//每次遍历数列，选择最小的与第i个交换
	for (i_ = 0; i_ < n; i_++)
	{
		int min_ = MAX;


		for (j_ = i_; j_ < n; j_++)
		{
			if (min_ > arr[j_])
			{
				min_ = arr[j_];
				num_ = j_;
			}
		}

		swap(&arr[i_], &arr[num_]);//将最小的元素与第i_个元素交换
	}


	print(arr, n);
}





void quickSort(int *arr, int left, int right)
{
	assert(arr);

	if (left >= right)//递归跳出条件
		return;

	int key = arr[left];
	int i_ = left;
	int j_ = right;

	while (i_ < j_)
	{
		while (i_ < j_ && arr[j_] >= key)//找一个比基数小的数字
			j_--;


		while (i_ < j_ && arr[i_] <= key)//找一个比基数大的数字
			i_++;


		if (i_ < j_)//满足条件的话交换
			swap(&arr[i_], &arr[j_]);
	}

	//将i_=j_的数字与基数交换
	arr[left] = arr[i_];
	arr[i_] = key;

	quickSort(arr, left, i_ - 1);
	quickSort(arr, i_ + 1, right);

}