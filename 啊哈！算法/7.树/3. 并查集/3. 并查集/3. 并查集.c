#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 快过年了，犯罪分子们也开始为年终奖"奋斗"作案了。小哼的家乡出现了多次抢劫事件。由于强盗人数过于庞大。作案频繁，警方想查清楚到底有几个犯罪团伙实在太不容易了，不过警察叔叔还是搜集到了一些证据，需要咱们帮忙分析一下:

  例:
 
  现在有10个强盗

  1号强盗与2号强盗是同伙

  3号强盗与4号强盗是同伙

  5号强盗与2号强盗是同伙

  4号强盗与6号强盗是同伙

  2号强盗与6号强盗是同伙

  8号强盗与7号强盗是同伙

  9号强盗与7号强盗是同伙

  1号强盗与6号强盗是同伙

  2号强盗与4号强盗是同伙

  有一点要注意:强盗的同伙也是同伙。你能帮警方查出有多少独立的犯罪团伙吗？
* 郭文峰
* 2018/10/31
*/

void init(int *f, int n)
{
	int i = 0;

	//初始化数组
	for (i = 1; i <= n; i++)
	{
		*(f + i) = i;
	}
}

int getf(int *f, int x)
{
	//若x的BOSS是自己则返回x
	if (f[x] == x)
	{
		return x;
	}
	//若x的BOSS不是自己，则递归找到最终的BOSS
	else
	{
		f[x] = getf(f, f[x]);
		return f[x];
	}
}

void merge(int *f, int x, int y)
{
	int t1 = getf(f, x);
	int t2 = getf(f, y);

	if (t1 != t2)//判断两个结点是否在同一集合中
	{
		f[t2] = t1;
		//靠左原则
	}
}

int main(void)
{
	int f[1000] = { 0 };
	int n = 0;
	int m = 0;
	int k = 0;
	int sum = 0;
	int i = 0;
	int x = 0;
	int y = 0;

	//共有n个犯罪分子和m对关系描述
	scanf("%d%d", &n, &m);

	//初始化
	init(f, n);

	//开始描述关系，并创建并查集
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d", &x, &y);
		merge(f, x, y);
	}

	//统计有多少组犯罪分子
	for (i = 1; i <= n; i++)
	{
		if (f[i] == i)
			sum++;
	}


	printf("%d\n", sum);
	
	system("pause");
	return 0;
}