#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>
#include <string.h>


/*
* ��дһ�����򣬴ӱ�׼�����ȡ�ַ�����������д����׼����С����з���ĸ���ַ�����������������ʽ�������ĸ�ַ������ǰ���м��ܡ�
  ���ܷ����ܼ򵥣�ÿ����ĸ���޸�Ϊ����ĸ���Ͼ���13��λ�ã�ǰ��󣩵���ĸ��
  ���磬A���޸�ΪN��Z���޸�ΪM��
  ע���Сд��Ӧ�ñ�ת����
* ���ķ�
* 2018/11/7
*/

int main(void)
{
	int ch = 0;

	while ((ch = getchar()) != EOF)
	{
		//�涨ǰ13���ַ���������޸�
		if ((ch >= 64 && ch <= 74) || (ch >= 97 && ch <= 109))
		{
			ch += 13;
			putchar(ch);
		}
		//�����ַ�������ǰ�޸�
		else if ((ch >= 75 && ch <= 90) || (ch >= 110 && ch <= 122))
		{
			ch -= 13;
			putchar(ch);
		}
		else
			putchar(ch);
	}

	system("pause");
	return 0;
}