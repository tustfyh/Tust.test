#include<stdio.h>
int func01(int i)
{
	int count = 1;
	for (int n = 1; n < i + 1; n++)
	{
		count = count * n;
	}
	return count;
}

int main()
{
	int tmp=0;
	for (int i = 1; i < 11; i++)
	{
		tmp = tmp + func01(i);
	}
	printf("一的阶乘到十的阶乘之和为%d\n", tmp);
	return 0;
}