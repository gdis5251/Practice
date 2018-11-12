#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* ����һ������ͼ������n�����У�m�����ߡ�
  ��Ҫ�ӳ���start������end��û��ֱ��ĺ��ߣ���Ҫ��������ٵ�ת������
  �˳�����Ҫ�õ������������
* ���ķ�
*2018/10/24
*/

struct note
{
	int x;//���б��
	int s;//ת������
};

int main(void)
{
	int e[51][51] = { 0 };
	int book[51] = { 0 };
	struct note que[2501] = { 0 };
	int i = 0;
	int j = 0;
	int n = 0;
	int m = 0;
	int a = 0;
	int b = 0;
	int start = 0;
	int end = 0;
	int head = 1;
	int tail = 1;
	int cur = 0;
	int flag = 0;

	//������и���n����������m����ʼ����start���յ����end
	scanf("%d%d%d%d", &n, &m, &start, &end);

	//��ʼ���ڽӾ����Լ����Լ���ת������Ϊ0
	//����Ĭ��Ϊ������������99999��ʾ
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j)
				e[i][j] = 0;
			else
				e[i][j] = 99999;
		}
	}

	//�����������Ϣ
 	for (i = 1; i <= m; i++)
	{
		scanf("%d%d", &a, &b);
		e[a][b] = 1;
		e[b][a] = 1;
	}

	//����һ��������Ϣ���
	que[tail].x = start;
	que[tail].s = 0;
	tail++;
	book[start] = 1;

	while (head < tail)
	{
		cur = que[head].x; //��ǰ�����׳��еı��

		for (i = 1; i <= n; i++)
		{
			if (e[cur][i] != 99999 && book[i] == 0)
			{
				que[tail].x = i;
				que[tail].s = que[head].s + 1;
				tail++;
				book[i] = 1;
 			}

			if (que[tail].x == end)
			{
				flag = 1;
				break;
			}

			
		}

		if (flag == 1)
			break;

		head++;
	}

	printf("%d\n", que[tail - 1].s);

	system("pause");
	return 0;
}