#include<stdio.h>
int main()
{
	int x, y;
	printf("请输入函数值x:");
	scanf_s("%d", &x);
	if (x<0)
	{
		y = 2 * x - 1;
	}
	else if (x<10)
	{
		y=2 * x + 10;
	}
	else if (x < 100)
	{
		y = 2 * x + 100;
	}
	else
	{
		y = x * x;
	}
	printf("函数值为%d\n", y);
	return 0;
}