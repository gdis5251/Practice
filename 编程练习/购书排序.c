#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* ͼ��ݽ�Ҫ���飬Ҫ����N��ͬѧ��˵�Լ���Ҫʲô�顣
  ÿ����ֻ��һ������Ҫ�����ISBN�Ŵ�С��������
  �˷���Ϊ�򵥵�Ͱ���򣬼ȿ���ȥ�أ��ֿ�������
  �������ISBN����1~1000֮�ڡ�
* ���ķ�
* 2018/9/26
*/

int main(void)
{
	int i = 0;
	int n = 0;
	int a[1001] = {0};
	int t = 0;
	int count = 0;

	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		scanf("%d", &t);
		a[t] = 1;
	}

	for (i = 1; i <= 1000; i++)
	{
		if (a[i] == 1)
		{
			printf("%d ", i);
			count++;
		}
	}

	printf("\n");
	printf("%d\n", count);

	system("pause");
	return 0;
}