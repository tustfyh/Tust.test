#include<stdio.h>

int func01(int n)
{
	if (n)
	{
		if (n == 1)
		{
			return 1;
		}
		else if (n == 2)
		{
			return 2 * n - 1;
		}
		else
		{
			return func01(n - 1) + 2 * n;
		}
	}
}

int main()
{
	int arr[20];

	for (int i = 0; i < 20; i++)
	{
		arr[i] = func01(i + 1);
	}
	for (int j = 0; j < 20; j++)
	{
		printf("数组的第%d项为%d\n", j + 1, arr[j]);
	}
	return 0;
}