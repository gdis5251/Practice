#define _CRT_SECURE_NO_WARNINGS 1

/*
* 本程序把一串数组里的字符数字转为整形的数字，如果发现非数字字符，返回0
* 郭文峰
* 2018/11/15
*/
void 

int main(void)
{
	char arr[29] = { "1023456789" };

	AsciiToInt(arr);

	for (int i = 0; i < 29; i++)
	{
		printf("%d ", arr[i]);
	}


	system("pause");
	return 0;
}