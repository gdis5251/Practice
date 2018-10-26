#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* �������ڶ�BellmanFord�㷨�����˶��е��Ż�
* ���ķ�
* 2018/10/26
*/

int main(void)
{
	int dis[10] = { 0 };
	int i = 0;
	int k = 0;
	int n = 0;
	int m = 0;
	int head = 1;
	int tail = 1;
	int que[101] = { 0 };
	int first[10] = { 0 };
	int next[10] = { 0 };
	int u[10] = { 0 };
	int v[10] = { 0 };
	int w[10] = { 0 };
	int book[10] = { 0 };
	int inf = 99999;


	scanf("%d%d", &n, &m);

	for (i = 1; i <= n; i++)
	{
		dis[i] = inf;
	}
	dis[1] = 0;

	//��ʼ��first����
	for (i = 1; i <= n; i++)
	{
		first[i] = -1;
	}

	for (i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
		//�����ڽӱ�
		next[i] = first[u[i]];
		first[u[i]] = i;
	}

	//��һ�Ŷ������
	que[tail] = 1;
	tail++;
	book[1] = 1;

	while (head < tail)
	{
		k = first[que[head]];//��ǰ��Ҫ����Ķ��׶���
		//ɨ�赱ǰ��������б�
		while (k != -1)
		{
			if (dis[v[k]] > dis[u[k]] + w[k])//�жϱ��Ƿ�����ɳڵ�����
			{
				dis[v[k]] = dis[u[k]] + w[k];//����

				if (book[v[k]] == 0)
				{
					que[tail] = v[k];
					tail++;
					book[v[k]] = 1;

				}
			}
			k = next[k];
		}
		book[que[head]] = 0;
		head++;
	}

	//���һ�Ŷ��㵽�������������·��
	for (i = 1; i <= n; i++)
	{
		printf("%d ", dis[i]);
	}

	system("pause");
	return 0;
}





