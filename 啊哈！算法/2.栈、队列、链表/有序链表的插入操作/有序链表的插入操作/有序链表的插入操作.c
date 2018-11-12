#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 本程序是对于有序链表插入操作的练习
* 郭文峰
* 2018/9/30
*/

struct node
{
	int data;
	struct node *next;
};

int main(void)
{
	struct node *head = NULL;
	struct node *p = NULL;
	struct node *q = NULL;
	struct node *t = NULL;

	int i = 0;
	int a = 0;
	int n = 0;

	//输入n的值，代表链表有几个元素
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a);

		//动态申请一个内存来存储下一个结点，并用临时指针p指向这个结点
		p = (struct node *)malloc(sizeof(struct node));
		p->data = a;
		p->next = NULL;

		//用尾插法插入临时指针p指向的结点
		if (head == NULL)
		{
			head = p;

		}
		else
		{
			q->next = p;
		}

		q = p;//让q指向此结点

	}

	//输入带插入的值
	scanf("%d", &a);
	//从头指针开始遍历
	t = head;
	while (t != NULL)
	{
		if (t->next->data > a)
		{
			p = (struct node *)malloc(sizeof(struct node));
			p->data = a;
			p->next = t->next;
			t->next = p;
			break;//插入即完毕，退出循环
		}
		t = t->next;
	}

	//输出所有结点
	t = head;
	while (t != NULL)
	{
		printf("%d   ", t->data);
		t = t->next;
	}

	system("pause");

	return 0;

}