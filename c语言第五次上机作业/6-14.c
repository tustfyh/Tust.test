#include<stdio.h>
int func01(int i)
{
	int count=0;
	for (int n = 1; n < i; n++)
	{
		if (i%n==0)
		{
			count = count + n;
		}
		
	}
	return count;
}



int main()
{	
	printf("1到1000中的完数为\n");
	for (int i = 1; i < 1001; i++)
	{
		if (i==func01(i))
		{
			printf("%d\n", i);
		}

	}
	return 0;
}