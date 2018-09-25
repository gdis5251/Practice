#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("请输入三角形的三条边：");
	int a, b, c;
	int iscontinue = 1;
	while (iscontinue)
	{
		scanf("%d%d%d", &a, &b, &c);
		if (a + b > c && a + c > b && b + c > a && a - b < c && a - c < b && b - c < a)
		{
			if (a == b && b == c && a == c)
				printf("该三角形为等边三角形！");
			else if (a == b || b == c || a == c)
				printf("该三角形为等腰三角形！");
			else
				printf("该三角形为不等边三角形！");
			iscontinue = 0;
		}
		else
			printf("请正确输入三个数字:");
	}
	system("pause");
	return 0;

}