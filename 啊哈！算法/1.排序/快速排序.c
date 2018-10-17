#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int n;
int a[101];

void quicksort(int left, int right)
{
	int i, j, temp, t;//�д�
	if (left > right)
		return;

	temp = a[left]; //temp�д���ǻ���
	i = left;
	j = right;
	while (i != j)
	{
		//�ȴ��������ң��ҵ�һ���Ȼ���С������
		while (a[j] >= temp && i < j)
			j--;
		//���������ң��ҵ�һ���Ȼ����������
		while (a[i] <= temp && i < j)
			i++;
		//���ҵ����������ֻ���λ��
		if (i < j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	//��������λ
	a[left] = a[i];
	a[i] = temp;

	quicksort(left, i - 1);
	quicksort(i + 1, right);
}

int main()
{ 
	int i;

	//ȷ������Ԫ�ظ�������������Ԫ��
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}

	quicksort(1, n);

	for (i = 1; i <= n; i++)
		printf("%d  ", a[i]);

	printf("\n");
	
	system("pause");
	return 0;
}