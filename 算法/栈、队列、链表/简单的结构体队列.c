#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* �������ǽ����򵥵Ķ��г��򡱽��е�һ���Ż��������е�����Ԫ�ط���һ���ṹ����
* ���ķ�
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

	//��������в���9����
	for (i = 0; i < 9; i++)
	{
		scanf("%d", &q.data[q.tail]);
		q.tail++;
	}

	while (q.head < q.tail)
	{
		printf("%d ", q.data[q.head]);//������׵�Ԫ��
		q.head++;

		q.data[q.tail] = q.data[q.head];//�Ƚ����׵�Ԫ���Ƶ���β
		q.tail++;

		q.head++;//�ٽ����׳���
	}

	printf("\n");

	system("pause");
	return 0;
}