#define ROW 10
#define COL 10

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int sum_arr(int p[][COL])
{
	int sum1 =0;
	int sum2 = 0;
	for (int i = 0; i < ROW; i++)
	{
		sum1 = sum1 + p[i][i];
	}
	for (int j = 9; j >=0 ; j--)
	{
		sum2 = sum2 + p[9-j][j];
	}
	return sum1 + sum2;
}


int main()
{
	srand(time(NULL));
	int arr1[ROW][COL];
	int num=0;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++) 
		{
			num = rand() % 100;
			arr1[i][j] = num;
		}
	}

	printf("两条对角线之和为%d\n", sum_arr(arr1));
}