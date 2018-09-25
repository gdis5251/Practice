#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//int main()												//从大到小的对数字进行排序
//{
//	int i, j, t, n, num[100];
//	scanf("%d", &n);									//n表示接下来有n个数
//	for (i = 1; i <= n; i++)
//		scanf("%d", &num[i]);							//循环输入接下来需要排序的数
//	for (i = 1; i <= n - 1; i++)
//	{
//		for (j = 1; j <= n - 1; j++)
//		{
//			if (num[j] < num[j + 1])
//			{
//				t = num[j];
//				num[j] = num[j + 1];
//				num[j + 1] = t;
//			}
//		}
//	}
//	for (i = 1; i <= n; i++)							//循环输出排序结果
//		printf("%d    \n", num[i]);
//	system("pause");
//	return 0;
//}
struct student									//定义一个结构体用来存储学生的姓名和成绩
{
	char name[21];
	char score;
};
int main()
{
	struct student s[100], t;
	int i, j, n;
	scanf("%d", &n);								//n表示接下来有n个数字
	for (i = 1; i <= n; i++)
		scanf("%s %d", &s[i].name, &s[i].score);	//循环输入结构体信息
	for (i = 1; i <= n - 1; i++)					//冒泡排序
	{
		for (j = 1; j <= n - 1; j++)
		{
			if (s[j].score < s[j + 1].score)		//注意！！ 若交换加了成绩项，（例如t.score=s[j].score）将只交换成绩，不交换姓名
			{
				t = s[j];
				s[j] = s[j + 1];
				s[j + 1] = t;
			}
		}
	}
	for (i = 1; i <= n; i++)						//循环输出排序后的姓名
		printf("%s   \n", s[i].name);
	system("pause");
	return 0;
}