#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("�����������ε������ߣ�");
	int a, b, c;
	int iscontinue = 1;
	while (iscontinue)
	{
		scanf("%d%d%d", &a, &b, &c);
		if (a + b > c && a + c > b && b + c > a && a - b < c && a - c < b && b - c < a)
		{
			if (a == b && b == c && a == c)
				printf("��������Ϊ�ȱ������Σ�");
			else if (a == b || b == c || a == c)
				printf("��������Ϊ���������Σ�");
			else
				printf("��������Ϊ���ȱ������Σ�");
			iscontinue = 0;
		}
		else
			printf("����ȷ������������:");
	}
	system("pause");
	return 0;

}