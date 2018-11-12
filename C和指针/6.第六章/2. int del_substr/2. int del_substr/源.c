#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>
#include <assert.h>

/*
* 本程序实现del_substr函数，即第一个字符串减去子串的部分并返回1，
  如果两个字符串不完全相同，则返回0。
* 郭文峰
* 2018/11/12
*/

int del_substr(char* str, const char* substr)
{
	char* pstr = str;
	const char* psubstr = substr;
	char* p = str;
	int flag = 0;

	//判断p2是否为p1的子串
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
	//如果为子串，将第一个相同字符的地址改为子串个数+1字符的地址
	else
	{
		while (*pstr != *psubstr)
		{
			pstr++;
		}
		//将第一个相同的字符的地址赋给p指针
		p = pstr;
		while (*psubstr)
		{
			psubstr++;
			pstr++;
		}
		//将从p 开始等于除子串外其他的字符
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