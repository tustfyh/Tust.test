#include<stdio.h>
int main()
{
	float tmp;
	float t=0;
	for (float i = 1.0; i < 21.0; i++)
	{
		tmp = (i + 1) / i;
		t = t+tmp;
	}
	printf("%f\n", t);
	return 0;
}