#define _CRT_SECURE_NO_WARNINGS 1

#include "switch.h"

/*
��������
������n��ʮ��������������������Ƕ�Ӧ�İ˽�������

  �����ʽ
  ������ĵ�һ��Ϊһ��������n ��1<=n<=10����
		������n�У�ÿ��һ����0~9����д��ĸA~F��ɵ��ַ�������ʾҪת����ʮ��������������ÿ��ʮ�����������Ȳ�����100000��

	�����ʽ
		���n�У�ÿ��Ϊ�����Ӧ�İ˽�����������

��ע�⡿
	�����ʮ��������������ǰ��0������012A��
	����İ˽�����Ҳ������ǰ��0��

	��������
		2
		39
		123ABC

	�������
		71
		4435274

����ʾ��
	�Ƚ�ʮ��������ת����ĳ������������ĳ������ת���ɰ˽��ơ�
*/

#define MAXSIZE 6

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
		gets(hex);
		bl = hexToBin(hex, bin);
		ol = binToOct(bin, oct, bl);

		printO(oct, ol);
	}

	system("pause");
	return 0;
}