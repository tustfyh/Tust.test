#include<stdio.h>


int main()
{
	int p, w,  y;
	float d,s,f;
	printf("请输入每千米的基本运费(元):");
	scanf_s("%d", &p);
	printf("请输入货物重量(吨):");
	scanf_s("%d", &w);
	printf("请输入运送距离(千米):");
	scanf_s("%f", &s);
	if (s<250)
	{
		d = 0;
		f = p * w * s * (1 - d);
	}
	else if (s<500)
	{
		d = 0.02;
		f = p * w * s * (1 - d);
	}
	else if (s < 1000)
	{
		d = 0.05;
		f = p * w * s * (1 - d);
	}
	else if (s < 2000)
	{
		d = 0.08;
		f = p * w * s * (1 - d);
	}
	else if (s < 3000)
	{
		d = 0.1;
		f = p * w * s * (1 - d);
	}
	else
	{
		d = 0.15;
		f = p * w * s * (1 - d);
	}
	
	printf("运送总费用为%f", f);
	return 0;
}