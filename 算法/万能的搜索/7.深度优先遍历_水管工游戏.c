#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 本程序用来实现管道游戏，地图方面，用1、2、3、4、5、6来分别表示6中管道的形状
  用1、2、3、4分别来表示左、上、右、下四个进口方向
* 郭文峰
* 2018/10/11
*/

int map[51][51], book[51][51];
int n, m, flag;

struct note
{
	int x;
	int y;
}s[100];
int top;

void dfs(int x, int y, int front)
{
	int i = 0;
	//判断是否到达终点，y = m + 1因为到最后会将管口对向外面
	if (x == n && y == m + 1)
	{
		flag = 1;//找到铺设方案
		for (i = 1; i <= top; i++)
		{
			printf("(%d,%d)  ", s[i].x, s[i].y);
		}
		return;
	}

	//判断是否越界
	if (x < 1 || x > n || y < 1 || y > m)
	{
		return;
	}

	//判断这个管道是否用过
	if (book[x][y] == 1)
	{
		return;
	}
	book[x][y] = 1;

	//入栈
	top++;
	s[top].x = x;
	s[top].y = y;

	//用到直水管的情况
	//1、2、3、4分别表示进水口在左、上、右、下的情况
	if (map[x][y] >= 5 && map[x][y] <= 6)
	{
		if (1 == front)
		{
			dfs(x, y + 1, 1);
		}
		if (2 == front)
		{
			dfs(x + 1, y, 2);
		}
		if (3 == front)
		{
			dfs(x, y - 1, 3);
		}
		if (4 == front)
		{
			dfs(x - 1, y, 4);
		}
	}


	//遇到水管是弯管的情况
	if (map[x][y] >= 1 && map[x][y] <= 4)
	{
		//每一次进口会有两种弯管对应
		if (1 == front)
		{
			dfs(x + 1, y, 2);
			dfs(x - 1, y, 4);
		}
		if (2 == front)
		{
			dfs(x, y + 1, 1);
			dfs(x, y - 1, 3);
		}
		if (3 == front)
		{
			dfs(x - 1, y, 4);
			dfs(x + 1, y, 2);

		}
		if (4 == front)
		{
			dfs(x, y + 1, 1);
			dfs(x, y - 1, 3);
		}
	}

	book[x][y] = 0;
	top--;//出栈
	return;
}
int main()
{
	int i = 0;
	int j = 0;

	scanf("%d%d", &n, &m);

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	//开始搜索，从1,1开始方向是左边为入口
	dfs(1, 1, 1);

	if (0 == flag)
	{
		printf("impossible!\n");
	}

	system("pause");
	return 0;
}