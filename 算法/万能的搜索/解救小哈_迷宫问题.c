#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* �Թ���n��m�еĵ�Ԫ����ɣ�n��m��С�ڵ���50����ÿ����Ԫ��Ҫô�ǿյأ�Ҫô���ϰ��
  �ҵ�һ�����Թ�����㵽�յ�����·����0��ʾ�յأ�1��ʾ�ϰ��
* ���ķ�
* 2018/10/9
*/

int n, m;//��ͼ��С����
int p, q;//�յ��������
int min = 99999;//������¼���·��
int map[51][51];//�ö�ά����洢��ͼ
int book[51][51];//��¼�߹�������

void dfs(int x, int y, int step)
{
	int tx, ty, k;

	int next[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };//���ҡ��¡�������

	//������յ㣬�ж��Ƿ������·��
	if (x == p && y == q)
	{
		if (step < min)
		{
			min = step;

		}
		return;
	}

	for (k = 0; k <= 3; k++)
	{
		//������һ������
		tx = x + next[k][0];
		ty = y + next[k][1];

		//�ж��Ƿ�Խ��
		if (tx < 1 || tx > n || ty < 1 || ty > m)
		{
			continue;
		}

		if (map[tx][ty] == 0 && book[tx][ty] == 0)
		{
			book[tx][ty] = 1;
			dfs(tx, ty, step + 1);
			book[tx][ty] = 0;
		}
	}
	return;
}

int main(void)
{
	int startx = 0;
	int starty = 0;//��ʼ����
	int i = 0;
	int j = 0;

	scanf("%d%d", &n, &m);//�����ͼ�Ĵ�С

	for (i = 1; i <= n; i++)//�����ͼ
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	scanf("%d%d%d%d", &startx, &starty, &p, &q);//�������������յ�����

	book[startx][starty] = 1;

	dfs(startx, starty, 0);

	printf("%d\n", min);

	system("pause");

	return 0;
}