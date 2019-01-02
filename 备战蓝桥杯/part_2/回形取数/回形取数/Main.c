#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


/*
问题描述
　　回形取数就是沿矩阵的边取数，若当前方向上无数可取或已经取过，则左转90度。一开始位于矩阵左上角，方向向下。
输入格式
  　　输入第一行是两个不超过200的正整数m, n，表示矩阵的行和列。接下来m行每行n个整数，表示这个矩阵。
输出格式
	　输出只有一行，共mn个数，为输入矩阵回形取数得到的结果。数之间用一个空格分隔，行末不要有多余的空格。
	  样例输入
	  3 3
	  1 2 3
	  4 5 6
	  7 8 9
	  样例输出
	  1 4 7 8 9 6 3 2 5
	  样例输入
	  3 2
	  1 2
	  3 4
	  5 6
	  样例输出
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
		//由上到下
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

		//由左到右
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

		//由下到上
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


		//由左到右
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
	int n = 0;//表示矩阵的行
	int m = 0;//表示矩阵的列
	int i = 0;
	int j = 0;
	int size = 0;

	scanf("%d %d", &n, &m);

	int **arr = (int **)malloc(sizeof(int *) * n);
	for (i = 0; i < n; i++)
	{
		*(arr + i) = (int *)malloc(sizeof(int) * m);
	}

	//输入矩阵内容
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
