#define _CRT_SECURE_NO_WARNINGS 1

#include "switch.h"

/*
问题描述
　给定n个十六进制正整数，输出它们对应的八进制数。

  输入格式
  　输入的第一行为一个正整数n （1<=n<=10）。
		接下来n行，每行一个由0~9、大写字母A~F组成的字符串，表示要转换的十六进制正整数，每个十六进制数长度不超过100000。

	输出格式
		输出n行，每行为输入对应的八进制正整数。

【注意】
	输入的十六进制数不会有前导0，比如012A。
	输出的八进制数也不能有前导0。

	样例输入
		2
		39
		123ABC

	样例输出
		71
		4435274

【提示】
	先将十六进制数转换成某进制数，再由某进制数转换成八进制。
*/

#define MAXSIZE 100000

int main(void)
{
	char hex[MAXSIZE] = { 0 };
	char bin[MAXSIZE * 4] = { 0 };
	char oct[MAXSIZE * 4 / 3 + 1] = { 0 };
	int i = 0;
	int n = 0;	
	int bl = 0;
	int ol = 0;
	scanf("%d", &n);


	for (i = 0; i < n; i++)
	{
		scanf("%s", hex);

		bl = hexToBin(hex, bin);
		ol = binToOct(bin, oct, bl);

		printO(oct, ol);
	}

	system("pause");
	return 0;
}