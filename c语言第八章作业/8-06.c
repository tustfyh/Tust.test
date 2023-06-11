#include<stdio.h>

#include<string.h>

int str_cmp(char ch1[],char ch2[])
{

	for (int i = 0;ch1[i]!='\0'|| ch2[i]!='\0'; i++)
	{

		if (ch1[i]!=ch2[i])
		{
			return ch1[i] - ch2[i];
		}
	}
	return 0;


}


int main()
{
	char ch1[20] = "0";
	char ch2[20] = "0";
	fgets(ch1, 20, stdin);
	fgets(ch2, 20, stdin);
	printf("%d\n", str_cmp(ch1, ch2));



	return 0;
}