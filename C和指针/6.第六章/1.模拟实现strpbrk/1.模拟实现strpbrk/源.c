#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>
#include <assert.h>

char* MyStrpbrk(const char* arr1, const char* arr2)
{
	assert(arr1 && arr2);
	const char* p1 = arr1;
	const char* p2 = arr2;

	//��������p1��ÿ���ַ���Ѱ��p2�Ƿ�����p1��ͬ���ַ�
	while (*p1)
	{
		while (*p1 != *p2 && *p2 != '\0')
		{
			p2++;
		}
		if (*p1 == *p2)
			//ǿתΪchar* �����ٷ��أ���Ϊconst�ǳ��������Ըı�
			return (char* )p1;

		//��p2ָ������ָ��arr2����Ԫ�ص�ַ
		p2 = arr2;
		p1++;
	}

	return NULL;

}

int main(void)
{
	char* arr1 = "This is my money!";
	char* arr2 = "Do not touch it!";
	char* arr3 = "aaa";
	//�������αȽϣ������ϣ���һ���ǿ��Է���һ����ַ
	//���ڶ��η��ص���NULL
	char* p = MyStrpbrk(arr1, arr2);
	char* q = MyStrpbrk(arr1, arr3);
	
	printf("%s\n", p);
	printf("%s\n", q);


	system("pause");
	return 0;
}