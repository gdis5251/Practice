#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 在一个有向图中，两个顶点往往不是最短长度，往往需要另一个顶点去过度
  本程序用一个算法实现更新邻接矩阵，实现两顶点之间的最短路径
* 郭文峰
* 2018/10/25
*/

int main(void)
{
	int e[51][51] = { 0 };
	int i = 0;
	int j = 0;
	int k = 0;
	int n = 0;
	int m = 0;
	int inf = 99999;
	int t1 = 0;
	int t2 = 0;
	int t3 = 0;

	scanf("%d%d", &n, &m);

	//初始化邻接矩阵
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j)
				e[i][j] = 0;
			else
				e[i][j] = inf;
		}
	}

	//输入各个顶点之间的距离
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &t1, &t2, &t3);
		e[t1][t2] = t3;
	}

	//更新邻接矩阵最短路径
	//分别通过K顶点过度，更新路径
	for (k = 1; k <= n; k++)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (e[i][j] > e[i][k] + e[k][j])
					e[i][j] = e[i][k] + e[k][j];
			}
		}
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			printf("%3d", e[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}