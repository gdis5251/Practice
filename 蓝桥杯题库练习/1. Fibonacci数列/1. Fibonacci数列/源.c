#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>

#define MOD 10007
#define MAXN 1000001
int f[MAXN] = { 0 };

int fib(int n)
{
	
	if (n <= 2)
		return 1;
	else
	{
		for (int i = 3; i <= n; i++)
		{
			f[i] = f[i - 1] + f[i - 2];

		}
	}
	return f[n];
}

int main(void)
{
	f[1] = 1;
	f[2] = 1;

	printf("Please Enter :>");
	int n = 0;
	int fi = 0;
	scanf("%d", &n);

	fi = fib(n);
	printf("%d\n", fi % MOD);

	system("pause");
	return 0;
}