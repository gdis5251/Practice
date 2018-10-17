#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 现有m根火柴（m<=24）希望拼出A+B=C的等式。等式中的A、B、C均是由火柴棍拼出来的（若该数非零，则第一位不能为0）
  加号与等号各自需要两根火柴
  如果A！=B，则A+B=C与B+A=C视为不同的等式（A、B、C都大于0）
  所有火柴棍均大于0
* 郭文峰
* 2018/10/8
*/
int fun(x)
{
	int num = 0;
	int f[] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };//初始化数组，记录每个数字所需要的火柴个数

	while (x / 10 != 0) //如果x商10不等于0，说明至少有两位数
	{
		//将末尾的数所需要的火柴棍个数加到num中
		num += f[x % 10];
		x = x / 10;
	}

	num += f[x];
	return num;


}

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int sum = 0;
	int m = 0;

	//输入需要多少根火柴
	scanf("%d", &m);

	//枚举A、B
	for (a = 0; a <= 1111; a++)
	{
		for (b = 0; b <= 1111; b++)
		{
			c = a + b; //用这种方式可以省掉枚举C，优化代码复杂度

			if (fun(a) + fun(b) + fun(c) == m-4)
			{
				printf("%d + %d = %d\n", a, b, c);
				sum++;
			}
		}
	}

	printf("一共有%d个等式！\n", sum);

	system("pause");

	return 0;
}
