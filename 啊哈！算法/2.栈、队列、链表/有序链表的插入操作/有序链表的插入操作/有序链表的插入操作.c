#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* �������Ƕ���������������������ϰ
* ���ķ�
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

	//����n��ֵ�����������м���Ԫ��
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a);

		//��̬����һ���ڴ����洢��һ����㣬������ʱָ��pָ��������
		p = (struct node *)malloc(sizeof(struct node));
		p->data = a;
		p->next = NULL;

		//��β�巨������ʱָ��pָ��Ľ��
		if (head == NULL)
		{
			head = p;

		}
		else
		{
			q->next = p;
		}

		q = p;//��qָ��˽��

	}

	//����������ֵ
	scanf("%d", &a);
	//��ͷָ�뿪ʼ����
	t = head;
	while (t != NULL)
	{
		if (t->next->data > a)
		{
			p = (struct node *)malloc(sizeof(struct node));
			p->data = a;
			p->next = t->next;
			t->next = p;
			break;//���뼴��ϣ��˳�ѭ��
		}
		t = t->next;
	}

	//������н��
	t = head;
	while (t != NULL)
	{
		printf("%d   ", t->data);
		t = t->next;
	}

	system("pause");

	return 0;

}