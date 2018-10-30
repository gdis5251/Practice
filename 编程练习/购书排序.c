#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 图书馆将要买书，要请来N个同学来说自己想要什么书。
  每种书只买一本，还要把书的ISBN号从小到大排序。
  此方法为简单的桶排序，既可以去重，又可以排序。
  假设书的ISBN好在1~1000之内。
* 郭文峰
* 2018/9/26
*/

int main(void)
{

	int i = 0;
	int n = 0;
	int a[1001] = {0};
	int t = 0;
	int count = 0;

	scanf("%d", &n);
         
	//输入ISBN号并用a数组记录
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &t);
		//去重
		a[t] = 1;
	}

	for (i = 1; i <= 1000; i++)
	{
		if (a[i] == 1)
		{
			printf("%d ", i);
			//count种书
			count++;
		}
	}

	printf("\n");
	printf("%d\n", count);

	system("pause");
	return 0;
}
