#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* ���������ù�����������ķ�������һ�ν�������С����������
* ���ķ�
* 2018/10/9
*/

struct note
{
	int x;
	int y;
	int s;
};

int main(void)
{
	struct note que[2501];
	//��ʼ����ͼ�ͱ������
	int map[51][51] = { 0 };
	int book[51][51] = { 0 };
	int i = 0;
	int j = 0;
	int k = 0;
	//��ʼ����ʼ�������
	int startx = 0;
	int starty = 0;
	//��ʼ���յ��������
	int p = 0;
	int q = 0;
	//��ʼ��ջͷ��ջβ
	int head = 1;
	int tail = 1;
	//��ʼ����ͼ��С����
	int n = 0;
	int m = 0;
	//��ʼ����������
	int next[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
	//��ʼ����һ���������
	int tx = 0;
	int ty = 0;

	int flag = 0;

	scanf("%d%d", &n, &m);
	//�����ͼ
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	//������ʼ������յ�����
	scanf("%d%d%d%d", &startx, &starty, &p, &q);

	//��ʼ��ջ
	que[tail].x = startx;
	que[tail].y = starty;
	que[tail].s = 0;
	tail++;

	book[startx][starty] = 1;

	while (head < tail)
	{
		for (k = 0; k <= 3; k++)
		{
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];

			//�ж��Ƿ�Խ��
			if (tx < 1 || tx > n || ty < 1 || ty > m)
			{
				continue;
			}

			//�ж���һ���Ƿ����
			if (map[tx][ty] == 0 && book[tx][ty] == 0)
			{
				book[tx][ty] = 1;
				que[tail].x = tx;
				que[tail].y = ty;
				que[tail].s = que[head].s + 1;
				tail++;

			}
		
			if (tx == p && ty == q)
			{
				flag = 1;
				break;
			}
		}
		
		if (1 == flag)
		{
			break;
		}
		head++;
	}

	printf("%d\n", que[tail - 1].s);


	system("pause");

	return 0;
}