#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>

int GetSum(int n)
{
	int i_ = 1;
	int sum_ = 0;
	for (; i_ <= n; i_++)
	{
		sum_ += i_;
	}
	return sum_;
}

int main(void)
{
	int n = 0;
	int sum = 0;

	printf("Please Enter :>");
	scanf("%d", &n);

	sum = GetSum(n);
	printf("Sum = %d\n", sum);

	system("pause");
	return 0;
}