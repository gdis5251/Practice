#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#define NUL '\0'

/*
* ��дһ������������һ���ַ�������ȡһ�����ַ�����������ԭ�����£�
  void deblank(char string[]);
  �����������ַ����������һ���ط���һ�����߶�������Ŀո���ɣ��Ͱ����Ǹĳɵ����ո��ַ���
  ע�⵱����������ַ�����ʱ��Ҫȷ������NUL�ַ���β��
* ���ķ�
* 2018/11/7
*/

//�ж�ch�Ƿ���һ�����߶���ո�
int is_blank(int ch)
{
	return ch == ' ' || ch == '\t' || ch == '\v' || ch == '\f' || ch == '\n' || ch == '\r';
}

void deblank(char *string)
{
	char *src = string;
	char *dest = string++;
	int ch = 0;

	while (ch = *src++)
	{
		if (is_blank(ch))		
		{
			//���ch�ǿո���ǰһ���ַ����ǿո񣬾���*dest == �� ��
			//���ch�ǿո���ǰһ���ַ��ǿո�����������ո�ֱ�ӵ���һ���ַ�
			if (!is_blank(*(dest - 1)))
				*dest++ = ' ';
		}
		else
		{
			*dest++ = ch;
		}
	}
	//�������һ���ַ�λ��NULֵ
	*dest = NUL;
}

int main(void)
{
	char arr[30] = { "   hello !    world   !" };

	deblank(arr);

	printf("%s\n", arr);

	system("pause");
	return 0;
}