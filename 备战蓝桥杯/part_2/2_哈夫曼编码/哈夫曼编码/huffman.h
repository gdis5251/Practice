#define _CRT_SECURE_NO_WARNINGS 1

#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_


#include <stdio.h>
#include <Windows.h>

typedef struct
{
	char ch;
	int weight;
	int par, lch, rch;
}HTNode, *huffmanTree;


typedef struct
{
	char ch;
	char *hc;
}HCNode, *huffmanCode, **huffmanCode_p;


void initHT(huffmanTree HT, huffmanCode HC, int n);
void createHT(huffmanTree HT, int n);
void printHT(huffmanCode HC, int n);
void hufCod(huffmanTree HT, huffmanCode_p HC, int n);



#endif //_HUFFMAN_H_