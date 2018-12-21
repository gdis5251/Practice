#define _CRT_SECURE_NO_WARNINGS 1

#include "huffman.h"

void initHT(huffmanTree HT, huffmanCode HC, int n)
{
	int i_ = 0;
	int m_ = 2 * n;

	for (i_ = 1; i_ < m_; i_++)//先将数组中所有的父亲结点、左右子树置0
	{
		HT[i_].par = 0;
		HT[i_].lch = 0;
		HT[i_].rch = 0;

	}

	for (i_ = 1; i_ <= n; i_++)//输入每个结点的权值
	{
		HC[i_].hc = NULL;

		fflush(stdin);
		printf("Please input ch:> ");
		scanf("%c", &HT[i_].ch);

		HC[i_].ch = HT[i_].ch;

		printf("Please input weight:> ");
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




void hufCod(huffmanTree HT, huffmanCode_p HC, int n)
{
	char *cd = (char *)malloc(sizeof(char) * n);//开一个内存存哈夫曼编码，哈夫曼编码最长为n-1，多开辟一个内存单元放'\0'
	if (!cd)
	{
		printf("malloc cd error!\n");
		exit(EXIT_FAILURE);
	}
	int start = n - 1;
	int i_ = 0;
	int f_ = 0;
	int c_ = 0;

	cd[n - 1] = '\0';//将最后一个元素设置为字符串结束标志
	for (i_ = 1; i_ <= n; i_++)
	{
		start = n - 1;
		c_ = i_;
		f_ = HT[i_].par;

		while (f_)//只要不是根结点，所有的结点都有双亲结点0
		{
			--start;//从后往前记录字符
			if (HT[f_].lch == c_)//双亲结点的左子树是否等于当前结点的编号
				cd[start] = '0';
			else
				cd[start] = '1';

			c_ = f_;
			f_ = HT[f_].par;
		}

		if (n - start)
		{
			(*HC)[i_].hc = (char*)malloc(n - start);
			strcpy((*HC)[i_].hc, &cd[start]);
		}
	}

	free(cd);

}




void printHT(huffmanCode HC, int n)
{
	int i_ = 0;
	int m_ = 2 * n;

	for (i_ = 1; i_ <= n; i_++)
	{
		printf("%c: %s\n", HC[i_].ch, HC[i_].hc);
		
		free(HC[i_].hc);
		HC[i_].hc = NULL;
	}

}