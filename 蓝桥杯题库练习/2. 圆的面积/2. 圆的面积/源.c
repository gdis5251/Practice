#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>
#include <math.h>

#define PI 3.14159265358979323

double GetArea(int r)
{
	return PI * pow(r, 2);
}
int main(void)
{
	int r = 0;
	double area = 0;

	printf("Please Enter :>");
	scanf("%d", &r);

	area = GetArea(r);

	printf("Area: %.7lf\n", area);

	system("pause");
	return 0;
}