#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
*  ʵ������ͼ��������ȱ������ҵ�һ�����㵽��һ����������·��
   ע��˳�����ɵ��� 1 ���㵽 n �������̾���
*  ���ķ�
*  2018/10/17
*/

int min = 999999;
int n = 0;
int m = 0;
int book[101] = { 0 };
int e[101][101] = { 0 };

void dfs(int cur, int dis)
{
	int i = 0;
	
	//�����ݹ����������
	//�������Ѿ�������С����ֱ������
	if (dis > min)
	{
		return;
	}

	//������յ�
	if (cur == n) //�˴��� n ���� 1 ���㵽 n �������̾��� 
		          // ����ͨ����׼���������� n �Ĵ�С
	{
		//������С����С���룬�� dis ��ֵ���� min
		if (dis < min)
		{
			min = dis;
			return;
		}
	}

	for (i = 1; i <= n; i++)
	{
		//�жϵ�ǰcur���㵽 i �����Ƿ���·�����ж� i �Ƿ������ߵ�·����
		if (e[cur][i] != 999999 && book[i] == 0)
		{
			book[i] = 1;
			dfs(i, dis + e[cur][i]); //�� i �ٳ���������Ѱ��Ŀ��
			book[i] = 0;//֮ǰһ��̽�����֮��ȡ���Գ��� i �ı��
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
	int c = 0;


	//�����ڽӾ���Ĵ�С
	scanf("%d%d", &n, &m);
	//���ڽӾ����ʼ��
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j)
			{
				e[i][j] = 0;
			}
			else
			{
				e[i][j] = 999999;
			}
		}
	}

	for (i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		e[a][b] = c; //����a������b�ĳ�����c
	}

	book[1] = 1;
	dfs(1, 0);

	printf("%d\n", min);

	system("pause");
	return 0;
}