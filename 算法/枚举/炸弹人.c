#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 本程序用来模拟炸弹人游戏，手动输入一个地图 ‘#’表示墙，‘.’表示空地，‘G'表示敌人。找出可以消灭敌人最多的那个点。
* 郭文峰
* 2018/10/4
*/

int main(void)
{
	char a[20][21];
	int x, y, i, j, map = 0, sum, p, q, n, m;

	//确定地图的大小
	scanf("%d%d", &n, &m);

	//输入地图
	for (i = 0; i <= n - 1; i++)
	{
		scanf("%s", &a[i]);
	}

	//用双重循环枚举地图上的每一个点
	for (i = 0; i <= n - 1; i++)
	{
		for (j = 0; j <= m - 1; j++)
		{
			if (a[i][j] == '.')
			{
				sum = 0;
				x = i;
				y = j;

				while (a[x][y] != '#')
				{
					if (a[x][y] == 'G')
						sum++;
					x--;
					
				}
				x = i;
				y = j;

				while (a[x][y] != '#')
				{
					if (a[x][y] == 'G')
						sum++;
					x++;
					
				}
				x = i;
				y = j;

				while (a[x][y] != '#')
				{
					if (a[x][y] == 'G')
						sum++;
					y--;
					
				}
				x = i;
				y = j;

				while (a[x][y] != '#')
				{
					if (a[x][y] == 'G')
						sum++;
					y++;
					
				}
				
				if (sum > map)
				{
					map = sum;
					p = i;
					q = j;
				}
					
				
			}
		}
	}
	printf("(%d,%d)点可以消灭%d最多的敌人", p, q, map);

	system("pause");

	return 0;
}