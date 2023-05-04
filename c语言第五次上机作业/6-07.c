#include<stdio.h>
int tmp=1;
double func(int n)
{
	tmp = tmp+n-1;
	return 1.0 / tmp;
}

int main()
{
	int n = 0;
	double s=0;
	double a;
	while (1)
	{
		n++;
		a = func(n);
		s = s + a;
		printf("%d\n", n);
		if (a<0.000001)
		{
			break;
		}
	}


	return 0;
}