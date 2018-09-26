#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 本程序是将“简单的队列程序”进行的一个优化，将队列的三个元素放在一个结构体中
* 郭文峰
* 2018/9/26
*/
struct queue
{
	int data[100];
	int head;
	int tail;
};

int main(void)
{
	int i = 0;
	struct queue q;
	q.head = 0;
	q.tail = 0;

	//依次向队列插入9个数
	for (i = 0; i < 9; i++)
	{
		scanf("%d", &q.data[q.tail]);
		q.tail++;
	}

	while (q.head < q.tail)
	{
		printf("%d ", q.data[q.head]);//输出队首的元素
		q.head++;

		q.data[q.tail] = q.data[q.head];//先将队首的元素移到队尾
		q.tail++;

		q.head++;//再将队首出队
	}

	printf("\n");

	system("pause");
	return 0;
}