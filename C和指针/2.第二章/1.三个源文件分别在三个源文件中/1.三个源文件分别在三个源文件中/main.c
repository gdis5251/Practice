#define _CRT_SECURE_NO_WARNINGS 1

#include "negate.h"
#include "increment.h"

/*
* 编写一个程序，它由三个函数组成，分别保存在一个单独的源文件中。
  函数increment 接受一个整形参数，它的返回值是该参数的值加一。
  函数negate 接受一个整形参数，它的返回值是该参数的负值。
  函数main 它分别用参数10，0和-10调用另外两个函数，并打印结果。
* 郭文峰
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