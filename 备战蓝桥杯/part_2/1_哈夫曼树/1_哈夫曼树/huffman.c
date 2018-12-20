#define _CRT_SECURE_NO_WARNINGS 1

#include "huffman.h"

void initHT(huffmanTree HT, int n)
{
	int i_ = 0;
	int m_ = 2 * n;

	for (i_ = 1; i_ < m_; i_++)//先将数组中所有的父亲结点、左右子树置0
	{
		HT[i_].par = 0;
		HT[i_].lch = 0;
		HT[i_].rch = 0;
	}

	printf("Please input weight:> ");
	for (i_ = 1; i_ <= n; i_++)//输入每个结点的权值
	{
		scanf("%d", &HT[i_].weight);
	}
}





static void sel(huffmanTree HT, int *s1, int *s2, int n)
{
	int i_ = 0;
	int min_ = 999;

	for (i_ = 1; i_ < 2 * n; i_++)
	{
		if (!HT[i_].par && HT[i_].weight > 0)
		{
			if (min_ > HT[i_].weight)
			{
				min_ = HT[i_].weight;
				*s1 = i_;
			}
		}
	}
	HT[*s1].par = 1;//用来记录那个结点已经被找过了

	min_ = 999;

	for (i_ = 1; i_ < 2 * n; i_++)
	{
		if (!HT[i_].par && HT[i_].weight > 0)
		{
			if (min_ > HT[i_].weight)
			{
				min_ = HT[i_].weight;
				*s2 = i_;
			}
		}
	}
}




void createHT(huffmanTree HT, int n)
{
	int s1_ = 0;
	int s2_ = 0;
	int i_ = 0;
	int m_ = 2 * n;

	for (i_ = n + 1; i_ < m_; i_++)
	{
		sel(HT, &s1_, &s2_, n);//找两个权值最小的结点

		//两个权值最小结点生成一个新树
		HT[i_].lch = s1_;
		HT[i_].rch = s2_;
		HT[i_].weight = HT[s1_].weight + HT[s2_].weight;
		
		//将两个被选中的结点的parent选项改为新结点
		HT[s1_].par = i_;
		HT[s2_].par = i_;


	}


}






void printHT(huffmanTree HT, int n)
{
	int i_ = 0;
	int m_ = 2 * n;

	for (i_ = 1; i_ < m_; i_++)
	{
		printf("No.%3d  weight-> %3d  parent-> %3d  lch-> %3d  rch-> %3d\n", \
			i_, HT[i_].weight, HT[i_].par, HT[i_].lch, HT[i_].rch);
	}

}