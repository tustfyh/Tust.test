#include<stdio.h>


float trapezoid(int a,int b,int h)
{
	
	return (a+b)*h*(1.0/2);
}

int main()
{
	int a,b,h;
	printf("请输入梯形的上底，下底，高\n");
	scanf("%d %d %d",&a,&b,&h);
	printf("梯形的面积为%f ",trapezoid(a,b,h));
	return 0;
}