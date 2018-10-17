#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* ʹ�������������������һ������ͼ
* ���ķ�
* 2018/10/17
*/
int n, m, sum;
int book[101], e[101][101];

void dfs(int cur)
{
	int i = 0;
	printf("%d ", cur);//�����ǰ��

	sum++;
	if (sum == n)//������������еĵ��򷵻�
	{
		return;
	}

	for (i = 1; i <= n; i++)
	{
		if (e[cur][i] == 1 && book[i] == 0)//���cur��㵽i��������������Ϊ�Ѿ�����
		{									//�ҵݹ����i���
			book[i] = 1;
			dfs(i);
		}
	}
	return;
}

int main(void)
{
	int i = 0;
	int j = 0;
	int a = 0;
	int b = 0;
	
	//��һ����ά����e[][]���洢һ������ͼ
	//�����������ͼ���м�������
	scanf("%d%d", &n, &m);

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (i == j)
			{
				e[i][j] = 0;		//��ά��������0�����Լ����Լ�
			}
			else
			{
				e[i][j] = 999999999; //��ά��������999999999����ʾ������
			}
		}
	}

	for (i = 1; i <= n; i++)
	{
		scanf("%d%d", &a, &b);
		e[a][b] = 1;
		e[b][a] = 1; //��Ϊ������ͼ������˫�򶼵���1
	}

	book[1] = 1;//1�ű���Ѿ�����
	dfs(1);//��1�Ŷ��㿪ʼ����

	system("pause");
	return 0;
}