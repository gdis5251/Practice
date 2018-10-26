#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* ��������BellmanFord�㷨�����·����
  �õ����ڽӱ���������ֱ�Ϊu[]��v[]��w[]��
  chenk���ж��Ƿ���½�����
  flag���ж��Ƿ��и�Ȩֵ��
* ���ķ�
* 2018/10/26
*/

int main(void)
{
	int dis[10] = { 0 };
	int bak[10] = { 0 };
	int i = 0;
	int j = 0;
	int k = 0;
	int check = 0;
	int flag = 0;
	int n = 0;
	int m = 0;
	int u[10] = { 0 };
	int v[10] = { 0 };
	int w[10] = { 0 };
	int inf = 999999999;

	//����n�������m����
	scanf("%d%d", &n, &m);

	//�������ݽ����ڽӱ�
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &u[i], &v[i], &w[i]);

	}

	//��ʼ��dis����
	for (i = 1; i <= n; i++)
	{
		dis[i] = inf;
	}
	dis[1] = 0;

	for (k = 1; k <= n - 1; k++)
	{
		//����bak�������dis����
		for (i = 1; i <= n; i++)
		{
			bak[i] = dis[i];
		}

		//�������·��
		for (j = 1; j <= m; j++)
		{
			if (dis[v[j]] > dis[u[j]] + w[j])
				dis[v[j]] = dis[u[j]] + w[j];
		}

		check = 0;
		//�ж��Ƿ����
		for (i = 1; i <= n; i++)
		{
			if (bak[i] != dis[i])
			{
				check = 1;
				break;
			}
		}
		if (check == 0)
			break;

	}

	//�ж��Ƿ��и�Ȩֵ
	for (j = 1; j <= m; j++)
	{
		if (dis[v[j]] > dis[u[j]] + w[j])
			flag = 1;
	}

	if (flag == 1)
		printf("�и�Ȩֵ��");
	else
	{
		for (i = 1; i <= n; i++)
		{
			printf("%d ", dis[i]);
		}
	}

	system("pause");
	return 0;
}