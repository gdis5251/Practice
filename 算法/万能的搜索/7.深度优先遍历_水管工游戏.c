#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* ����������ʵ�ֹܵ���Ϸ����ͼ���棬��1��2��3��4��5��6���ֱ��ʾ6�йܵ�����״
  ��1��2��3��4�ֱ�����ʾ���ϡ��ҡ����ĸ����ڷ���
* ���ķ�
* 2018/10/11
*/

int map[51][51], book[51][51];
int n, m, flag;

struct note
{
	int x;
	int y;
}s[100];
int top;

void dfs(int x, int y, int front)
{
	int i = 0;
	//�ж��Ƿ񵽴��յ㣬y = m + 1��Ϊ�����Ὣ�ܿڶ�������
	if (x == n && y == m + 1)
	{
		flag = 1;//�ҵ����跽��
		for (i = 1; i <= top; i++)
		{
			printf("(%d,%d)  ", s[i].x, s[i].y);
		}
		return;
	}

	//�ж��Ƿ�Խ��
	if (x < 1 || x > n || y < 1 || y > m)
	{
		return;
	}

	//�ж�����ܵ��Ƿ��ù�
	if (book[x][y] == 1)
	{
		return;
	}
	book[x][y] = 1;

	//��ջ
	top++;
	s[top].x = x;
	s[top].y = y;

	//�õ�ֱˮ�ܵ����
	//1��2��3��4�ֱ��ʾ��ˮ�������ϡ��ҡ��µ����
	if (map[x][y] >= 5 && map[x][y] <= 6)
	{
		if (1 == front)
		{
			dfs(x, y + 1, 1);
		}
		if (2 == front)
		{
			dfs(x + 1, y, 2);
		}
		if (3 == front)
		{
			dfs(x, y - 1, 3);
		}
		if (4 == front)
		{
			dfs(x - 1, y, 4);
		}
	}


	//����ˮ������ܵ����
	if (map[x][y] >= 1 && map[x][y] <= 4)
	{
		//ÿһ�ν��ڻ���������ܶ�Ӧ
		if (1 == front)
		{
			dfs(x + 1, y, 2);
			dfs(x - 1, y, 4);
		}
		if (2 == front)
		{
			dfs(x, y + 1, 1);
			dfs(x, y - 1, 3);
		}
		if (3 == front)
		{
			dfs(x - 1, y, 4);
			dfs(x + 1, y, 2);

		}
		if (4 == front)
		{
			dfs(x, y + 1, 1);
			dfs(x, y - 1, 3);
		}
	}

	book[x][y] = 0;
	top--;//��ջ
	return;
}
int main()
{
	int i = 0;
	int j = 0;

	scanf("%d%d", &n, &m);

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	//��ʼ��������1,1��ʼ���������Ϊ���
	dfs(1, 1, 1);

	if (0 == flag)
	{
		printf("impossible!\n");
	}

	system("pause");
	return 0;
}