#include<stdio.h>


int main()
{
	float count = 0;
	float tmp = 0;
	float ave;
	while (1)
	{
		float x = 0;
		printf("请输入学生成绩（输入-99结束循环）\n");
		scanf_s("%f", &x);
		if (x==-99.0)
		{
			break;
		}
		tmp = x + tmp;
		count++;
	}
	ave = tmp / count;
	printf("这群学生的平均数为%lf\n", ave);
	return 0;
}