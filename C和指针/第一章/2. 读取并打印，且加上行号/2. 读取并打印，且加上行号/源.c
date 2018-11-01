#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 从标准输入读取几行输入。每行输入都要打印到标准输出上，前面要
  加上行号。在编写这个程序时要试图让程序能够处理的输入行的长度
  没有限制。
* 郭文峰
* 2018/10/31
*/

int main()
{
	//ch被声明为整形用来存字符型的原因是
	//EOF为整形，它的位数要是字符类型多
	//把ch声明为整形可以防止从输入读取的字符意外被解释为EOF
	int ch;
	int line = 0;
	int flag = 1;
	
	//循环读取字符
	while ((ch = getchar()) != EOF)
	{
		if (flag == 1)
		{
			line++;
			printf("%d、", line);
			flag = 0;
		}
		//每次输入一个字符后回车，即可显示行号加字符
		if (ch == '\n')
			flag = 1;
		putchar(ch);
	}

	return 0;
}
