#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 本程序在广度优先搜索的基础上，对各个岛屿进行染色，且每个岛屿的代表数字不同。
* 郭文峰
* 2018/10/10
*/

int map[51][51], book[51][51];
int n, m;

void dfs(int x, int y, int color)
{
	int tx = 0;
	int ty = 0;
	int k = 0;
	int next[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

	//对(x,y)进行染色
	map[x][y] = color;

	for (k = 0; k <= 3; k++)
	{
		tx = x + next[k][0];
		ty = y + next[k][1];

		if (tx < 1 || tx > n || ty < 1 || ty > m)
		{
			continue;
		}

		if (map[tx][ty] > 0 && book[tx][ty] == 0)
		{
			book[tx][ty] = 1;
			dfs(tx, ty, color);
		}

	}
	return;


	

}

int main(void)
{
	
	int i = 0;
	int j = 0;
	//初始化染色变量
	int num = 0;

	//输入地图大小和起始坐标
	scanf("%d%d", &n, &m);

	//输入地图
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	//对各个岛屿进行染色用调用深度优先搜索函数
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (map[i][j] > 0)
			{
				num--;
				book[i][j] = 1;
				dfs(i, j, num);

			}
		}
	}

	//输出染色后的地图
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			printf("%3d", map[i][j]);
		}
		printf("\n");
	}

	printf("共有%d个小岛\n", -num);

	system("pause");

	return 0;

}