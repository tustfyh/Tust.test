#include<stdio.h>
#include<ctype.h>
int main()
{
	char str[100] = "0";
	printf("请输入字符串:");
	fgets(str, 100, stdin);//stdin 为标准屏幕
	int arr[3] = { 0 };
	for (int i = 0; str[i]!='\0'; i++)
	{
		if (isupper(str[i]))
		{
			arr[0]++;
		}
		else if (islower(str[i]))
		{
			arr[1]++;
		}
		else if (isdigit(str[i]))
		{
			arr[2]++;
		}
	}
	printf("该字符串中大写字母个数%d\n", arr[0]);
	printf("该字符串中小写字母个数%d\n", arr[1]);
	printf("该字符串中数字字符个数%d\n", arr[2]);

	return 0;
}