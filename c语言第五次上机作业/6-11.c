#include<stdio.h>

int func(int n)
{
	int tmp = n;
	int a, b, c;
	a = n / 100;//1
	n = n % 100;//53
	b = n /10;//5
	c = n % 10;//3
	if (a*a*a+b*b*b+c*c*c==tmp)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int main()
{
	for (int i = 100; i < 1000; i++)
	{
		if (func(i))
		{
			printf("%d ", i);
		}
	}


	return 0;
}