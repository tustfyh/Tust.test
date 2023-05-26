#define ROW 10
#define COL 10

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int max_arr(int p[][COL])
{
	int max = p[0][0];
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (max < p[i][j])
			{
				max = p[i][j];
			}
		}
	}
	return max;
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
	printf("该二维数组中的最大值为%d\n", max_arr(arr1));

}