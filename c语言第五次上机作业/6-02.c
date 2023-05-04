#include<stdio.h>
double func(int i)
{
	return (2.0* i) * (2.0* i) / ((2.0* i - 1) * (2.0* i + 1));
}

int main()
{
	double a=1;
	double b;
	int n;
	scanf_s("%d", &n);
	for (int i =1 ; i < n+1; i++)
	{
		b = func(i);
		a = 2 * b * a;
	}
	printf("%lf\n", a);
	return 0;
}