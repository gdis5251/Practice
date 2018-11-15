#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>

/*
* ʵ��Hermite Polynomials����ʽ
* ���ķ�
* 2018/11/15
*/

int HermitePolynomials(int n, int x)
{
	if (n <= 0)
		return 1;
	else if (n == 1)
		return 2 * x;
	else
	{
		//ע�ⲻҪ���Լ�(--)��Ϊ��ı�n��ֵ�������nֵ��ı�
		return 2 * x * HermitePolynomials(n - 1, x) - 2 * (n - 1)*HermitePolynomials(n - 2, x);
	}
}

int main(void)
{
	int n = 0;
	int x = 0;
	printf("Please Enter:");
	scanf("%d%d", &n, &x);
	
	int ret = HermitePolynomials(n, x);

	printf("%d\n", ret);

	

	system("pause");
	return 0;
}