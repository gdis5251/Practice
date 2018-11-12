#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 使用深度优先搜索来遍历一个无向图
* 郭文峰
* 2018/10/17
*/
int n, m, sum;
int book[101], e[101][101];

void dfs(int cur)
{
	int i = 0;
	printf("%d ", cur);//输出当前点

	sum++;
	if (sum == n)//如果访问完所有的点则返回
	{
		return;
	}

	for (i = 1; i <= n; i++)
	{
		if (e[cur][i] == 1 && book[i] == 0)//如果cur结点到i结点可以连接则标记为已经访问
		{									//且递归访问i结点
			book[i] = 1;
			dfs(i);
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
	
	//用一个二维数组e[][]来存储一个无向图
	//输入这个无向图共有几个数字
	scanf("%d%d", &n, &m);

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (i == j)
			{
				e[i][j] = 0;		//二维数组中用0代表自己到自己
			}
			else
			{
				e[i][j] = 999999999; //二维数组中用999999999来表示正无穷
			}
		}
	}

	for (i = 1; i <= n; i++)
	{
		scanf("%d%d", &a, &b);
		e[a][b] = 1;
		e[b][a] = 1; //因为是无向图，所以双向都等于1
	}

	book[1] = 1;//1号标记已经访问
	dfs(1);//从1号顶点开始遍历

	system("pause");
	return 0;
}