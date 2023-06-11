#include<stdio.h>
#include<string.h>
void func(char str[], int sz)
{
	int c=sz-2;
	char ch;
	for (int i = 0; i < c; i++)
	{
		ch = str[c];
		str[c] = str[i];
		str[i] = ch;
		c--;
	}
}
int main()
{
	char str[100]="0";
	fgets(str, 100, stdin);
	int sz = strlen(str);
	func(str,sz);
	printf("逆序后字符串为%s\n", str);
	
	return 0;
}