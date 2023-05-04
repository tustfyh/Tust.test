#include<stdio.h>
int main()
{
	float s = 0.008;
	float p = 14;
	float tmp;
	int count = 0;
	while (1)
	{
		tmp = p + p * s;
		p = tmp;
		count++;
		if (p>26)
		{
			break;
		}
	}
	printf("第%d年后人口达到26亿\n", count);


	return 0;
}