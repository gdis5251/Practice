#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* �ӱ�׼�����ȡ�������롣ÿ�����붼Ҫ��ӡ����׼����ϣ�ǰ��Ҫ
  �����кš��ڱ�д�������ʱҪ��ͼ�ó����ܹ�����������еĳ���
  û�����ơ�
* ���ķ�
* 2018/10/31
*/

int main()
{
	//ch������Ϊ�����������ַ��͵�ԭ����
	//EOFΪ���Σ�����λ��Ҫ���ַ����Ͷ�
	//��ch����Ϊ���ο��Է�ֹ�������ȡ���ַ����ⱻ����ΪEOF
	int ch;
	int line = 0;
	int flag = 1;
	
	//ѭ����ȡ�ַ�
	while ((ch = getchar()) != EOF)
	{
		if (flag == 1)
		{
			line++;
			printf("%d��", line);
			flag = 0;
		}
		//ÿ������һ���ַ���س���������ʾ�кż��ַ�
		if (ch == '\n')
			flag = 1;
		putchar(ch);
	}

	return 0;
}
