#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* ��һ�����ֽ��д�С����Ķ�����
  �˳����õ�����С��
* ���ķ�
* 2018/10/30
*/

int n;//������¼�ж��ٸ����
int h[101];//������Ŷѵ�����



void swap(int t, int i)
{
	int temp = h[t];
	h[t] = h[i];
	h[i] = temp;
}

//���ڽ��i���������ӽ�����������С�Ѵ���
void siftdown(int i)
{
	int flag = 0;
	int t = 0;

	while (i * 2 <= n && 0 == flag)
	{
		//������ӽ��С�ڸ���㣬����t�����ӽ��
		if (h[i] > h[i * 2])
		{
			t = i * 2;
		}
		else
		{
			t = i;
		}

		//������ӽ��С�����ڵĸ���㣬��t�����ӽ��
		if (i * 2 + 1 <= n)
		{
			if (h[t] > h[i * 2 + 1])//ע��������򵽴˴�˵�����ӽ���Ѿ��͸���㽻�������Դ˴��жϵ������ӽ������ӽ��
			{
				t = i * 2 + 1;
			}
		}

		//��������������㣬�򽻻���������
		if (t != i)
		{
			swap(t, i);
			i = t;//���ղű��������ӽ���Ÿ���i���������ı���

		}
		else
		{
			flag = 1;
		}
	}
}


void create()
{
	int i = 0;

	for (i = n / 2; i >= 1; i--)
	{
		siftdown(i);
	}
}

//ɾ���Ѷ�Ԫ�ز�������
int deletetop(void)
{
	int t = h[1];
	h[1] = h[n];
	n--;//�ѵ�Ԫ�ؼ���1
	siftdown(1);
	return t;
}

int main(void)
{
	int i = 0;
	int num = 0;

	//�����ж��ٸ����ֽ�Ҫ����
	scanf("%d", &num);

	for (i = 1; i <= num; i++)
	{
		scanf("%d", &h[i]);
	}
	
	//ע����һ������ж��creat֮ǰ
	n = num;


	//������
	create();


	//ÿ��ɾ���Զ����֣������д�ӡ
	for (i = 1; i <= num; i++)
	{
		printf("%d ", deletetop());
	}
	printf("\n");

	system("pause");
	return 0;


}