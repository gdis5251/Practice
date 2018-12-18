#define _CRT_SECURE_NO_WARNINGS 1

#ifndef _SWITCH_H_
#define _SWITCH_H_

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>



int hexToBin(char *hex, char *bin);
int binToOct(char *bin, char *oct, int bl);
void printO(char *oct, int ol);



#endif //_SWITCH_H_