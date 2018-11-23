#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>

int main(void)
{

	int x = 0;
	scanf("%x", &x);

	printf("%o\n", x);

	system("pause");
	return 0;

}