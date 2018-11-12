#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>
#include <assert.h>

/*
* ������ʵ��del_substr����������һ���ַ�����ȥ�Ӵ��Ĳ��ֲ�����1��
  ��������ַ�������ȫ��ͬ���򷵻�0��
* ���ķ�
* 2018/11/12
*/

int del_substr(char* str, const char* substr)
{
	char* pstr = str;
	const char* psubstr = substr;
	char* p = str;
	int flag = 0;

	//�ж�p2�Ƿ�Ϊp1���Ӵ�
	while (*psubstr)
	{
		if (*pstr == *psubstr)
		{
			flag = 1;
			psubstr++;
		}
		else
		{
			if (flag == 1)
			{
				flag = 0;
				break;
			}
			flag = 0;
			
		}
		pstr++;
	}
	pstr = str;
	psubstr = substr;
	if (flag == 0)
		return 0;
	//���Ϊ�Ӵ�������һ����ͬ�ַ��ĵ�ַ��Ϊ�Ӵ�����+1�ַ��ĵ�ַ
	else
	{
		while (*pstr != *psubstr)
		{
			pstr++;
		}
		//����һ����ͬ���ַ��ĵ�ַ����pָ��
		p = pstr;
		while (*psubstr)
		{
			psubstr++;
			pstr++;
		}
		//����p ��ʼ���ڳ��Ӵ����������ַ�
		while (*pstr)
		{
			*p = *pstr;
			p++;
			pstr++;
		}
		*p = '\0';

		return 1;
		
	}
}

int main(void)
{
	char arr1[] = { "ABCDEFG" };
	char arr2[] = { "CDE" };
	int ret = del_substr(arr1, arr2);

	if (ret == 1)
	{
		printf("%s\n", arr1);
	}
	else
	{
		printf("They're not exactly the same. \n");
	}

	system("pause");
	return 0;
}