#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>
#include <string.h>


/*
* 编写一个程序，从标准输入读取字符，并把它们写到标准输出中。所有非字母的字符都按照它的输入形式输出，字母字符在输出前进行加密。
  加密方法很简单，每个字母被修改为在字母表上距其13个位置（前或后）的字母。
  例如，A被修改为N，Z被修改为M。
  注意大小写都应该被转换。
* 郭文峰
* 2018/11/7
*/

int main(void)
{
	int ch = 0;

	while ((ch = getchar()) != EOF)
	{
		//规定前13个字符，均向后修改
		if ((ch >= 64 && ch <= 74) || (ch >= 97 && ch <= 109))
		{
			ch += 13;
			putchar(ch);
		}
		//其余字符，均向前修改
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