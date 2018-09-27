#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* 本程序是判断回文字符串，目的是了解栈的基本操作
* 郭文峰
* 2018/9/27
*/

int main(void)
{
	int i = 0;
	char a[100] = { 0 };
	char s[100] = { 0 };
	int top = 0;
	int next = 0;
	int mid = 0;
	int len = 0;

	gets(a);//读取一串字符串

	len = strlen(a);

	mid = len / 2 - 1;

	for (i = 0; i <= mid; i++)
	{
		s[++top] = a[i];
	}

	if (len % 2 == 0)
	{
		next = mid + 1;
	}
	else
	{
		next = mid + 2;
	}

	for (i = next; i <= len - 1; i++)
	{
		if (a[i] != s[top])
		{
			break;
		}
		else
		{
			top--;
		}
	}

	if (top == 0)
	{
		printf("YES!");
	}
	else
	{
		printf("NO");
	}

	system("pause");
	return 0;
}