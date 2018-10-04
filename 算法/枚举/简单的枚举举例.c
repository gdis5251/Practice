#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 本程序用来初次认识枚举法 计算一道数学题 *** + *** = *** 将数字1~9 分别填入 每个数字只能出现一次，使等式成立。
* 郭文峰
* 2018/10/4
*/

int main(void)
{
	int a[10] = { 0 };
	int i = 0;
	int book[10] = { 0 };
	int sum = 0;
	int total = 0;

	for (a[1] = 1; a[1] <= 9; a[1]++)
		for (a[2] = 1; a[2] <= 9; a[2]++)
			for (a[3] = 1; a[3] <= 9; a[3]++)
				for (a[4] = 1; a[4] <= 9; a[4]++)
					for (a[5] = 1; a[5] <= 9; a[5]++)
						for (a[6] = 1; a[6] <= 9; a[6]++)
							for (a[7] = 1; a[7] <= 9; a[7]++)
								for (a[8] = 1; a[8] <= 9; a[8]++)
									for (a[9] = 1; a[9] <= 9; a[9]++)
									{
										//初始化book数组
										for (i = 1; i <= 9; i++)
										{
											book[i] = 0;
										}
										//标记出现过的数字
										for (i = 1; i <= 9; i++)
										{
											book[a[i]] = 1;
											
										}
										//如果所有数字都出现了，开始判断等式是否成立
										sum = 0;
										for (i = 1; i <= 9; i++)
										{
											sum += book[i];
										}
										if (sum == 9 && a[1] * 100 + a[2] * 10 + a[3] + a[4] * 100 + a[5] * 10 + a[6] == a[7] * 100 + a[8] * 10 + a[9])
										{
											total++;
											printf("%d%d%d + %d%d%d = %d%d%d\n", a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);

										}
									}
	printf("total = %d\n", total / 2);

	system("pause");

	return 0;
}