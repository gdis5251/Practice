#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 本程序是BellmanFord算法求最短路径。
  用到了邻接表三个数组分别为u[]、v[]、w[]。
  chenk来判断是否更新结束。
  flag来判断是否有负权值。
* 郭文峰
* 2018/10/26
*/

int main(void)
{
	int dis[10] = { 0 };
	int bak[10] = { 0 };
	int i = 0;
	int j = 0;
	int k = 0;
	int check = 0;
	int flag = 0;
	int n = 0;
	int m = 0;
	int u[10] = { 0 };
	int v[10] = { 0 };
	int w[10] = { 0 };
	int inf = 999999999;

	//输入n个顶点和m条边
	scanf("%d%d", &n, &m);

	//输入数据建立邻接表
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &u[i], &v[i], &w[i]);

	}

	//初始化dis数组
	for (i = 1; i <= n; i++)
	{
		dis[i] = inf;
	}
	dis[1] = 0;

	for (k = 1; k <= n - 1; k++)
	{
		//先让bak数组等于dis数组
		for (i = 1; i <= n; i++)
		{
			bak[i] = dis[i];
		}

		//更新最短路径
		for (j = 1; j <= m; j++)
		{
			if (dis[v[j]] > dis[u[j]] + w[j])
				dis[v[j]] = dis[u[j]] + w[j];
		}

		check = 0;
		//判断是否更新
		for (i = 1; i <= n; i++)
		{
			if (bak[i] != dis[i])
			{
				check = 1;
				break;
			}
		}
		if (check == 0)
			break;

	}

	//判断是否有负权值
	for (j = 1; j <= m; j++)
	{
		if (dis[v[j]] > dis[u[j]] + w[j])
			flag = 1;
	}

	if (flag == 1)
		printf("有负权值！");
	else
	{
		for (i = 1; i <= n; i++)
		{
			printf("%d ", dis[i]);
		}
	}

	system("pause");
	return 0;
}