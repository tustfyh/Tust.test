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
	one_game(arr, ROW, COL);//��ʼ������
	two_game(arr, ROW, COL);//��ӡ����
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
		printf("���Ӯ����Ϸ����\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ����Ϸ����\n");
	}
	else
		printf("ƽ��\n");
}
void test()
{
	int  a = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("������ѡ�1/0��");
		scanf_s("%d", &a);
		switch (a)
		{

		case 1:
			printf("��ʼ��������Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (a);
}
int main()
{
	test();
	return 0;
}
 