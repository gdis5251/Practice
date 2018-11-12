#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int n;
int a[101];

void quicksort(int left, int right)
{
	int i, j, temp, t;//判错
	if (left > right)
		return;

	temp = a[left]; //temp中存的是基数
	i = left;
	j = right;
	while (i != j)
	{
		//先从右向左找，找到一个比基数小的数字
		while (a[j] >= temp && i < j)
			j--;
		//从左向右找，找到一个比基数大的数字
		while (a[i] <= temp && i < j)
			i++;
		//将找到的两个数字互换位置
		if (i < j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	//将基数归位
	a[left] = a[i];
	a[i] = temp;

	quicksort(left, i - 1);
	quicksort(i + 1, right);
}

int main()
{ 
	int i;

	//确定数组元素个数并输入数组元素
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