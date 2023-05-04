#include<stdio.h>
float func(float t,int n,float r)
{
	float tmp;
	for (int i = 1; i < n+1; i++)
	{
		tmp = t * (1.0 + r);
		t = tmp;
	}
	return t;
}


int main()
{
	int n;
	float t,r;
	
	printf("请输入一年定期存款的总额:");
	scanf_s("%f", &t);
	printf("请输入存款的利率:");
	scanf_s("%f", &r);
	printf("请输入存款年数:");
	scanf_s("%d", &n);
	printf("%d年后存款为%f\n",n,func(t, n, r));
	return 0;
}