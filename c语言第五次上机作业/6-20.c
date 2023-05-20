#include<stdio.h>

long long func01(int n)//求阶乘
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return n * func01(n - 1);
	}
}

double func02(double x, int n)//求x次幂(带正负号)
{
	double tmp = 1;
	for (int i = 0; i < 2*n-1; i++)
	{
		tmp = tmp * x;
	}
	if (n%2)
	{
		return tmp;
	}
	else
	{
		return tmp*(-1);
	}
}
double mysin(double x)
{
	int n = 1;
	double tmp = 0;
	double tmp01 = 0;
	
	while (1)
	{
		tmp01= func02(x, n) / func01(2*n-1);
		tmp = tmp + tmp01;
		if (tmp01<0)
		{
			tmp01 = -1 * tmp01;
		}
		if (tmp01<0.00001&&tmp01>0)
		{
			return tmp;
		}
		n++;
	}
}
int main()
{
	double x=0;
	printf("请输入x(弧度制):");
	scanf_s("%lf",&x);
	printf("sin值为%lf", mysin(x));
	return 0;
}