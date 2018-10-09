#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 迷宫由n行m列的单元格组成（n和m都小于等于50），每个单元格要么是空地，要么是障碍物。
  找到一条从迷宫的起点到终点的最短路径（0表示空地，1表示障碍物）
* 郭文峰
* 2018/10/9
*/

int n, m;//地图大小变量
int p, q;//终点坐标变量
int min = 99999;//用来记录最短路径
int map[51][51];//用二维数组存储地图
int book[51][51];//记录走过的坐标

void dfs(int x, int y, int step)
{
	int tx, ty, k;

	int next[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };//向右、下、左、右走

	//如果到终点，判断是否是最短路径
	if (x == p && y == q)
	{
		if (step < min)
		{
			min = step;

		}
		return;
	}

	for (k = 0; k <= 3; k++)
	{
		//计算下一个坐标
		tx = x + next[k][0];
		ty = y + next[k][1];

		//判断是否越界
		if (tx < 1 || tx > n || ty < 1 || ty > m)
		{
			continue;
		}

		if (map[tx][ty] == 0 && book[tx][ty] == 0)
		{
			book[tx][ty] = 1;
			dfs(tx, ty, step + 1);
			book[tx][ty] = 0;
		}
	}
	return;
}

int main(void)
{
	int startx = 0;
	int starty = 0;//起始坐标
	int i = 0;
	int j = 0;

	scanf("%d%d", &n, &m);//输入地图的大小

	for (i = 1; i <= n; i++)//输入地图
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	scanf("%d%d%d%d", &startx, &starty, &p, &q);//输入起点坐标和终点坐标

	book[startx][starty] = 1;

	dfs(startx, starty, 0);

	printf("%d\n", min);

	system("pause");

	return 0;
}