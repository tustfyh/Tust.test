#include"game.h"
void menu()
{
	printf("**************************************\n");
	printf("*****1.play       2.gave up***********\n");
	printf("**************************************\n");


}
void game()
{
	int ret = 0;
	char arr[ROW][COL] = { 0 };
	one_game(arr, ROW, COL);//初始化数组
	two_game(arr, ROW, COL);//打印棋盘
	while (1)
	{
		playmove(arr, ROW, COL);
		two_game(arr, ROW, COL);
		ret=win(arr,ROW,COL);
		if (ret != 'g')
			break;
		computermove(arr, ROW, COL);
		two_game(arr, ROW, COL);
		ret = win(arr, ROW, COL);
		if (ret != 'g')
			break;
	}
	if (ret == '*')
	{
		printf("玩家赢，游戏结束\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢，游戏结束\n");
	}
	else
		printf("平局\n");
}
void test()
{
	int  a = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入选项（1/0）");
		scanf_s("%d", &a);
		switch (a)
		{

		case 1:
			printf("开始三子棋游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (a);
}
int main()
{
	test();
	return 0;
}
 