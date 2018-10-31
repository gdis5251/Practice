#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* �������������ѽ��д�С��������
* ���ķ�
* 2018/10/31
*/

int n;
int h[101];


//����������
void swap(int t, int i)
{
	int temp = h[t];
	h[t] = h[i];
	h[i] = temp;
}

void siftdown(int i)
{
	int flag = 0;
	int t = 0;

	while (i * 2 <= n && 0 == flag)
	{
		//������ӽ����ڸ���㣬�򲻷�������
		//�����ӽ���Ÿ�ֵ��t��������
		if (h[i] < h[i * 2])
			t = i * 2;
		else
			t = i;
		
		//�ж������ӽ�����ж����ӽ��
		if (i * 2 + 1 <= n)
		{
			if (h[t] < h[i * 2 + 1])
				t = i * 2 + 1;
		}

		//���t������i ��˵�����������ѣ����Խ�����ŵ�����
		if (t != i)
		{
			swap(t, i);
			i = t;//��t�ı�Ÿ���i��������һ�αȽ�
		}
		else
		{
			flag = 1;
		}
	}
}

void create(void)
{
	int i = 0;

	for (i = n / 2; i >= 1; i--)
	{
		//����С������������
		siftdown(i);
	}
}

//ÿ�ν����Ѷ������һ����Ž��
void heapsort(void)
{
	while (n > 1)
	{
		swap(1, n);
		n--;
		siftdown(1);
	}
}


int main(void)
{
	int i = 0;
	int num = 0;
	
	//���빲�ж��ٸ����ֽ�������
	scanf("%d", &num);

	//���뽫Ҫ���������
	for (i = 1; i <= num; i++)
	{
		scanf("%d", &h[i]);
	}

	n = num;

	//������
	create();

	//��������
	heapsort();

	//�������õ�����
	for (i = 1; i <= num; i++)
	{
		printf("%d ", h[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}