#define _CRT_SECURE_NO_WARNINGS 1

/*
* �������һ����������ַ�����תΪ���ε����֣�������ַ������ַ�������0
* ���ķ�
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