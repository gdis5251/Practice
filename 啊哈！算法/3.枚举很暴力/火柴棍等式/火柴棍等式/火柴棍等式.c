#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* ����m�����m<=24��ϣ��ƴ��A+B=C�ĵ�ʽ����ʽ�е�A��B��C�����ɻ���ƴ�����ģ����������㣬���һλ����Ϊ0��
  �Ӻ���ȺŸ�����Ҫ�������
  ���A��=B����A+B=C��B+A=C��Ϊ��ͬ�ĵ�ʽ��A��B��C������0��
  ���л���������0
* ���ķ�
* 2018/10/8
*/
int fun(x)
{
	int num = 0;
	int f[] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };//��ʼ�����飬��¼ÿ����������Ҫ�Ļ�����

	while (x / 10 != 0) //���x��10������0��˵����������λ��
	{
		//��ĩβ��������Ҫ�Ļ��������ӵ�num��
		num += f[x % 10];
		x = x / 10;
	}

	num += f[x];
	return num;


}

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int sum = 0;
	int m = 0;

	//������Ҫ���ٸ����
	scanf("%d", &m);

	//ö��A��B
	for (a = 0; a <= 1111; a++)
	{
		for (b = 0; b <= 1111; b++)
		{
			c = a + b; //�����ַ�ʽ����ʡ��ö��C���Ż����븴�Ӷ�

			if (fun(a) + fun(b) + fun(c) == m-4)
			{
				printf("%d + %d = %d\n", a, b, c);
				sum++;
			}
		}
	}

	printf("һ����%d����ʽ��\n", sum);

	system("pause");

	return 0;
}