#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>

/*
��������
��������һ��������n�����n!��ֵ��
  ��������n!=1*2*3*��*n��
	�㷨����
	����n!���ܴܺ󣬶�������ܱ�ʾ��������Χ���ޣ���Ҫʹ�ø߾��ȼ���ķ�����ʹ��һ������A����ʾһ��������a��A[0]��ʾa�ĸ�λ��A[1]��ʾa��ʮλ���������ơ�
	  ������a����һ������k��Ϊ������A��ÿһ��Ԫ�ض�����k����ע�⴦����Ӧ�Ľ�λ��
		�������Ƚ�a��Ϊ1��Ȼ���2����3�����˵�nʱ�����õ���n!��ֵ��
		  �����ʽ
		  �����������һ��������n��n<=1000��
			�����ʽ
			�������n!��׼ȷֵ��
			  ��������
			  10
			  �������
			  3628800
*/

int fac(int n)
{
	if (n < 3)
		return 2;

	return n*fac(n - 1);

}

int main(void)
{
	int n = 0;
	unsigned long long ret = 0;
	printf("Please Input:");
	scanf("%d", &n);

	ret = fac(n);
	printf("%u\n", ret);
	system("pause");
	return 0;
}