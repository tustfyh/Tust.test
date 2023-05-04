#include<stdio.h>

int function(int x)
{
	if (x <100&&x>9)
	{
		int tmp = x * x;
		tmp = tmp % 100;
		if (tmp==x)
		{
			return 1;
		}
		else
		{
			return 0;
		}
		
	}
	else
	{
		
		return -1;
	}

}
int main()
{
	int x;
	printf("请输入一个两位数:");
	scanf_s("%d", &x);
	if (function(x)==1)
	{
		printf("该数是守形数\n");
	}
	else if (function(x) == -1)
	{
		printf("你输入的数不是两位数\n");
	}
	else
	{
		printf("该数不是守形数\n");
	}

	return 0;
}