#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 本程序是用广度优先搜索的方法，再一次解决“解救小哈”的问题
* 郭文峰
* 2018/10/9
*/

struct note
{
	int x;
	int y;
	int s;
};

int main(void)
{
	struct note que[2501];
	//初始化地图和标记数组
	int map[51][51] = { 0 };
	int book[51][51] = { 0 };
	int i = 0;
	int j = 0;
	int k = 0;
	//初始化起始坐标变量
	int startx = 0;
	int starty = 0;
	//初始化终点坐标变量
	int p = 0;
	int q = 0;
	//初始化栈头和栈尾
	int head = 1;
	int tail = 1;
	//初始化地图大小变量
	int n = 0;
	int m = 0;
	//初始化方向数组
	int next[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
	//初始化下一步坐标变量
	int tx = 0;
	int ty = 0;

	int flag = 0;

	scanf("%d%d", &n, &m);
	//读入地图
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	//输入起始坐标和终点坐标
	scanf("%d%d%d%d", &startx, &starty, &p, &q);

	//初始化栈
	que[tail].x = startx;
	que[tail].y = starty;
	que[tail].s = 0;
	tail++;

	book[startx][starty] = 1;

	while (head < tail)
	{
		for (k = 0; k <= 3; k++)
		{
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];

			//判断是否越界
			if (tx < 1 || tx > n || ty < 1 || ty > m)
			{
				continue;
			}

			//判断下一步是否可走
			if (map[tx][ty] == 0 && book[tx][ty] == 0)
			{
				book[tx][ty] = 1;
				que[tail].x = tx;
				que[tail].y = ty;
				que[tail].s = que[head].s + 1;
				tail++;

			}
		
			if (tx == p && ty == q)
			{
				flag = 1;
				break;
			}
		}
		
		if (1 == flag)
		{
			break;
		}
		head++;
	}

	printf("%d\n", que[tail - 1].s);


	system("pause");

	return 0;
}