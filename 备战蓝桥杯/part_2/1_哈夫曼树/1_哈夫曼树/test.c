#define _CRT_SECURE_NO_WARNINGS 1

/*
** ������ʵ���˹������������Ĺ���
** ���ķ�
** 2018/12/20
*/

#include "huffman.h"

int main(void)
{
	int n = 0;
	huffmanTree HT = NULL;
	printf("Please input how many data you like to create:> ");
	scanf("%d", &n);

	HT = (huffmanTree)malloc(sizeof(HTNode) * (2 * n));//�࿪��һ����Ԫ����Ϊ���鲻��0��Ԫ�أ���ֹ��������
	if (!HT)
	{
		printf("malloc error!\n");
		exit(EXIT_FAILURE);
	}

	initHT(HT, n);//��ʼ����������

	//createHT(HT, n);//���ɹ�������

	printHT(HT, n);//��ӡ��������

	free(HT);
	HT = NULL;

	system("pause");
	return 0;
}