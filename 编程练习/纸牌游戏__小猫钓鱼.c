#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 游戏规则是这样的，将一副扑克牌平均分成两份，每人拿一份。小哼先拿出手中的第一张扑克牌放桌上，然后小哈也拿出手中的第一张扑克牌
  并放在小哼刚打出的扑克牌的上面，就像这样两个人交替出牌。出牌时，如果某人打出的牌与桌上某张牌的牌面相同，即可将两张相同的牌
  及中间的牌全部拿走，并依次放到自己手中的牌的末尾。当任意一个人手上的牌全部打完时，另一个人获胜
* 郭文峰
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

	//初始化队列
	q1.head = 1;
	q1.tail = 1;
	q2.head = 1;
	q2.tail = 1;

	//初始化栈
	s.top = 0;

	for (i = 0; i < 10; i++)
	{
		book[i] = 0;
	}

	//依次向队列插入6个数
	//给小哼6张牌
	for (i = 1; i <= 6; i++)
	{
		scanf("%d", &q1.data[q1.tail]);
		q1.tail++;
	}

	//依次向队列插入6个数
	//给小哈6张牌
	for (i = 1; i <= 6; i++)
	{
		scanf("%d", &q2.data[q2.tail]);
		q2.tail++;
	}

	//当队列不为空的时候执行循环
	while (q1.head < q1.tail && q2.head < q2.tail)
	{
		t = q1.data[q1.head];//小哼出一张牌
		//判断小哼打出的牌是否能赢
		if (book[t] == 0)//表明桌上没有牌面为t 的牌
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

		t = q2.data[q2.head];//小哈出一张牌
		//判断小哈打出的牌是否能赢
		if (book[t] == 0)//表明桌上没有牌面为t 的牌
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
		printf("小哼WIN\n");
		printf("小哼手上还剩的牌为：");
		for (i = q1.head; i <= q1.tail - 1; i++)
		{
			printf(" %d", q1.data[i]);
		}

		if (s.top > 0)
		{
			printf("\n桌上的牌是：");
			for (i = 1; i <= s.top; i++)
			{
				printf(" %d", s.data[i]);
			}
		}
		else
		{
			printf("桌上没有牌了！\n");
		}
	}
	else
	{
		printf("小哈WIN\n");
		printf("小哈手上还剩的牌为：");
		for (i = q2.head; i <= q2.tail - 1; i++)
		{
			printf(" %d", q2.data[i]);
		}

		if (s.top > 0)
		{
			printf("\n桌上的牌是：");
			for (i = 1; i <= s.top; i++)
			{
				printf(" %d", s.data[i]);
			}
		}
		else
		{
			printf("桌上没有牌了！\n");
		}
	}

	system("pause");

	return 0;
}
