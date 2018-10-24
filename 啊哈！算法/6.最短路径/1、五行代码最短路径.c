#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* ��һ������ͼ�У�������������������̳��ȣ�������Ҫ��һ������ȥ����
  ��������һ���㷨ʵ�ָ����ڽӾ���ʵ��������֮������·��
* ���ķ�
* 2018/10/25
*/

int main(void)
{
	int e[51][51] = { 0 };
	int i = 0;
	int j = 0;
	int k = 0;
	int n = 0;
	int m = 0;
	int inf = 99999999999;
	int t1 = 0;
	int t2 = 0;
	int t3 = 0;

	scanf("%d%d", &n, &m);

	//��ʼ���ڽӾ���
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j)
				e[i][j] = 0;
			else
				e[i][j] = inf;
		}
	}

	//�����������֮��ľ���
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &t1, &t2, &t3);
		e[t1][t2] = t3;
	}

	//�����ڽӾ������·��
	//�ֱ�ͨ��K������ȣ�����·��
	for (k = 1; k <= n; k++)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (e[i][j] > e[i][k] + e[k][j])
					e[i][j] = e[i][k] + e[k][j];
			}
		}
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			printf("%3d", e[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}