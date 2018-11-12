#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>


/*
* 本程序用两个数组来模拟链表，一个data数组来存储真正的数据，另一个right数组来存放当前元素的下一个结点位置。
* 郭文峰
* 2018/10/1
*/

int main(void)
{
	//对需要的变量初始化
	int data[101] = { 0 };
	int right[101] = { 0 };
	int i = 0;
	int n = 0;
	int len = 0;
	int t = 0;

	//手动输入模拟链表最开始需要录入多少个元素
	scanf("%d", &n);
	
	len = n;

	for (i = 1; i <= n; i++)
	{
		scanf("%d", &data[i]);
	}

	for (i = 1; i <= n; i++)
	{
		if (i != n)
		{
			right[i] = i + 1;
		}
		else
		{
			right[i] = 0;
		}
	}

	//准备插入新元素
	len++;
	scanf("%d", &data[len]);

	t = 1;

	while (t != 0)
	{
		if (data[right[t]] > data[len])
		{
			right[len] = right[t];
			right[t] = len;
			break;
		}
		t = right[t];
	}

	t = 1;

	while (t != 0)
	{
		printf("%d ", data[t]);
		t = right[t];
	}

	system("pause");
	return 0;
}