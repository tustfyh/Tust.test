#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
void func(char* str)
{
	for (int i = 0; str[i]!='\0'; i++)
	{
		if (isupper(str[i]))//小写
		{
			str[i]=tolower(str[i]);
		}
		else if(islower(str[i]))//大写
		{
			str[i]=toupper(str[i]);
		}
	}
	
}
int main()
{

	char str[100] = "0";
	fgets(str,100, stdin);
	func(str);
	printf("转换后字符串为%s\n", str);

	return 0;
}