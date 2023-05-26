#include<stdio.h>
#include<time.h>
#include<stdlib.h>
float func(int *p,int sz)
{
	int tmp = 0;
	int count = 0;
	int sum = 0;
	int num;
	while (tmp<100)
	{
		 num = rand() % 100;
		if (num % 2 == 0)
		{
			count++;
			sum = sum + num;
		}
		*p++ = num;
		tmp++;
	}
	return (float)sum / (float)count;
}

int main()
{
	srand(time(NULL));
	int arr[100];
	int sz = sizeof(arr) / sizeof(arr[1]);
	printf("该数组中偶数的平均值为%f\n", func(arr, sz));
	printf("该数组中元素值为");
	for (int i = 0; i < 100; i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}