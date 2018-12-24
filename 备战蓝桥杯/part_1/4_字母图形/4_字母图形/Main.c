#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>

//��������
//5 7
//�������
//ABCDEFG
//BABCDEF
//CBABCDE
//DCBABCD
//EDCBABC
//���ݹ�ģ��Լ��
//1 <= n, m <= 26

void printGraph(int row, int col)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int isSort = 1;
	char **ch = (char **)malloc(sizeof(char*) * row);
	if (!ch)
	{
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < row; i++)
	{
		ch[i] = (char *)malloc(sizeof(char) * col);
		if (!ch[i])
		{
			exit(EXIT_FAILURE);
		}
	}

	for (i = 0; i < row; i++)
	{
		ch[i][0] = i + 'A';
		k = 1;
		isSort = 1;
		if ('A' < ch[i][0])//���ÿ�е�һ��Ԫ�ر�A��˵����������
		{
			isSort = 0;
		}


		for (j = 0; j < col - 1; j++)
		{
			if ('A' == ch[i][j])//ֻҪ��������A���Ͱ�isSort = 1;
				isSort = 1;
			

			if (0 == isSort)
			{
				ch[i][j + 1] = ch[i][0] - j - 1;
			}
			else
			{
				ch[i][j + 1] = 'A' + k;
				k++;
			}

		}
	}

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			printf("%c", ch[i][j]);
		printf("\n");
	}

	for (i = 0; i < row; i++)
	{
		free(ch[i]);
		ch[i] = NULL;
	}
	free(ch);
	ch = NULL;
}

int main(void)
{
	int n = 0;
	int m = 0;

	scanf("%d%d", &n, &m);
	
	printGraph(n, m);

	system("pause");
	return 0;
}