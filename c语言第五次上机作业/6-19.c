#include<stdio.h>


int main()
{
	int i, j, n;
	for ( i = 1; i < 1001; i++)
	{
		for (j = 1; j < i; j++)
		{
			for ( n = 0; n < j; n++)
			{
				if (n*n+j*j==i*i)
				{
					printf("%d %d %d \n", n, j, i);
				}
			}
		}
	}


	return 0;
}