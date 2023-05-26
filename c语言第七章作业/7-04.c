#include<stdio.h>
int func(int i)
{
	if (!(i%7==0 && i%11==0))
	{
		if (i % 7 == 0 || i % 11 == 0) {
			return i;
		}
	}
	return 0;
}
int main()
{
	int tmp=0;
	int arr[500];
	for (int i = 1; i < 501; i++)
	{
		if (func(i))
		{
			arr[tmp] = func(i);
			printf("%d\n",arr[tmp]);
			tmp++;
		}
	}
	return 0;
}