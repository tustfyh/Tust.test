#include<stdio.h>

double func(int n)
{
	return 1.0 / (n * n + 1);
}

int main()
{
	int n = 1;
	double t=0;
	double tmp = 0;
	while (1)
	{
		tmp = func(n);
		n++;
		t = t + tmp;
		printf("%d %lf\n", n, tmp);
		if (tmp<0.000001)
		{
			break;
		}
	}
	printf("最后值为%lf\n", t);
	
	return 0;
}