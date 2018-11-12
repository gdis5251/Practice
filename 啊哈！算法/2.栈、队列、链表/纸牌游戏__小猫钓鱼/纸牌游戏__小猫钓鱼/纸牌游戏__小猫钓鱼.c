#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* ��Ϸ�����������ģ���һ���˿���ƽ���ֳ����ݣ�ÿ����һ�ݡ�С�����ó����еĵ�һ���˿��Ʒ����ϣ�Ȼ��С��Ҳ�ó����еĵ�һ���˿���
  ������С�߸մ�����˿��Ƶ����棬�������������˽�����ơ�����ʱ�����ĳ�˴������������ĳ���Ƶ�������ͬ�����ɽ�������ͬ����
  ���м����ȫ�����ߣ������ηŵ��Լ����е��Ƶ�ĩβ��������һ�������ϵ���ȫ������ʱ����һ���˻�ʤ
* ���ķ�
* 2018/9/29
*/

struct queue
{
	int data[1000];
	int head;
	int tail;
};

struct stack
{
	int data[10];
	int top;
};

int main(void)
{
	struct queue q1, q2;
	struct stack s;
	int i = 0;
	int t = 0;
	int book[10];

	//��ʼ������
	q1.head = 1;
	q1.tail = 1;
	q2.head = 1;
	q2.tail = 1;

	//��ʼ��ջ
	s.top = 0;

	for (i = 0; i < 10; i++)
	{
		book[i] = 0;
	}

	//��������в���6����
	//��С��6����
	for (i = 1; i <= 6; i++)
	{
		scanf("%d", &q1.data[q1.tail]);
		q1.tail++;
	}

	//��������в���6����
	//��С��6����
	for (i = 1; i <= 6; i++)
	{
		scanf("%d", &q2.data[q2.tail]);
		q2.tail++;
	}

	//�����в�Ϊ�յ�ʱ��ִ��ѭ��
	while (q1.head < q1.tail && q2.head < q2.tail)
	{
		t = q1.data[q1.head];//С�߳�һ����
		//�ж�С�ߴ�������Ƿ���Ӯ
		if (book[t] == 0)//��������û������Ϊt ����
		{
			q1.head++;
			s.top++;
			s.data[s.top] = t;
			book[t] = 1;
		}
		else
		{
			q1.head++;
			q1.data[q1.tail] = t;
			q1.tail++;
			while (s.data[s.top] != t)
			{
				book[s.data[s.top]] = 0;
				q1.data[q1.tail] = s.data[s.top];
				q1.tail++;
				s.top--;
			}
			

		}

		t = q2.data[q2.head];//С����һ����
		//�ж�С����������Ƿ���Ӯ
		if (book[t] == 0)//��������û������Ϊt ����
		{
			q2.head++;
			s.top++;
			s.data[s.top] = t;
			book[t] = 1;
		}
		else
		{
			q2.head++;
			q2.data[q2.tail] = t;
			q2.tail++;
			while (s.data[s.top] != t)
			{
				book[s.data[s.top]] = 0;
				q2.data[q2.tail] = s.data[s.top];
				q2.tail++;
				s.top--;

			}
			

		}
	}

	if (q2.head == q2.tail)
	{
		printf("С��WIN\n");
		printf("С�����ϻ�ʣ����Ϊ��");
		for (i = q1.head; i <= q1.tail - 1; i++)
		{
			printf(" %d", q1.data[i]);
		}

		if (s.top > 0)
		{
			printf("\n���ϵ����ǣ�");
			for (i = 1; i <= s.top; i++)
			{
				printf(" %d", s.data[i]);
			}
		}
		else
		{
			printf("����û�����ˣ�\n");
		}
	}
	else
	{
		printf("С��WIN\n");
		printf("С�����ϻ�ʣ����Ϊ��");
		for (i = q2.head; i <= q2.tail - 1; i++)
		{
			printf(" %d", q2.data[i]);
		}

		if (s.top > 0)
		{
			printf("\n���ϵ����ǣ�");
			for (i = 1; i <= s.top; i++)
			{
				printf(" %d", s.data[i]);
			}
		}
		else
		{
			printf("����û�����ˣ�\n");
		}
	}

	system("pause");

	return 0;
}
