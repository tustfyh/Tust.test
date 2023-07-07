#include<stdio.h>
#include<iostream>
using namespace std;

//hafuman编码的实现
typedef struct hafumantree
{
	float weight;
	int parent, lch, rch;
}hufumantree,*hfpoint;
typedef struct sqstack
{
	int stacksize=6; //栈里元素个数
	char* top;//栈顶指针
	char* base;//栈底指针
}sqstack;

void initsqstack(sqstack& sq)
{
	char* p = new char[sq.stacksize];
	sq.top = p;
	sq.base = sq.top;
}
void push(sqstack& sq,char n)//压栈
{
	*sq.top++ = n;
}
char pop(sqstack& sq)
{
	sq.top--;
	return *sq.top;
}
hufumantree* inithufamantree(int count,float arr[])
{
	int m = 2 * count;
	hufumantree* h = new hufumantree[m];
	for (int i = 1; i < m; i++)
	{
		h[i].parent = 0;
		h[i].lch = 0;
		h[i].rch = 0;
	}
	for (int j = 1; j <=count; j++)
	{
		h[j].weight = arr[j-1];
	}
	return h;
}
//发现权重值较小的两个的下标
void find_min(int* s1, int* s2,hufumantree* h,int count)
{
	float min1 = 0;
	float min2;
	for (int i = 1; i <= count ; i++)
	{
		min1 = min1 + h[i].weight;
	}
	min2 = min1;
	for (int j = 1; j <= count; j++)
	{
		if (h[j].parent==0)
		{
			if (min1 > h[j].weight)
			{
				min1 = h[j].weight;
				*s1 = j;
			}
		}
	}
	for (int n = 1; n <=count; n++)
	{
		if (h[n].parent == 0)
		{
			if (min2 > h[n].weight && n != *s1)
			{
				min2 = h[n].weight;
				*s2 = n;
			}
		}
	}
}
void createhufamantree(hufumantree* h,int count)
{
	for (int i = count+1; i < 2*count; i++)
	{
		int s1,s2;
		find_min(&s1,&s2,h,i-1);
		h[s1].parent = i;
		h[s2].parent = i;
		h[i].lch = s1;
		h[i].rch = s2;
		h[i].weight = h[s1].weight + h[s2].weight;
	}
}
void createhftreecode(hufumantree* h,int count,sqstack& sq,char cd[7][6])
{
	char c = '0';
	char d = '1';
	for (int i = 1; i <=count; i++)
	{
		int count = i;
		while (1)
		{
			if (h[count].parent!=0)
			{
				if (h[h[count].parent].lch == count)
				{
					push(sq, c);
				}
				else if(h[h[count].parent].rch == count)
				{
					push(sq, d);
				}
				count = h[count].parent;
			}
			else
			{
				break;
			}
		}
		for (int j = 0; j < 6; j++)
		{
			if (sq.top==sq.base)
			{
				cd[i-1][j] = '\0';
				break;
			}
			else
			{
				cd[i-1][j] = pop(sq);
			}
		}
	}




}
int main()
{
	hfpoint h =NULL;
	char ch[] = "ABCDEFG";
	sqstack sq;
	initsqstack(sq);
	char hfcd[7][6] = { 0 };
	float arr[7] = { 0.4,0.3,0.15,0.05,0.04,0.03,0.03};
	int count = sizeof(arr)/sizeof(arr[0]);
	h=inithufamantree(count, arr);
	createhufamantree(h, count);
	createhftreecode(h, count, sq, hfcd);
	for (int i = 0; i < 7; i++)
	{
		printf("%c的hufaman编码=%s\n", ch[i], hfcd[i]);
	}
	return 0;
}