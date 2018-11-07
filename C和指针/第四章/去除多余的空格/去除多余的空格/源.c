#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#define NUL '\0'

/*
* 编写一个函数，它从一个字符串中提取一个子字符串。函数的原型如下：
  void deblank(char string[]);
  当函数发现字符串中如果有一个地方由一个或者多个连续的空格组成，就把它们改成单个空格字符。
  注意当你遍历整个字符串的时候要确保它以NUL字符结尾。
* 郭文峰
* 2018/11/7
*/

//判断ch是否是一个或者多个空格
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
			//如果ch是空格且前一个字符不是空格，就让*dest == ‘ ’
			//如果ch是空格且前一个字符是空格，则跳过这个空格直接到下一个字符
			if (!is_blank(*(dest - 1)))
				*dest++ = ' ';
		}
		else
		{
			*dest++ = ch;
		}
	}
	//最后给最后一个字符位赋NUL值
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