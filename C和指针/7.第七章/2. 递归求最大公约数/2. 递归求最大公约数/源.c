#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>

/*
* �������õݹ�ķ�ʽ�����Լ��
				M % N = 0 : N
  gcd(M, N) = 
				M % N = R, R > 0: gcd(N, R)
* ���ķ�
* 2018/11/15
*/

int gcd(int m, int n)
{
	if (m % n == 0) //�����������ֱ�ӷ��س���
		return n;
	else if (m % n > 0)//���������������������0��˵��������С�ڳ���������������
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