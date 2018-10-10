#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* һ�ŵ�ͼ����һ��������һЩ����������ɣ������ķɻ�Ҫ�����ڣ�6.8�������������������ĵ����
* ���ķ�
* 2018/10/10
*/

struct note
{
	int x;
	int y;
};

int main(void)
{
	int map[51][51] = { 0 };
	int book[51][51] = { 0 };
	int n, m, i, j, k, startx, starty, tx, ty, sum = 0;
	int head = 1;
	int tail = 1;
	struct note que[2501];

	int next[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

	//�����ͼ��С����ʼ����
	scanf("%d%d%d%d", &n, &m, &startx, &starty);

	//�����ͼ
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	//��ʼ�������
	que[tail].x = startx;
	que[tail].y = starty;
	tail++;
	book[startx][starty] = 1;
	sum = 1;

	while (head < tail)
	{
		for (k = 0; k <= 3; k++)
		{
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];

			if (tx < 1 || tx > n || ty < 1 || ty > m)
			{
				continue;
			}

			if (map[tx][ty] > 0 && book[tx][ty] == 0)
			{
				sum++;
				book[tx][ty] = 1;
				que[tail].x = tx;
				que[tail].y = ty;
				tail++;
			}
		}
		head++;
	}

	printf("%d\n", sum);

	system("pause");

	return 0;

}