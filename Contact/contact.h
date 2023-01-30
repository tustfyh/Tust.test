#pragma once
#include<stdio.h>
//#define PEO_NUM 5000
#include<string.h>
#include<Windows.h>
enum leixin
{
	down,//0
	add,//1
	del,//2
	search,//3
	modify,//4
	show,//5
	sort,//6
	save,//7
	clear//8
};

struct people
{
	char name[20];
	int age;
	char sex[5];
	char addr[50];
	char num[15];
};
 typedef struct peoinfo
{
	struct people* date;
	int sz;
	int volume;
} peoinfo;
 void confirst(peoinfo *ps);
 void adddate(peoinfo* ps);
 void addinfor(int x, peoinfo* ps);
 void showdate(peoinfo* ps);
 void deldate(peoinfo* ps);
 void searchdate(peoinfo* ps);
 void  modifdate(peoinfo* ps);
 void destroy(peoinfo* ps);
 void savedate(peoinfo* ps);
 void loaddate(peoinfo* ps);
 void cleardate(peoinfo* ps);
 void sortdate(peoinfo* ps);
 int cmp_age(const void* e1, const void* e2);
