#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
*  实现有向图的深度优先遍历，找到一个顶点到另一个顶点的最短路径
   注意此程序完成的是 1 顶点到 n 顶点的最短距离
*  郭文峰
*  2018/10/17
*/

int min = 999999;
int n = 0;
int m = 0;
int book[101] = { 0 };
int e[101][101] = { 0 };

void dfs(int cur, int dis)
{
	int i = 0;
	
	//给出递归的跳出条件
	//若距离已经大于最小距离直接跳出
	if (dis > min)
	{
		return;
	}

	//如果到终点
	if (cur == n) //此处的 n 代表 1 顶点到 n 顶点的最短距离 
		          // 可以通过标准输入来决定 n 的大小
	{
		//若距离小于最小距离，将 dis 的值赋给 min
		if (dis < min)
		{
			min = dis;
			return;
		}
	}

	for (i = 1; i <= n; i++)
	{
		//判断当前cur顶点到 i 顶点是否有路，并判断 i 是否在已走的路径中
		if (e[cur][i] != 999999 && book[i] == 0)
		{
			book[i] = 1;
			dfs(i, dis + e[cur][i]); //从 i 再出发，继续寻找目标
			book[i] = 0;//之前一部探索完毕之后，取消对城市 i 的标记
		}
	}
	return;

}

int main(void)
{
	int i = 0;
	int j = 0;
	int a = 0;
	int b = 0;
	int c = 0;


	//读入邻接矩阵的大小
	scanf("%d%d", &n, &m);
	//给邻接矩阵初始化
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j)
			{
				e[i][j] = 0;
			}
			else
			{
				e[i][j] = 999999;
			}
		}
	}

	for (i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		e[a][b] = c; //顶点a到顶点b的长度是c
	}

	book[1] = 1;
	dfs(1, 0);

	printf("%d\n", min);

	system("pause");
	return 0;
}