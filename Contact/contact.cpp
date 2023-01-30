
#include"contact.h"
//����name�±�
 static int find_name(peoinfo* ps, char name[20])//static �޶��ú���ֻ��������ļ���ʹ��
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
 //�鿴����
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
//��ʼ��ͨѶ¼
void confirst(peoinfo* ps)
{
	//memset(ps->date, 0, sizeof(ps->date));
	ps->date = (struct people *)calloc(3, sizeof(struct people));
		ps->sz = 0;
		ps->volume = 3;
		//�����ϴε�����
		loaddate(ps);
}
//��������(����)
void loaddate(peoinfo* ps)
{
	struct people tmp = { 0 };
	FILE* pf;
	fopen_s(&pf, "contact_date.txt", "rb");
	while (fread(&tmp, sizeof(struct people), 1, pf))//fread������һ���޷���������һ�ζ�һ�����ļ��в���������ʱ���᷵�����һ�ζ��ĸ���ֵ
	{
		check(ps);
		ps->date[ps->sz] = tmp;
		ps->sz++;
	}
	fclose(pf);
	pf = NULL;
}

//����ͨѶ¼��Ϣ
void adddate(peoinfo* ps)
{
	    check(ps);
		printf("����������");
		scanf_s("%s", ps->date[ps->sz].name, 20);
		printf("����������");
		scanf_s("%d", &ps->date[ps->sz].age);
		printf("�������Ա�");
		scanf_s("%s", ps->date[ps->sz].sex, 5);
		printf("�������ַ");
		scanf_s("%s", ps->date[ps->sz].addr, 50);
		printf("������绰����");
		scanf_s("%s", ps->date[ps->sz].num, 15);	
		ps->sz++;
		printf("��ӳɹ�\n");
	
}
//�鿴ͨѶ¼
void showdate(peoinfo* ps)
{
	if (ps->sz == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		printf("%-20s\t", "����");
		printf("%-4s\t", "����");
		printf("%-5s\t", "�Ա�");
		printf("%-12s\t", "�绰");
		printf("%-20s\n", "��ַ");
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
//ɾ����Ϣ
void deldate(peoinfo* ps)
{
	char name[20];
	printf("������Ҫɾ��������");
	scanf_s("%s", name, 20);
	if (ps->sz == 0)
	{
		printf("ͨѶ¼Ϊ��,�޷�ɾ��\n");
	}
	else
	{
		int ret = find_name(ps, name);

		if (ret == -1)
		{
			printf("Ҫɾ������ϵ�˲��ڸ�ͨѶ¼��\n");
		}
		else
		{
			for (int j = ret; j <=ps->sz - 1; j++)
			{
				ps->date[j] = ps->date[j + 1];
			}
			printf("ɾ���ɹ�\n");
			ps->sz--;
		}
	}
}
//��������
void searchdate(peoinfo* ps)
{
	char name[20];
	printf("������Ҫ����������");
	scanf_s("%s", name, 20);
	if (ps->sz == 0)
	{
		printf("ͨѶ¼Ϊ��,�޷�����\n");
	}
	else
	{
		int ret = find_name(ps, name);
		if (ret == -1)
		{
			printf("ͨѶ¼���������\n");
		}
		else
		{
			printf("����:%s\n", ps->date[ret].name);
			printf("����:%d\n", ps->date[ret].age);
			printf("�Ա�:%s\n", ps->date[ret].sex);
			printf("�绰:%s\n", ps->date[ret].num);
			printf("��ַ:%s\n", ps->date[ret].addr);
		}
	}
}
//�޸���Ϣ
void  modifdate(peoinfo* ps)
{
	char name[20];
	printf("������Ҫ�޸�������");
	scanf_s("%s", name, 20);
	if (ps->sz == 0)
	{
		printf("ͨѶ¼Ϊ��,�޷�����\n");
	}
	else
	{
		int ret = find_name(ps, name);
		if (ret == -1)
		{
			printf("ͨѶ¼���������\n");
		}
		else
		{
			printf("����д�޸ĺ����Ϣ\n");
			printf("����������");
			scanf_s("%s", ps->date[ret].name, 20);
			printf("����������");
			scanf_s("%d", &ps->date[ret].age);
			printf("�������Ա�");
			scanf_s("%s", ps->date[ret].sex, 5);
			printf("�������ַ");
			scanf_s("%s", ps->date[ret].addr, 50);
			printf("������绰����");
			scanf_s("%s", ps->date[ret].num, 15);
			printf("�޸ĳɹ�\n");
		}
	}
}
//��������
void destroy(peoinfo* ps)
{
	free(ps->date);
	ps->date = NULL;
}
//��������
void savedate(peoinfo* ps)
{
	FILE* pf;
	fopen_s(&pf, "contact_date.txt", "wb");
	for (int i = 0; i < ps->sz; i++)
	{
		fwrite(&(ps->date[i]), sizeof(struct people), 1, pf);//��date ���������д��pf���������ļ���ȥ���Զ����Ƶ���ʽ
	}
	fclose(pf);
	pf = NULL;
}
//�����������
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
		printf("ͨѶ¼Ϊ��,�޷�����\n");
	}
	else
	{
		int c = 0;
		printf("�������������ͣ�1.���� 2.���䣩");
		scanf_s("%d", &c);
		//printf("�������������ͣ�1.���� 2.���䣩");
		if (c == 2)
		{
			//qsort(ps->date, q, sizeof(ps->date[0]),cmp_age);
			printf("����ɹ�\n");
		}
	}




}
