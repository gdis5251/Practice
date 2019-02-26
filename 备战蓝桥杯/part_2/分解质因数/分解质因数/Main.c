#pragma warning(disable : 4996)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
问题描述
　　求出区间[a,b]中所有整数的质因数分解。
输入格式
　　输入两个整数a，b。
输出格式
　　每行输出一个数的分解，形如k=a1*a2*a3...(a1<=a2<=a3...，k也是从小到大的)(具体可看样例)
样例输入
	3 10
样例输出
	3=3
	4=2*2
	5=5
	6=2*3
	7=7
	8=2*2*2
	9=3*3
	10=2*5
提示
　　先筛出所有素数，然后再分解。
数据规模和约定
　　2<=a<=b<=10000
*/

//判断该数是否是素数
int isPrimeNum(int num)
{
	int i = 0;
	for (i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0)
			return 0;
	}

	return 1;
}

//打印
void Print(int a, int b)
{
	for (int i = a; i <= b; i++)
	{
		//先判断是否是素数
		if (isPrimeNum(i) == 1)
		{//如果是素数直接打印
			printf("%d=%d\n", i, i);
		}
		else
		{//如果不是素数，进行因数打印形式打印 8
			printf("%d=", i);

			int j = i;
			int k = 2;
			while (!isPrimeNum(j))
			{
				
				if (j % k == 0)
				{
					printf("%d*", k);

					j /= k;
				}
				else
					k++;
			}
			printf("%d\n", j);
		}
	}
}

int main(void)
{
	int a = 0;
	int b = 0;

	scanf("%d%d", &a, &b);
	
	//判断a与b的取值是否符合条件
	if (a < 2 || b < 2 || a > 10000 || b > 10000 || a > b)
		exit(EXIT_FAILURE);

	Print(a, b);

	system("pause");
	return 0;
}