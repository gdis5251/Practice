#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* Dijkstra�㷨��ͨ�����ɳ������·��
* ���ķ�
* 2018/10/25
*/

int main(void)
{
	int e[51][51] = { 0 };
	int book[51] = { 0 };
	int dis[50] = { 0 };
	int inf = 999999999;
	int i = 0;
	int j = 0;
	int n = 0;
	int m = 0;
	int t1 = 0;
	int t2 = 0;
	int t3 = 0;
	int min = 0;
	int u = 0;
	int v = 0;

	//��������ͼ��n�������m����
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

	//�����������֮��ߵĳ���
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &t1, &t2, &t3);
		e[t1][t2] = t3;
	}

	//��ʼ��dis����
	for (i = 1; i <= n; i++)
		dis[i] = e[1][i];


	book[1] = 1;

	//�㷨���Ĳ���
	for (i = 1; i <= n - 1; i++)
	{
		//�ҵ���Դ�������һ����
		min = inf;
		for (j = 1; j <= n; j++)
		{
			if (dis[j] < min && book[j] == 0)
			{
				min = dis[j];
				u = j;
			}
		}
		//���u��
		book[u] = 1;

		//�������·��
		for (v = 1; v <= n; v++)
		{
			
			if (dis[v] > dis[u] + e[u][v])
			{
				dis[v] = dis[u] + e[u][v];
			}
			
		}
	}

	for (i = 1; i <= n; i++)
	{
		printf("%d ", dis[i]);
	}

	system("pause");
	return 0;
}