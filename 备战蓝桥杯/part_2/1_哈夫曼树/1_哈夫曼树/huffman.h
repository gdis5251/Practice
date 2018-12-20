#define _CRT_SECURE_NO_WARNINGS 1

#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_


#include <stdio.h>
#include <Windows.h>

typedef struct
{
	int weight;
	int par, lch, rch;
}HTNode, *huffmanTree;



void initHT(huffmanTree HT, int n);
void createHT(huffmanTree HT, int n);
void printHT(huffmanTree HT, int n);



#endif //_HUFFMAN_H_