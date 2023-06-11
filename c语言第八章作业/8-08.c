#include<stdio.h>
#include<ctype.h>


void str_encrypt(char ch[])
{
	for (int i = 0; ch[i]!='\0'; i++)
	{
		if (isalpha(ch[i]))
		{
			if ((ch[i]>=65 && ch[i]<=86)|| (ch[i] >= 97 && ch[i] <= 118))
			{
				ch[i] = ch[i] + 4;
			}
			else if((ch[i] >= 87 && ch[i] <= 90) || (ch[i] >= 119 && ch[i] <= 122))
			{
				ch[i] = ch[i] - 22;
			}
		}
	}
}


int main()
{
	char ch[100] = "0";
	fgets(ch, 100, stdin);
	str_encrypt(ch);
	printf("%s\n", ch);


	return 0;
}