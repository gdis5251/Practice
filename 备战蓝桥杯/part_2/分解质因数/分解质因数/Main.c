#pragma warning(disable : 4996)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
��������
�����������[a,b]�������������������ֽ⡣
�����ʽ
����������������a��b��
�����ʽ
����ÿ�����һ�����ķֽ⣬����k=a1*a2*a3...(a1<=a2<=a3...��kҲ�Ǵ�С�����)(����ɿ�����)
��������
	3 10
�������
	3=3
	4=2*2
	5=5
	6=2*3
	7=7
	8=2*2*2
	9=3*3
	10=2*5
��ʾ
������ɸ������������Ȼ���ٷֽ⡣
���ݹ�ģ��Լ��
����2<=a<=b<=10000
*/

//�жϸ����Ƿ�������
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

//��ӡ
void Print(int a, int b)
{
	for (int i = a; i <= b; i++)
	{
		//���ж��Ƿ�������
		if (isPrimeNum(i) == 1)
		{//���������ֱ�Ӵ�ӡ
			printf("%d=%d\n", i, i);
		}
		else
		{//�����������������������ӡ��ʽ��ӡ 8
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
	
	//�ж�a��b��ȡֵ�Ƿ��������
	if (a < 2 || b < 2 || a > 10000 || b > 10000 || a > b)
		exit(EXIT_FAILURE);

	Print(a, b);

	system("pause");
	return 0;
}