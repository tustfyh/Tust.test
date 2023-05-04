#include<stdio.h>


int main()
{
	int x;
	printf("请输入噪音强度(一个大于0的整数):");
	scanf_s("%d", &x);
	if (x<=50&& x>0)
	{
		printf("安静\n");
	}
	else if (x<71)
	{
		printf("吵闹，有损神经\n");
	}
	else if (x < 91)
	{
		printf("很吵，神经细胞受到破坏\n");
	}
	else if (x < 101)
	{
		printf("吵闹加剧，听力受损\n");
	}
	else if (x < 121)
	{
		printf("难以忍受，待一分钟即暂时致聋\n");
	}
	else 
	{
		printf("极度聋或全聋\n");
	}

	return 0;
}