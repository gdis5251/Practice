#define _CRT_SECURE_NO_WARNINGS 1

#include "sort.h"

/*
��������
��������һ������Ϊn�����У���������а���С�����˳�����С�1<=n<=200
	�����ʽ
  ��	��һ��Ϊһ������n��
		�ڶ��а���n��������Ϊ�����������ÿ�������ľ���ֵС��10000��
	�����ʽ
	  �����һ�У�����С�����˳��������������С�
	��������
		5
		8 3 6 4 9
	�������
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

	//ð������
	//bubbleSort(arr, n);

	//ѡ������
	//selSort(arr, n);

	//��������
	quickSort(arr, 0, n - 1);

	print(arr, n);
	printf("\n");

	free(arr);

	system("pause");
	return 0;
}