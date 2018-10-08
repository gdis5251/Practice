#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
*  本程序用于初次认识深度优先搜索，输入n，全排列n个数字
*  郭文峰
*  2018/10/8
*/

int a[10]  ;
int book[10] ;
int n;

void dfs(int step)
{
	int i = 0;
	if (step == n + 1)
	{
		//输出一种排列方式
		for (i = 1; i <= n; i++)
		{
			printf("%d", a[i]);
		}
		printf("\n");

		return; //返回最近一次调用dfs()的地方
	}

	for (i = 1; i <= n; i++)
	{
		
		
		if (0 == book[i])
		{
			a[step] = i;
			book[i] = 1;
			//用递归的方法再一次调用dfs（）
			dfs(step + 1);
			book[i] = 0;
			
		}
	}
	return;
}

int main(void)
{
	scanf("%d", &n);

	dfs(1);//调用dfs（）函数，从1开始

	system("pause");

	return 0;

}