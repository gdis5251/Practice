#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* �������ڹ�����������Ļ����ϣ��Ը����������Ⱦɫ����ÿ������Ĵ������ֲ�ͬ��
* ���ķ�
* 2018/10/10
*/

int map[51][51], book[51][51];
int n, m;

void dfs(int x, int y, int color)
{
	int tx = 0;
	int ty = 0;
	int k = 0;
	int next[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

	//��(x,y)����Ⱦɫ
	map[x][y] = color;

	for (k = 0; k <= 3; k++)
	{
		tx = x + next[k][0];
		ty = y + next[k][1];

		if (tx < 1 || tx > n || ty < 1 || ty > m)
		{
			continue;
		}

		if (map[tx][ty] > 0 && book[tx][ty] == 0)
		{
			book[tx][ty] = 1;
			dfs(tx, ty, color);
		}

	}
	return;


	

}

int main(void)
{
	
	int i = 0;
	int j = 0;
	//��ʼ��Ⱦɫ����
	int num = 0;

	//�����ͼ��С����ʼ����
	scanf("%d%d", &n, &m);

	//�����ͼ
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	//�Ը����������Ⱦɫ�õ������������������
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (map[i][j] > 0)
			{
				num--;
				book[i][j] = 1;
				dfs(i, j, num);

			}
		}
	}

	//���Ⱦɫ��ĵ�ͼ
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			printf("%3d", map[i][j]);
		}
		printf("\n");
	}

	printf("����%d��С��\n", -num);

	system("pause");

	return 0;

}