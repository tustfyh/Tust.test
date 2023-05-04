#include<stdio.h>

int  function(int x)
{
	if (x % 6 == 0&& x % 9 == 0 && x % 14 == 0 )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int x;
	printf("请输入一个整数:");
	scanf_s("%d", &x);
	if (function(x))
	{
		printf("该数可以同时被6，9，14整除\n");
	}
	else
	{
		printf("该数不可以同时被6，9，14整除\n");
	}
	return 0;
}