#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 对一串数字进行从小到大的堆排序
  此程序用到了最小堆
* 郭文峰
* 2018/10/30
*/

int n;//用来记录有多少个结点
int h[101];//用来存放堆的数字



void swap(int t, int i)
{
	int temp = h[t];
	h[t] = h[i];
	h[i] = temp;
}

//对于结点i及其它的子结点进行子树最小堆处理
void siftdown(int i)
{
	int flag = 0;
	int t = 0;

	while (i * 2 <= n && 0 == flag)
	{
		//如果左子结点小于父结点，就让t等于子结点
		if (h[i] > h[i * 2])
		{
			t = i * 2;
		}
		else
		{
			t = i;
		}

		//如果右子结点小于现在的父结点，让t等于子结点
		if (i * 2 + 1 <= n)
		{
			if (h[t] > h[i * 2 + 1])//注意如果程序到此处说明左子结点已经和父结点交换，所以此处判断的是左子结点和右子结点
			{
				t = i * 2 + 1;
			}
		}

		//如果上述条件满足，则交换结点的数字
		if (t != i)
		{
			swap(t, i);
			i = t;//将刚才被交换的子结点编号赋给i便于下来的遍历

		}
		else
		{
			flag = 1;
		}
	}
}


void create()
{
	int i = 0;

	for (i = n / 2; i >= 1; i--)
	{
		siftdown(i);
	}
}

//删除堆顶元素并返回它
int deletetop(void)
{
	int t = h[1];
	h[1] = h[n];
	n--;//堆的元素减少1
	siftdown(1);
	return t;
}

int main(void)
{
	int i = 0;
	int num = 0;

	//输入有多少个数字将要进堆
	scanf("%d", &num);

	for (i = 1; i <= num; i++)
	{
		scanf("%d", &h[i]);
	}
	
	//注意这一步必须卸载creat之前
	n = num;


	//建立堆
	create();


	//每次删除对顶数字，并进行打印
	for (i = 1; i <= num; i++)
	{
		printf("%d ", deletetop());
	}
	printf("\n");

	system("pause");
	return 0;


}