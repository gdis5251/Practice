#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 使用广度优先遍历遍历无向图
* 郭文峰
* 2018/10/17
*/

int main(void)
{
	int i = 0;
	int j = 0;
	int n = 0;
	int m = 0;
	int a = 0;
	int b = 0;
	int cur = 0;
	int book[101] = { 0 };
	int e[101][101] = { 0 };
	int que[10001] = { 0 };
	int head = 1;
	int tail = 1;

	scanf("%d%d", &n, &m);

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j)
			{
				e[i][j] = 0;//使i == j 的点也就是自己访问自己的点等于0
			}
			else
			{
				e[i][j] = 999999; //先默认所有的点都不能互相访问，并认为999999为正无穷
			}
		}
	}

	for (i = 1; i <= m; i++)
	{
		scanf("%d%d", &a, &b);
		e[a][b] = 1;
		e[b][a] = 1;

	}

	//先将1结点入栈
	que[tail] = 1;
	tail++;
	book[1] = 1;

	while (head < tail)
	{
		cur = que[head];

		for (i = 1; i <= n; i++)
		{
			if (e[cur][i] == 1 && book[i] == 0)
			{
				que[tail] = i;
				tail++;
				book[i] = 1;
			}

			if (tail > n)
			{
				break;
			}
		}

		head++;
	}

	for (i = 1; i < tail; i++)
	{
		printf("%d ", que[i]);
	}

	system("pause");
	return 0;

}