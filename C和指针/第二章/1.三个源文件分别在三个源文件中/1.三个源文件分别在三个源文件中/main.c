#define _CRT_SECURE_NO_WARNINGS 1

#include "negate.h"
#include "increment.h"

/*
* ��дһ��������������������ɣ��ֱ𱣴���һ��������Դ�ļ��С�
  ����increment ����һ�����β��������ķ���ֵ�Ǹò�����ֵ��һ��
  ����negate ����һ�����β��������ķ���ֵ�Ǹò����ĸ�ֵ��
  ����main ���ֱ��ò���10��0��-10����������������������ӡ�����
* ���ķ�
* 2018/11/5
*/

int main(void)
{
	printf("%d\n", increment(10));
	printf("%d\n", increment(0));
	printf("%d\n", increment(-10));

	printf("%d\n", negate(10));
	printf("%d\n", negate(0));
	printf("%d\n", negate(-10));


	system("pause");
	return 0;


}