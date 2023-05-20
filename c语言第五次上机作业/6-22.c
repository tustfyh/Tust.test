#include<stdio.h>

float p(float n, float x)
{
	if (n==0)
	{
		return 1;
	}
	else if(n==1)
	{
		return x;
	}
	else
	{
		return ((2 * n - 1) * x - p(n - 1, x) - (n - 1) * p(n - 2, x)) / n;
	}
}
int main()
{
	float n, x;
	printf("请输入n阶勒让德公式的n和x:\n");
	scanf_s("%f %f", &n, &x);
	printf("n阶勒让德公式的值为%f", p(n, x));
	return 0;
}