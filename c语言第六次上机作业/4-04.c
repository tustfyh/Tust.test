#include <stdio.h>

int func(int j)

{
	int tmp=1;
	for(int i=0;i<j;i++)
	{
		tmp=tmp*10;
	}
	return tmp;
}


int inv(int a)
{
	int n=0;
	for(int j=4;j>=0;j--)
	{
		n=n+(a%10)*func(j);
		a=a/10;
	}
	
	return n;
	
}

int main()
{
	
	
	int a;
	printf("请输入一个五位数\n");
	scanf("%d",&a);
	printf("%d\n",inv(a));
	return 0;
}