#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* ������ԡ�ö�١��½���򵥵�ö�پ�����������������������Ż�
* ���ķ�
* 2018/10/8
*/

int a[10], book[10], total = 0;

void dfs(int step)
{
	int i = 0;

	if (10 == step)
	{
		if (a[1] * 100 + a[2] * 10 + a[3] + a[4] * 100 + a[5] * 10 + a[6] == a[7] * 100 + a[8] * 10 + a[9])
		{
			total++;
			printf("%d%d%d + %d%d%d = %d%d%d\n", a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
		}
		return;
	}
	for (i = 1; i <= 9; i++)
	{
		if (0 == book[i])
		{
			a[step] = i;
			book[i] = 1;

			dfs(step + 1);
			book[i] = 0;
		}
	}
	return;
}

int main(void)
{
	
	dfs(1);

	printf("total=%d\n", total / 2);

	system("pause");

	return 0;
}