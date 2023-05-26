#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int arr1[100] = {0};
	int arr2[5] = { 0 };
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 100; i++)
	{
		arr1[i] = rand() % 100;//控制范围
	}
	for ( int j = 0; j < 100;  j++)
	{
		if (arr1[j]>=90)
		{
			arr2[0]++;
		}
		else if (arr1[j] >=80)
		{
			arr2[1]++;
		}
		else if(arr1[j]>=70)
		{
			arr2[2]++;
		}
		else if (arr1[j]>=60)
		{
			arr2[3]++;
		}
		else
		{
			arr2[4]++;
		}
	}
	printf("数组中>=90的个数为%d\n80~89的个数为%d\n70~79的个数为%d\n60~69的个数为%d\n小于60的个数为%d\n", arr2[0], arr2[1], arr2[2], arr2[3], arr2[4]);
	return 0;
}