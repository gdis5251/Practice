#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//int main()												//�Ӵ�С�Ķ����ֽ�������
//{
//	int i, j, t, n, num[100];
//	scanf("%d", &n);									//n��ʾ��������n����
//	for (i = 1; i <= n; i++)
//		scanf("%d", &num[i]);							//ѭ�������������Ҫ�������
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
//	for (i = 1; i <= n; i++)							//ѭ�����������
//		printf("%d    \n", num[i]);
//	system("pause");
//	return 0;
//}
struct student									//����һ���ṹ�������洢ѧ���������ͳɼ�
{
	char name[21];
	char score;
};
int main()
{
	struct student s[100], t;
	int i, j, n;
	scanf("%d", &n);								//n��ʾ��������n������
	for (i = 1; i <= n; i++)
		scanf("%s %d", &s[i].name, &s[i].score);	//ѭ������ṹ����Ϣ
	for (i = 1; i <= n - 1; i++)					//ð������
	{
		for (j = 1; j <= n - 1; j++)
		{
			if (s[j].score < s[j + 1].score)		//ע�⣡�� ���������˳ɼ��������t.score=s[j].score����ֻ�����ɼ�������������
			{
				t = s[j];
				s[j] = s[j + 1];
				s[j + 1] = t;
			}
		}
	}
	for (i = 1; i <= n; i++)						//ѭ���������������
		printf("%s   \n", s[i].name);
	system("pause");
	return 0;
}