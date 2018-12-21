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
	huffmanCode HC = NULL;
	printf("Please input how many data you like to create:> ");
	scanf("%d", &n);

	HT = (huffmanTree)malloc(sizeof(HTNode) * (2 * n));//�࿪��һ����Ԫ����Ϊ���鲻��0��Ԫ�أ���ֹ��������
	if (!HT)
	{
		printf("malloc error!\n");
		exit(EXIT_FAILURE);
	}

	HC = (huffmanCode)malloc(sizeof(HCNode) * (n + 1));
	if (!HC)
	{
		printf("malloc error!\n");
		exit(EXIT_FAILURE);
	}

	initHT(HT, HC, n);//��ʼ����������

	createHT(HT, n);//���ɹ�������

	hufCod(HT, &HC, n);

	printHT(HC, n);//��ӡ��������

	free(HT);
	free(HC);
	HC = NULL;
	HT = NULL;

	system("pause");
	return 0;
}