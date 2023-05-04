#include<stdio.h>
int func(int i)
{
	return 2 * i * i + 3 * i + 1;
}

int main()
{

	int a = 0;
	int b = 0;
	for (int i = 1; i < 21; i++)
	{
		b = func(i);
		a = a + b;
	}
	printf("%d\n", a);
	return 0;
}