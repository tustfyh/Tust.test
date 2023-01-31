#include"game.h"
void one_game(char arr[ROW][COL], int row, int col)

{
	int a = 0;
	int b = 0;
	for (a = 0; a < row; a++)
	{
		for (b = 0; b < col; b++)
		{
			arr[a][b] = ' ';

		}
	}
}void two_game(char arr[ROW][COL], int row, int col)
{
	int a = 0;
	for (a = 0; a < row; a++)
	{
		int b = 0;
		for (b = 0; b < col; b++)
		{
			printf(" %c ", arr[a][b]);
			if (b < col - 1)
				printf("|");
		}
		printf("\n");
		if (a < row - 1)
		{
			for (b = 0; b < col; b++)
			{

				printf("---");
				if (b < col - 1)
					printf("|");
			}
			printf("\n");
		}

	}
}
void playmove(char arr[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走!\n");
	while (1)
	{
		printf("请输入坐标!");
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (arr[x - 1][y - 1] == ' ')
			{
				arr[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("坐标被占用,请重新输入坐标\n");
		}
		else
			printf("输入坐标非法\n");
	}
	}
	
void computermove(char arr[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走!\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (arr[x][y] == ' ')
		{
			arr[x][y] = '#';
			break;
		}
	}
}
int Full(char arr[ROW][COL], int row, int col)
{
	int a = 0;
	int b = 0;
	for (a = 0; a < row; a++)
	{
		for (b = 0; b < col; b++)
		{
			if (arr[a][b] == ' ')
			{
				return 0;
			}
		}
	
	}
	return 1;
 }
char win(char arr[ROW][COL], int row, int col)
{

	int a = 0;
	for (a = 0; a<row; a++)
	{
		if (arr[a][0] == arr[a][1] && arr[a][1] == arr[a][2]&&arr[a][0]!=' ')
		{
			return arr[a][0];
		}
	}
	for (a = 0; a < col; a++)
	{
		if (arr[0][a] == arr[1][a] && arr[1][a] == arr[2][a] && arr[2][a] != ' ')
		{
			return arr[0][a];
		}
	}

		if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]&&arr[1][1]!=' ')
		{
			return arr[1][1];
		}
		if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]&&arr[1][1]!=' ')
		{
			return arr[2][2];
		}
		if (Full(arr,row,col) == 1)
		{
			return 'q';
		}
		else
			return 'g';
	}
	


