#define _CRT_SECURE_NO_WARNINGS 1

/*
** 本程序实现了构建哈夫曼树的过程
** 郭文峰
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

	HT = (huffmanTree)malloc(sizeof(HTNode) * (2 * n));//多开辟一个单元，因为数组不用0号元素，防止引起歧义
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

	initHT(HT, HC, n);//初始化哈夫曼树

	createHT(HT, n);//生成哈夫曼树

	hufCod(HT, &HC, n);

	printHT(HC, n);//打印哈夫曼树

	free(HT);
	free(HC);
	HC = NULL;
	HT = NULL;

	system("pause");
	return 0;
}