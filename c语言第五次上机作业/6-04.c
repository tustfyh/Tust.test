#include<stdio.h>


int main()
{
	printf("1~10000中所有为闰年的年费是\n");
	for (int i = 1; i < 10001; i++)
	{
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
		{
			printf("%d\n", i);
		}
	}
	return 0;
}