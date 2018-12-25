#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>

#define MAX 9999

static void swap(int *x, int *y)
{

	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void print(int *arr, int n)
{
	int i_ = 0;

	for (i_ = 0; i_ < n; i_++)
	{
		printf("%d ", arr[i_]);
	}
}


void quickSort(int *arr, int left, int right)
{
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
	quickSort(arr, 0, n - 1);

	print(arr, n);
	printf("\n");

	free(arr);

	system("pause");
	return 0;
}