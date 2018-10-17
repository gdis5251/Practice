#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* ʹ�ù�����ȱ�����������ͼ
* ���ķ�
* 2018/10/17
*/

int main(void)
{
	int i = 0;
	int j = 0;
	int n = 0;
	int m = 0;
	int a = 0;
	int b = 0;
	int cur = 0;
	int book[101] = { 0 };
	int e[101][101] = { 0 };
	int que[10001] = { 0 };
	int head = 1;
	int tail = 1;

	scanf("%d%d", &n, &m);

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j)
			{
				e[i][j] = 0;//ʹi == j �ĵ�Ҳ�����Լ������Լ��ĵ����0
			}
			else
			{
				e[i][j] = 999999; //��Ĭ�����еĵ㶼���ܻ�����ʣ�����Ϊ999999Ϊ������
			}
		}
	}

	for (i = 1; i <= m; i++)
	{
		scanf("%d%d", &a, &b);
		e[a][b] = 1;
		e[b][a] = 1;

	}

	//�Ƚ�1�����ջ
	que[tail] = 1;
	tail++;
	book[1] = 1;

	while (head < tail)
	{
		cur = que[head];

		for (i = 1; i <= n; i++)
		{
			if (e[cur][i] == 1 && book[i] == 0)
			{
				que[tail] = i;
				tail++;
				book[i] = 1;
			}

			if (tail > n)
			{
				break;
			}
		}

		head++;
	}

	for (i = 1; i < tail; i++)
	{
		printf("%d ", que[i]);
	}

	system("pause");
	return 0;

}