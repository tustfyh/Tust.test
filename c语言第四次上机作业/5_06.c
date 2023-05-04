#include<stdio.h>
#include<math.h>
float func(float a, float b)
{
	if (a>0&&b>0)
	{
		return cos(a) + cos(b);
	}
	if (a > 0 && b <= 0)
	{
		return sin(a) + sin(b);
	}
	if (a <= 0 && b > 0)
	{
		return cos(a) + sin(b);
	}
	if (a <= 0 && b <=0)
	{
		return sin(a) + cos(b);
	}
}
int main()
{
	float a, b;
	scanf_s("%f %f", &a, &b);
	printf("函数值为%f\n", func(a, b));
	return 0;
}