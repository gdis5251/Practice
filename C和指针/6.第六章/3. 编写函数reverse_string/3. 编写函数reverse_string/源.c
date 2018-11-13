#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>
#include <assert.h>

/*
* 编写函数reverse_string函数，将参数字符串反向排列
* 郭文峰
* 2018/11/13
*/

//void reverse_string(char* str)
//{
//	assert(str);
//	int count = 0;
//	char* p = str;
//	//求这个字符串共有多少个字符
//	while (*p++)
//	{
//		count++;
//	}
//
//	int i = 0;
//	int flag = count / 2;
//	p = str;
//	for (i = 0; i < flag; i++)
//	{
//		char temp = *(p + i);
//		*(p + i) = *(p + count - 1);
//		*(p + count - 1) = temp;
//		count--;
//	}
//	
//}

//用递归的方式求字符串反向排列
void ReverseStringD(char* str)
{
	assert(str);

	if (*str)
	{
		ReverseStringD(++str);
		printf("%c", *--str);
	}
}

int main(void)
{
	char str[] = { "Show Me The Money!" };
	
	printf("%s\n", str);

	//reverse_string(str);

//	printf("%s\n", str);

	ReverseStringD(str);

	system("pause");
	return 0;
}