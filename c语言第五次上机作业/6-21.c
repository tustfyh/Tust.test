#include<stdio.h>
long Fibonacci(int n)
{
	if (n==1 ||n==2)
	{
		return 1;
	}
	else
	{
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}
int main()
{
	int n;
	printf("请输入所求斐波那契数列的第n项：");
	scanf_s("%d", &n);
	printf("值为%ld ", Fibonacci(n));
	return 0;
}