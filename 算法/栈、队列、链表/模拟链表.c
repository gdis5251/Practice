#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>


/*
* ������������������ģ������һ��data�������洢���������ݣ���һ��right��������ŵ�ǰԪ�ص���һ�����λ�á�
* ���ķ�
* 2018/10/1
*/

int main(void)
{
	//����Ҫ�ı�����ʼ��
	int data[101] = { 0 };
	int right[101] = { 0 };
	int i = 0;
	int n = 0;
	int len = 0;
	int t = 0;

	//�ֶ�����ģ�������ʼ��Ҫ¼����ٸ�Ԫ��
	scanf("%d", &n);
	
	len = n;

	for (i = 1; i <= n; i++)
	{
		scanf("%d", &data[i]);
	}

	for (i = 1; i <= n; i++)
	{
		if (i != n)
		{
			right[i] = i + 1;
		}
		else
		{
			right[i] = 0;
		}
	}

	//׼��������Ԫ��
	len++;
	scanf("%d", &data[len]);

	t = 1;

	while (t != 0)
	{
		if (data[right[t]] > data[len])
		{
			right[len] = right[t];
			right[t] = len;
			break;
		}
		t = right[t];
	}

	t = 1;

	while (t != 0)
	{
		printf("%d ", data[t]);
		t = right[t];
	}

	system("pause");
	return 0;
}