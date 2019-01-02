#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


/*
��������
��������ȡ�������ؾ���ı�ȡ��������ǰ������������ȡ���Ѿ�ȡ��������ת90�ȡ�һ��ʼλ�ھ������Ͻǣ��������¡�
�����ʽ
  ���������һ��������������200��������m, n����ʾ������к��С�������m��ÿ��n����������ʾ�������
�����ʽ
	�����ֻ��һ�У���mn������Ϊ����������ȡ���õ��Ľ������֮����һ���ո�ָ�����ĩ��Ҫ�ж���Ŀո�
	  ��������
	  3 3
	  1 2 3
	  4 5 6
	  7 8 9
	  �������
	  1 4 7 8 9 6 3 2 5
	  ��������
	  3 2
	  1 2
	  3 4
	  5 6
	  �������
	  1 3 5 6 4 2
*/

void huiXingQuShu(int **arr, int n, int m, int size)
{
	int i = 0;
	int j = 0;

	int **book = (int **)malloc(sizeof(int *) * n);
	for (i = 0; i < n; i++)
	{
		*(book + i) = (int *)malloc(sizeof(int) * m);
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			book[i][j] = 0;
		}
	}

	i = 0;
	j = 0;
	while (size > 0)
	{
		//���ϵ���
		while (i >= 0 && i < n && j >= 0 && j < m && book[i][j] == 0)
		{
			if (book[i][j] == 0)
			{
				printf("%d ", arr[i][j]);
				book[i][j] = 1;
				i++;
				size--;
			}
			if (size == 0)
				break;
		}
		if (size == 0)
			break;
		i--;
		j++;

		//������
		while (i >= 0 && i < n && j >= 0 && j < m && book[i][j] == 0)
		{
			if (i >= 0 && i < n && j >= 0 && j < m)
			{
				printf("%d ", arr[i][j]);
				book[i][j] = 1;

				size--;
			}
			j++;
			if (size == 0)
				break;
		}
		if (size == 0)
			break;
		j--;
		i--;

		//���µ���
		while (i >= 0 && i < n && j >= 0 && j < m && book[i][j] == 0)
		{
			if (i >= 0 && i < n && j >= 0 && j < m && book[i][j] == 0)
			{
				printf("%d ", arr[i][j]);
				book[i][j] = 1;

				size--;
			}
			i--;
			if (size == 0)
				break;
		}
		if (size == 0)
			break;
		i++;
		j--;


		//������
		while (i >= 0 && i < n && j >= 0 && j < m && book[i][j] == 0)
		{
			if (i >= 0 && i < n && j >= 0 && j < m && book[i][j] == 0)
			{
				printf("%d ", arr[i][j]);
				book[i][j] = 1;

				size--;
			}
			j--;
			if (size == 0)
				break;
		}
		if (size == 0)
			break;
		j++;
		i++;
	}
}


int main(void)
{
	int n = 0;//��ʾ�������
	int m = 0;//��ʾ�������
	int i = 0;
	int j = 0;
	int size = 0;

	scanf("%d %d", &n, &m);

	int **arr = (int **)malloc(sizeof(int *) * n);
	for (i = 0; i < n; i++)
	{
		*(arr + i) = (int *)malloc(sizeof(int) * m);
	}

	//�����������
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	size = n * m;

	huiXingQuShu(arr, n, m, size);
	printf("\n");

	system("pause");
	return 0;
}
