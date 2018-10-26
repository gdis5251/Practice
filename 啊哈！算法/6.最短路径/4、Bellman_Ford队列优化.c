#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 本程序在对BellmanFord算法进行了队列的优化
* 郭文峰
* 2018/10/26
*/

int main(void)
{
	int dis[10] = { 0 };
	int i = 0;
	int k = 0;
	int n = 0;
	int m = 0;
	int head = 1;
	int tail = 1;
	int que[101] = { 0 };
	int first[10] = { 0 };
	int next[10] = { 0 };
	int u[10] = { 0 };
	int v[10] = { 0 };
	int w[10] = { 0 };
	int book[10] = { 0 };
	int inf = 99999;


	scanf("%d%d", &n, &m);

	for (i = 1; i <= n; i++)
	{
		dis[i] = inf;
	}
	dis[1] = 0;

	//初始化first数组
	for (i = 1; i <= n; i++)
	{
		first[i] = -1;
	}

	for (i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
		//建立邻接表
		next[i] = first[u[i]];
		first[u[i]] = i;
	}

	//将一号顶点入队
	que[tail] = 1;
	tail++;
	book[1] = 1;

	while (head < tail)
	{
		k = first[que[head]];//当前需要处理的队首顶点
		//扫描当前顶点的所有边
		while (k != -1)
		{
			if (dis[v[k]] > dis[u[k]] + w[k])//判断边是否符合松弛的条件
			{
				dis[v[k]] = dis[u[k]] + w[k];//更新

				if (book[v[k]] == 0)
				{
					que[tail] = v[k];
					tail++;
					book[v[k]] = 1;

				}
			}
			k = next[k];
		}
		book[que[head]] = 0;
		head++;
	}

	//输出一号顶点到其余各顶点的最短路径
	for (i = 1; i <= n; i++)
	{
		printf("%d ", dis[i]);
	}

	system("pause");
	return 0;
}





