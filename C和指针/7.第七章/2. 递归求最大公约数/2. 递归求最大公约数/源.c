#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>

/*
* 本程序用递归的方式求最大公约数
				M % N = 0 : N
  gcd(M, N) = 
				M % N = R, R > 0: gcd(N, R)
* 郭文峰
* 2018/11/15
*/

int gcd(int m, int n)
{
	if (m % n == 0) //如果能整数则直接返回除数
		return n;
	else if (m % n > 0)//如果不能整除但余数大于0，说明被除数小于除数，将两数交换
		return gcd(n, (m % n));
}


int main(void)
{
	int m = 0;
	int n = 0;
	printf("Please Enter two numbers:");
	scanf("%d%d", &m, &n);

	int ret = gcd(m, n);
	printf("%d\n", ret);


	system("pause");
	return 0;
}