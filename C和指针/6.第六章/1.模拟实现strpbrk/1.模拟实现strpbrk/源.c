#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>
#include <assert.h>

char* MyStrpbrk(const char* arr1, const char* arr2)
{
	assert(arr1 && arr2);
	const char* p1 = arr1;
	const char* p2 = arr2;

	//挨个遍历p1的每个字符，寻找p2是否有与p1相同的字符
	while (*p1)
	{
		while (*p1 != *p2 && *p2 != '\0')
		{
			p2++;
		}
		if (*p1 == *p2)
			//强转为char* 类型再返回，因为const是常量不可以改变
			return (char* )p1;

		//让p2指针重新指向arr2的首元素地址
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
	//进行两次比较，理论上，第一次是可以返回一个地址
	//而第二次返回的是NULL
	char* p = MyStrpbrk(arr1, arr2);
	char* q = MyStrpbrk(arr1, arr3);
	
	printf("%s\n", p);
	printf("%s\n", q);


	system("pause");
	return 0;
}