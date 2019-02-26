#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
问题描述
　　给定两个仅由大写字母或小写字母组成的字符串(长度介于1到10之间)，它们之间的关系是以下4中情况之一：
　　1：两个字符串长度不等。比如 Beijing 和 Hebei
　　2：两个字符串不仅长度相等，而且相应位置上的字符完全一致(区分大小写)，比如 Beijing 和 Beijing
　　3：两个字符串长度相等，相应位置上的字符仅在不区分大小写的前提下才能达到完全一致（也就是说，它并不满足情况2）。比如 beijing 和 BEIjing
　　4：两个字符串长度相等，但是即使是不区分大小写也不能使这两个字符串一致。比如 Beijing 和 Nanjing
　　编程判断输入的两个字符串之间的关系属于这四类中的哪一类，给出所属的类的编号。
输入格式
　　包括两行，每行都是一个字符串
输出格式
　　仅有一个数字，表明这两个字符串的关系编号
样例输入
	BEIjing
	beiJing
样例输出
	3
*/
int strDiffer(char *str1, char *str2)
{
	//1、先比较两个字符串长度是否相等
	int len_str1 = strlen(str1);
	int len_str2 = strlen(str2);

	if (len_str1 != len_str2)
		return 1;

	//2、两个字符串完全相同
	if (strcmp(str1, str2) == 0)
		return 2;

	//3、两个字符串在不区分大小写的情况下完全一致
	for (int i = 0; i < len_str1; i++)
	{
		if (isupper(str1[i]) == 1)
			str1[i] = tolower(str1[i]);
		if (isupper(str2[i]) == 1)
			str2[i] = tolower(str2[i]);
	}
	if (strcmp(str1, str2) == 0)
		return 3;

	//4、两个字符串不一样
	return 4;
}




int main(void)
{
	char str1[10] = { 0 };
	char str2[10] = { 0 };

	scanf("%s", str1);
	scanf("%s", str2);

	printf("%d\n", strDiffer(str1, str2));

	system("pause");
	return 0;
}