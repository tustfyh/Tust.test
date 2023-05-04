#include<stdio.h>


int main()
{

	int arr[5] = { 0 };
	for (int i = 0; i < 20; i++)
	{
		int x = 0;
		printf("请输入一个0~100之间的数");
		scanf_s("%d", &x);
		if (x>90)
		{
			arr[0]++;
		}
		else if (x>80)
		{
			arr[1]++;
		}
		else if (x>70)
		{
			arr[2]++;
		}
		else if (x>60)
		{
			arr[3]++;
		}
		else
		{
			arr[4]++;
		}
	}

	printf("90分以上的个数为%d\n80~89的个数为%d\n70~79的个数为%d\n60~69的个数为%d\n60分以下的个数为%d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);

	return 0;
}