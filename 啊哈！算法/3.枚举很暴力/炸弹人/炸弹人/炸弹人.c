#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* ����������ģ��ը������Ϸ���ֶ�����һ����ͼ ��#����ʾǽ����.����ʾ�յأ���G'��ʾ���ˡ��ҳ�����������������Ǹ��㡣
* ���ķ�
* 2018/10/4
*/

int main(void)
{
	char a[20][21];
	int x, y, i, j, map = 0, sum, p, q, n, m;

	//ȷ����ͼ�Ĵ�С
	scanf("%d%d", &n, &m);

	//�����ͼ
	for (i = 0; i <= n - 1; i++)
	{
		scanf("%s", &a[i]);
	}

	//��˫��ѭ��ö�ٵ�ͼ�ϵ�ÿһ����
	for (i = 0; i <= n - 1; i++)
	{
		for (j = 0; j <= m - 1; j++)
		{
			if (a[i][j] == '.')
			{
				sum = 0;
				x = i;
				y = j;

				while (a[x][y] != '#')
				{
					if (a[x][y] == 'G')
						sum++;
					x--;
					
				}
				x = i;
				y = j;

				while (a[x][y] != '#')
				{
					if (a[x][y] == 'G')
						sum++;
					x++;
					
				}
				x = i;
				y = j;

				while (a[x][y] != '#')
				{
					if (a[x][y] == 'G')
						sum++;
					y--;
					
				}
				x = i;
				y = j;

				while (a[x][y] != '#')
				{
					if (a[x][y] == 'G')
						sum++;
					y++;
					
				}
				
				if (sum > map)
				{
					map = sum;
					p = i;
					q = j;
				}
					
				
			}
		}
	}
	printf("(%d,%d)���������%d���ĵ���", p, q, map);

	system("pause");

	return 0;
}