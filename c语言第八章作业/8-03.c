#include<stdio.h>
#include<ctype.h>

int upr_len(char str[])
{

	int count = 0;
	for (int i = 0; str[i]!='\0'; i++)
	{
		if (isupper(str[i]))
		{
			count++;
		}
	}
	return count;
}
int main()
{

	char str[100] = "0";
	fgets(str, 100, stdin);
	printf("该字符串中大写字母个数为%d\n", upr_len(str));
	return 0;
}