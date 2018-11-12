#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* 本程序用于实现简单的队列实例
  解码一段数字，解码规则为将第一个数删除，紧接着第二个数放到这串数的末尾，直到剩下最后一个数
  按照刚才的删除顺序，把这些删除的数连在一起就是正确的数字
* 郭文峰
*2018/9/26
*/

int main(void)
{
	int q[100] = { 6, 3, 1, 7, 5, 8, 9, 2, 4 };
	// 初始化队列
	int head = 0;
	int tail = 9; //将tail指向末尾的下一个元素

	while (head < tail)
	{
		//打印队首并将队首出队
		printf("%d ", q[head]);
		head++;
		//先将新队首的元素添加到队尾
		q[tail] = q[head];
		tail++;
		//再将队首出队
		head++;
	}

	printf("\n");

	system("pause");
	return 0;
}