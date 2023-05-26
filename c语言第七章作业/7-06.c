#define ROW 10
#define COL 10

#include<time.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	srand(time(NULL));
	int arr1[ROW][COL];
	int arr2[2] = { 0 };
	int num=0;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++) 
		{
			num = rand() % 100;
			arr1[i][j] = num;
			if (num>=60)
			{
				arr2[0]++;
			}
			else
			{
				arr2[1]++;
			}
		}
	}
	printf("该数组中大于等于六十的元素个数为%d,小于六十的元素个数为%d\n", arr2[0], arr2[1]);

}