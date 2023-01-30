
#include"contact.h"
//查找name下表
 static int find_name(peoinfo* ps, char name[20])//static 限定该函数只能在这个文件中使用
{
	int i = 0;
	for (i = 0; i < ps->sz; i++)
	{
		if (strcmp(ps->date[i].name, name) == 0)
		{
			break;
		}
	}
	if (i == ps->sz)
	{
		return -1;
	}
	else
	{
		return i;
	}
 }
 //查看容量
 void check(peoinfo* ps)
 {
	 if (ps->sz == ps->volume)
	 {
	  struct people* ptr=(struct people*) realloc(ps->date, (ps->sz + 2) * sizeof(struct people));
	  if (ptr != NULL)
	  {
		  ps->date = ptr;
		  ps->volume += 2;
	  }
	  else
		  return;
	 }
 }
//初始化通讯录
void confirst(peoinfo* ps)
{
	//memset(ps->date, 0, sizeof(ps->date));
	ps->date = (struct people *)calloc(3, sizeof(struct people));
		ps->sz = 0;
		ps->volume = 3;
		//保存上次的数据
		loaddate(ps);
}
//加载数据(保存)
void loaddate(peoinfo* ps)
{
	struct people tmp = { 0 };
	FILE* pf;
	fopen_s(&pf, "contact_date.txt", "rb");
	while (fread(&tmp, sizeof(struct people), 1, pf))//fread，返回一个无符号数，若一次读一个，文件中不在有数据时，会返回最后一次读的个数值
	{
		check(ps);
		ps->date[ps->sz] = tmp;
		ps->sz++;
	}
	fclose(pf);
	pf = NULL;
}

//增加通讯录信息
void adddate(peoinfo* ps)
{
	    check(ps);
		printf("请输入姓名");
		scanf_s("%s", ps->date[ps->sz].name, 20);
		printf("请输入年龄");
		scanf_s("%d", &ps->date[ps->sz].age);
		printf("请输入性别");
		scanf_s("%s", ps->date[ps->sz].sex, 5);
		printf("请输入地址");
		scanf_s("%s", ps->date[ps->sz].addr, 50);
		printf("请输入电话号码");
		scanf_s("%s", ps->date[ps->sz].num, 15);	
		ps->sz++;
		printf("添加成功\n");
	
}
//查看通讯录
void showdate(peoinfo* ps)
{
	if (ps->sz == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		printf("%-20s\t", "姓名");
		printf("%-4s\t", "年龄");
		printf("%-5s\t", "性别");
		printf("%-12s\t", "电话");
		printf("%-20s\n", "地址");
		for (int j = 0; j < ps->sz; j++)
		{
			printf("%-20s\t", ps->date[j].name);
			printf("%-4d\t", ps->date[j].age);
			printf("%-5s\t", ps->date[j].sex);
			printf("%-12s\t", ps->date[j].num);
			printf("%-20s\n", ps->date[j].addr);
		}
	}
}
//删除信息
void deldate(peoinfo* ps)
{
	char name[20];
	printf("请输入要删除人姓名");
	scanf_s("%s", name, 20);
	if (ps->sz == 0)
	{
		printf("通讯录为空,无法删除\n");
	}
	else
	{
		int ret = find_name(ps, name);

		if (ret == -1)
		{
			printf("要删除的联系人不在该通讯录中\n");
		}
		else
		{
			for (int j = ret; j <=ps->sz - 1; j++)
			{
				ps->date[j] = ps->date[j + 1];
			}
			printf("删除成功\n");
			ps->sz--;
		}
	}
}
//查找数据
void searchdate(peoinfo* ps)
{
	char name[20];
	printf("请输入要查找人姓名");
	scanf_s("%s", name, 20);
	if (ps->sz == 0)
	{
		printf("通讯录为空,无法查找\n");
	}
	else
	{
		int ret = find_name(ps, name);
		if (ret == -1)
		{
			printf("通讯录中无这个人\n");
		}
		else
		{
			printf("姓名:%s\n", ps->date[ret].name);
			printf("年龄:%d\n", ps->date[ret].age);
			printf("性别:%s\n", ps->date[ret].sex);
			printf("电话:%s\n", ps->date[ret].num);
			printf("地址:%s\n", ps->date[ret].addr);
		}
	}
}
//修改信息
void  modifdate(peoinfo* ps)
{
	char name[20];
	printf("请输入要修改人姓名");
	scanf_s("%s", name, 20);
	if (ps->sz == 0)
	{
		printf("通讯录为空,无法查找\n");
	}
	else
	{
		int ret = find_name(ps, name);
		if (ret == -1)
		{
			printf("通讯录中无这个人\n");
		}
		else
		{
			printf("请填写修改后的信息\n");
			printf("请输入姓名");
			scanf_s("%s", ps->date[ret].name, 20);
			printf("请输入年龄");
			scanf_s("%d", &ps->date[ret].age);
			printf("请输入性别");
			scanf_s("%s", ps->date[ret].sex, 5);
			printf("请输入地址");
			scanf_s("%s", ps->date[ret].addr, 50);
			printf("请输入电话号码");
			scanf_s("%s", ps->date[ret].num, 15);
			printf("修改成功\n");
		}
	}
}
//销毁数据
void destroy(peoinfo* ps)
{
	free(ps->date);
	ps->date = NULL;
}
//保存数据
void savedate(peoinfo* ps)
{
	FILE* pf;
	fopen_s(&pf, "contact_date.txt", "wb");
	for (int i = 0; i < ps->sz; i++)
	{
		fwrite(&(ps->date[i]), sizeof(struct people), 1, pf);//将date 里面的数据写到pf所创建的文件中去，以二进制的形式
	}
	fclose(pf);
	pf = NULL;
}
//清除所有数据
void cleardate(peoinfo* ps)
{
	for (int j = 0; j <= ps->sz - 1; j++)
	{
		ps->date[j] = ps->date[j + 1];
	}
	ps->sz = 0;
}
int cmp_age(const void* e1, const void* e2)
{
	return ((struct people*)e1)->age- ((struct people*)e2)->age;
}
void sortdate(peoinfo* ps)
{
	if (ps->sz == 0)
	{
		printf("通讯录为空,无法查找\n");
	}
	else
	{
		int c = 0;
		printf("请输入排序类型（1.姓名 2.年龄）");
		scanf_s("%d", &c);
		//printf("请输入排序类型（1.姓名 2.年龄）");
		if (c == 2)
		{
			//qsort(ps->date, q, sizeof(ps->date[0]),cmp_age);
			printf("排序成功\n");
		}
	}




}
