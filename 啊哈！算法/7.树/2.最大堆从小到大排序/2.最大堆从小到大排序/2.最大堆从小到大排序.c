#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 本程序利用最大堆进行从小到大排序
* 郭文峰
* 2018/10/31
*/

int n;
int h[101];


//交换两个数
void swap(int t, int i)
{
	int temp = h[t];
	h[t] = h[i];
	h[i] = temp;
}

void siftdown(int i)
{
	int flag = 0;
	int t = 0;

	while (i * 2 <= n && 0 == flag)
	{
		//如果左子结点大于父结点，则不符合最大堆
		//将左子结点编号赋值给t后续交换
		if (h[i] < h[i * 2])
			t = i * 2;
		else
			t = i;
		
		//判断完左子结点再判断右子结点
		if (i * 2 + 1 <= n)
		{
			if (h[t] < h[i * 2 + 1])
				t = i * 2 + 1;
		}

		//如果t不等于i 则说明不符合最大堆，所以交换编号的内容
		if (t != i)
		{
			swap(t, i);
			i = t;//将t的编号赋给i，便于下一次比较
		}
		else
		{
			flag = 1;
		}
	}
}

void create(void)
{
	int i = 0;

	for (i = n / 2; i >= 1; i--)
	{
		//从最小子树来创建堆
		siftdown(i);
	}
}

//每次交换堆顶和最后一个编号结点
void heapsort(void)
{
	while (n > 1)
	{
		swap(1, n);
		n--;
		siftdown(1);
	}
}


int main(void)
{
	int i = 0;
	int num = 0;
	
	//输入共有多少个数字进行排序
	scanf("%d", &num);

	//输入将要排序的数字
	for (i = 1; i <= num; i++)
	{
		scanf("%d", &h[i]);
	}

	n = num;

	//创建堆
	create();

	//最大堆排序
	heapsort();

	//输出排序好的数字
	for (i = 1; i <= num; i++)
	{
		printf("%d ", h[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}