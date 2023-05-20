#include<stdio.h>


float v(float r,float h)
{
	
	return 3.14*r*r*h;
}

int main()
{
	float h,r;
	printf("请输入圆柱的半径和高\n");
	scanf("%f %f",&r,&h);
	printf("梯形的面积为%f ",v(r,h));
	return 0;
}