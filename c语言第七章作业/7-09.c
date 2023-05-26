#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 4
#define COL 4
//矩阵的加法
void add(int arr1[ROW][COL], int arr2[ROW][COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++) {

			arr1[i][j] = arr1[i][j] + arr2[i][j];
		}
	}
 }
//矩阵的乘法
void mul(int arr3[ROW][COL], int arr1[ROW][COL],int arr2[ROW][COL])
{
	int tmp = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) 
		{
			for (int k = 0; k < 4; k++)
			{
				tmp = tmp + arr1[i][k] * arr2[j][k];
			}
			arr3[i][j] = tmp;
		}
	}
}
int main()
{
	srand(time(NULL));
	int arr1[ROW][COL];
	int arr2[ROW][COL];
	int arr3[ROW][COL];
	int num1,num2;
	for (int i = 0; i <ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			num1 = rand() % 100;
			num2 = rand() % 100;
			arr1[i][j] = num1;
			arr2[i][j] = num2;
		}
	}
	return 0;
}
