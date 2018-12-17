#define _CRT_SECURE_NO_WARNINGS 1

#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <Windows.h>
#include <assert.h>

#define MAX 9999

void print(int *arr, int n);
void bubbleSort(int *arr, int n);
void selSort(int *arr, int n);
void quickSort(int *arr, int left, int right);

#endif //_SORT_H_