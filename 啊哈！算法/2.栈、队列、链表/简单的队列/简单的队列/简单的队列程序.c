#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
* ����������ʵ�ּ򵥵Ķ���ʵ��
  ����һ�����֣��������Ϊ����һ����ɾ���������ŵڶ������ŵ��⴮����ĩβ��ֱ��ʣ�����һ����
  ���ողŵ�ɾ��˳�򣬰���Щɾ����������һ�������ȷ������
* ���ķ�
*2018/9/26
*/

int main(void)
{
	int q[100] = { 6, 3, 1, 7, 5, 8, 9, 2, 4 };
	// ��ʼ������
	int head = 0;
	int tail = 9; //��tailָ��ĩβ����һ��Ԫ��

	while (head < tail)
	{
		//��ӡ���ײ������׳���
		printf("%d ", q[head]);
		head++;
		//�Ƚ��¶��׵�Ԫ����ӵ���β
		q[tail] = q[head];
		tail++;
		//�ٽ����׳���
		head++;
	}

	printf("\n");

	system("pause");
	return 0;
}