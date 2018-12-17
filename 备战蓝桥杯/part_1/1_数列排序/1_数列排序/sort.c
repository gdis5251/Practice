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

	//ÿ�α������У�ѡ����С�����i������
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

		swap(&arr[i_], &arr[num_]);//����С��Ԫ�����i_��Ԫ�ؽ���
	}


	print(arr, n);
}





void quickSort(int *arr, int left, int right)
{
	assert(arr);

	if (left >= right)//�ݹ���������
		return;

	int key = arr[left];
	int i_ = left;
	int j_ = right;

	while (i_ < j_)
	{
		while (i_ < j_ && arr[j_] >= key)//��һ���Ȼ���С������
			j_--;


		while (i_ < j_ && arr[i_] <= key)//��һ���Ȼ����������
			i_++;


		if (i_ < j_)//���������Ļ�����
			swap(&arr[i_], &arr[j_]);
	}

	//��i_=j_���������������
	arr[left] = arr[i_];
	arr[i_] = key;

	quickSort(arr, left, i_ - 1);
	quickSort(arr, i_ + 1, right);

}