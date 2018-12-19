#define _CRT_SECURE_NO_WARNINGS 1

#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_


#include <stdio.h>
#include <Windows.h>


typedef struct Huffman
{
	int rate;
	struct Huffman *left;
	struct Huffman *right;

};




#endif //_HUFFMAN_H_