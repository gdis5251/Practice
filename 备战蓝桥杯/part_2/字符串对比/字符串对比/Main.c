#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
��������
���������������ɴ�д��ĸ��Сд��ĸ��ɵ��ַ���(���Ƚ���1��10֮��)������֮��Ĺ�ϵ������4�����֮һ��
����1�������ַ������Ȳ��ȡ����� Beijing �� Hebei
����2�������ַ�������������ȣ�������Ӧλ���ϵ��ַ���ȫһ��(���ִ�Сд)������ Beijing �� Beijing
����3�������ַ���������ȣ���Ӧλ���ϵ��ַ����ڲ����ִ�Сд��ǰ���²��ܴﵽ��ȫһ�£�Ҳ����˵���������������2�������� beijing �� BEIjing
����4�������ַ���������ȣ����Ǽ�ʹ�ǲ����ִ�СдҲ����ʹ�������ַ���һ�¡����� Beijing �� Nanjing
��������ж�����������ַ���֮��Ĺ�ϵ�����������е���һ�࣬������������ı�š�
�����ʽ
�����������У�ÿ�ж���һ���ַ���
�����ʽ
��������һ�����֣������������ַ����Ĺ�ϵ���
��������
	BEIjing
	beiJing
�������
	3
*/
int strDiffer(char *str1, char *str2)
{
	//1���ȱȽ������ַ��������Ƿ����
	int len_str1 = strlen(str1);
	int len_str2 = strlen(str2);

	if (len_str1 != len_str2)
		return 1;

	//2�������ַ�����ȫ��ͬ
	if (strcmp(str1, str2) == 0)
		return 2;

	//3�������ַ����ڲ����ִ�Сд���������ȫһ��
	for (int i = 0; i < len_str1; i++)
	{
		if (isupper(str1[i]) == 1)
			str1[i] = tolower(str1[i]);
		if (isupper(str2[i]) == 1)
			str2[i] = tolower(str2[i]);
	}
	if (strcmp(str1, str2) == 0)
		return 3;

	//4�������ַ�����һ��
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