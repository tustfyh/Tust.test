#include <stdio.h>

float rectangle(float a,float b,float x)
{
	
	return (a*b)/x;
}
int main()
{
	float a,b,x;
	printf("请输入矩形草坪的长 宽 修建草坪的速度\n");
	scanf("%f %f %f",&a,&b,&x);
	printf("修建完草坪所需时间t=%f",rectangle(a,b,x));
	return 0;
}