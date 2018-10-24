#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 对于一个无向图，共有n个城市，m条航线。
  需要从城市start到城市end，没有直达的航线，需要计算出最少的转机次数
  此程序需要用到广度优先搜索
* 郭文峰
*2018/10/24
*/

struct note
{
	int x;//城市编号
	int s;//转机次数
};

int main(void)
{
	int e[51][51] = { 0 };
	int book[51] = { 0 };
	struct note que[2501] = { 0 };
	int i = 0;
	int j = 0;
	int n = 0;
	int m = 0;
	int a = 0;
	int b = 0;
	int start = 0;
	int end = 0;
	int head = 1;
	int tail = 1;
	int cur = 0;
	int flag = 0;

	//输入城市个数n，航线条数m，起始城市start，终点城市end
	scanf("%d%d%d%d", &n, &m, &start, &end);

	//初始化邻接矩阵，自己到自己的转机次数为0
	//其他默认为正无穷这里用99999表示
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j)
				e[i][j] = 0;
			else
				e[i][j] = 99999;
		}
	}

	//输入各航线信息
 	for (i = 1; i <= m; i++)
	{
		scanf("%d%d", &a, &b);
		e[a][b] = 1;
		e[b][a] = 1;
	}

	//将第一个城市信息入队
	que[tail].x = start;
	que[tail].s = 0;
	tail++;
	book[start] = 1;

	while (head < tail)
	{
		cur = que[head].x; //当前队列首城市的编号

		for (i = 1; i <= n; i++)
		{
			if (e[cur][i] != 99999 && book[i] == 0)
			{
				que[tail].x = i;
				que[tail].s = que[head].s + 1;
				tail++;
				book[i] = 1;
 			}

			if (que[tail].x == end)
			{
				flag = 1;
				break;
			}

			
		}

		if (flag == 1)
			break;

		head++;
	}

	printf("%d\n", que[tail - 1].s);

	system("pause");
	return 0;
}