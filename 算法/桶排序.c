#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, j, t;
	int book[10];
	for (i = 0; i < 10; i++)
	{
		book[i] = 0;
	}
	printf("������5�����������򽫻����������ִ�С��������Ͱ���򷨣�");
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &t);
		book[t]++;
	}
	for (i = 0; i < 10; i++)
		for (j = 1; j <= book[i]; j++)
			printf("%d   ", i);
	system("pause");
	return 0;
}