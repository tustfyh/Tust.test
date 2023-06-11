#include<stdio.h>
#include<ctype.h>



int main()
{

	char str1[50]="0";
	char str2[100]="0";
	int count = 0;
	fgets(str2, 100, stdin);

	for (int i = 0;str2[i]!='\0'; i++)
	{
		if (islower(str2[i]))
		{
			str1[count] = str2[i];
			count++;
		}
	}
	printf("%s", str1);
	retrun 0;
}