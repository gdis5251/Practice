#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
*  ���������ڳ�����ʶ�����������������n��ȫ����n������
*  ���ķ�
*  2018/10/8
*/

int a[10]  ;
int book[10] ;
int n;

void dfs(int step)
{
	int i = 0;
	if (step == n + 1)
	{
		//���һ�����з�ʽ
		for (i = 1; i <= n; i++)
		{
			printf("%d", a[i]);
		}
		printf("\n");

		return; //�������һ�ε���dfs()�ĵط�
	}

	for (i = 1; i <= n; i++)
	{
		
		
		if (0 == book[i])
		{
			a[step] = i;
			book[i] = 1;
			//�õݹ�ķ�����һ�ε���dfs����
			dfs(step + 1);
			book[i] = 0;
			
		}
	}
	return;
}

int main(void)
{
	scanf("%d", &n);

	dfs(1);//����dfs������������1��ʼ

	system("pause");

	return 0;

}