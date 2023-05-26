#include<stdio.h>
void inv(int* p1,int* p2)
{
	for (int i = 0; i < 100; i++)
	{
		*p1-- = *p2++;
	}
}
int main()
{
	int arr1[100];
	int arr2[100];
	for (int i = 0; i < 100; i++)
	{
		arr1[i] = i;
	}
	inv(&arr2[99], arr1);

	for (int j = 0;  j < 100;  j++)
	{
		printf("%d ", arr2[j]);
	}

	return 0;
}