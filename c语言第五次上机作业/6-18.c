#include<stdio.h>

int main()
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 13; j++) 
		{
			for (int n = 1; n < 73; n++)
			{
				if (4*i+3*j+0.5*n==36&&i+j+n==36)
				{
					printf("需要男人数为%d\n需要女人数为%d\n需要小孩人数为%d\n", i, j, n);
					return 0;
				}
			}
		}
	}
	

}