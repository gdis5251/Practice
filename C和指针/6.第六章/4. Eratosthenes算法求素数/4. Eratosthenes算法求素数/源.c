#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>
#include <assert.h>

/*
* ʹ��Eratosthenes�㷨��һ����Χ�ڵ�����
* ���ķ�
* 2018/11/13
*/

#define TURE 1
#define FALSE 0

void Eratosthenes(int* arr, const int sz)
{
	assert(arr);

	int* p = arr;
	int i = 0;
	int j = 0;

	//��˳��ȥģÿ��û�б�ȡ����ǵ����֣���������������ȡ�����
	for (i = 2; i < sz; i++)
	{
		if (*(p + i))
		{
			for (j = i + 1; j < sz; j++)
			{
				if (*(p + j))
				{
					if (j % i == 0)
					{
						*(p + j) = FALSE;
					}
				}
			}
		}
	}
	
}

void print(int* arr, const int sz)
{
	assert(arr);

	int i = 0;
	for (i = 2; i < sz; i++)
	{
		if (*(arr + i))
		{
			printf("%d ", i);
		}
	}
}
int main(void)
{
	int arr[1001] = { 0 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);

	for (i = 0; i < sz; i++)
	{
		arr[i] = TURE;
	}
	Eratosthenes(arr, sz);
	print(arr, sz);

	system("pause");
	return 0;
}