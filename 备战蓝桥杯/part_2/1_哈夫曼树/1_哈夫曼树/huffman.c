#define _CRT_SECURE_NO_WARNINGS 1

#include "huffman.h"

void initHT(huffmanTree HT, int n)
{
	int i_ = 0;
	int m_ = 2 * n;

	for (i_ = 1; i_ <= m_; i_++)//�Ƚ����������еĸ��׽�㡢����������0
	{
		HT[i_].par = 0;
		HT[i_].lch = 0;
		HT[i_].rch = 0;
	}

	printf("Please input weight:> ");
	for (i_ = 1; i_ <= n; i_++)//����ÿ������Ȩֵ
	{
		scanf("%d", &HT[i_].weight);
	}
}




void printHT(huffmanTree HT, int n)
{
	int i_ = 0;
	int m_ = 2 * n;

	for (i_ = 1; i_ <= m_; i_++)
	{
		printf("No.%3d  weight-> %3d  parent-> %3d  lch-> %3d  rch-> %3d\n", \
			i_, HT[i_].weight, HT[i_].par, HT[i_].lch, HT[i_].rch);
	}

}