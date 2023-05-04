#include<stdio.h>

int fouction(int x, int y)
{
	int tmp;
	//衣服大于裤子
	if (x>y)
	{
		if (y>=50)
		{
			 tmp = y * 80 + (x - y) * 60;
			return tmp;
		}
		else
		{
			 tmp = y * 90 + (x - y) * 60;
			return tmp;
		}
	}
	else
	{
		if (x >= 50)
		{
			tmp = x * 80 + (y - x) * 60;
			return tmp;
		}
		else
		{
			tmp = x * 90 + (y - x) * 60;
			return tmp;
		}
	}
}
int main()
{
	int x,y;
	printf("请输入购买的衣服数:");
	scanf_s("%d", &x);
	printf("请输入购买的裤子数:");
	scanf_s("%d", &y);
	printf("收款总额%d元\n", fouction(x, y));
	return 0;
}