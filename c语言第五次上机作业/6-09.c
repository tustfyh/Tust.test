#include<stdio.h>

int func01(int i)
{
	int count = 1;
	for ( int n = 1;  n < i+1;  n++)
	{
		count = count * n;
	}
	return count;
}

int main()
{
	double e = 1;
	int n = 1;
	while (1)
	{
		e = e + 1.0 / func01(n);
		n++;
		if (e + 1.0 / func01(n+1)-e<0.00001)
		{
			break;
		}
	}
	printf("%lf", e);
	return 0;
}