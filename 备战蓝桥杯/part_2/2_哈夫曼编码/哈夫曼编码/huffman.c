#define _CRT_SECURE_NO_WARNINGS 1

#include "huffman.h"

void initHT(huffmanTree HT, huffmanCode HC, int n)
{
	int i_ = 0;
	int m_ = 2 * n;

	for (i_ = 1; i_ < m_; i_++)//�Ƚ����������еĸ��׽�㡢����������0
	{
		HT[i_].par = 0;
		HT[i_].lch = 0;
		HT[i_].rch = 0;

	}

	for (i_ = 1; i_ <= n; i_++)//����ÿ������Ȩֵ
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
	HT[*s1].par = 1;//������¼�Ǹ�����Ѿ����ҹ���

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
		sel(HT, &s1_, &s2_, n);//������Ȩֵ��С�Ľ��

		//����Ȩֵ��С�������һ������
		HT[i_].lch = s1_;
		HT[i_].rch = s2_;
		HT[i_].weight = HT[s1_].weight + HT[s2_].weight;

		//��������ѡ�еĽ���parentѡ���Ϊ�½��
		HT[s1_].par = i_;
		HT[s2_].par = i_;


	}


}




void hufCod(huffmanTree HT, huffmanCode_p HC, int n)
{
	char *cd = (char *)malloc(sizeof(char) * n);//��һ���ڴ����������룬�����������Ϊn-1���࿪��һ���ڴ浥Ԫ��'\0'
	if (!cd)
	{
		printf("malloc cd error!\n");
		exit(EXIT_FAILURE);
	}
	int start = n - 1;
	int i_ = 0;
	int f_ = 0;
	int c_ = 0;

	cd[n - 1] = '\0';//�����һ��Ԫ������Ϊ�ַ���������־
	for (i_ = 1; i_ <= n; i_++)
	{
		start = n - 1;
		c_ = i_;
		f_ = HT[i_].par;

		while (f_)//ֻҪ���Ǹ���㣬���еĽ�㶼��˫�׽��0
		{
			--start;//�Ӻ���ǰ��¼�ַ�
			if (HT[f_].lch == c_)//˫�׽����������Ƿ���ڵ�ǰ���ı��
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