#include<stdio.h>
int func(int a,int n)
{
	int tmp=0;
	for (int i = 0; i < n; i++)
	{
		tmp = tmp + a;
		a = a * 10 + 2;
	}
	return tmp;
}


int main()
{
	int a, n;
	printf("请输入a:");
	scanf_s("%d", &a);
	printf("请输入n:");
	scanf_s("%d", &n);
	printf("%d\n", func(a, n));
	return 0;
}