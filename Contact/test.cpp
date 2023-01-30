//文件版通讯录实现
#include"contact.h"
void menu()
{
	
	printf("******1.add      2.del**********\n");
	printf("******3.search   4.modify*******\n"); 
	printf("******5.show     6.sort*********\n");
	printf("*****      7.save      *********\n");
	printf("******8.clear    0 down*********\n");
	
}


int main()
{
	int a = 0;
	int b = 0;
	//创建通讯录
	peoinfo con;
//初始化通讯录
	confirst(&con);
	do
	{
		system("cls");
		menu();
		printf("请输入选项");
		scanf_s("%d", &a);
		switch (a)
		{
		case add:
			system("cls");
			adddate(&con);
			Sleep(1000);
			break;
		case del:
			system("cls");
			deldate(&con);
			Sleep(1000);
			break;
		case search:
			system("cls");
			searchdate(&con);
			Sleep(3000);
			break;
		case modify:
			system("cls");
			modifdate(&con);
			Sleep(3000);
			break;
		case show:
			system("cls");
			showdate(&con);
			Sleep(5000);
			break;
		case save:
			system("cls");
			savedate(&con);
			printf("数据已保存");
			Sleep(2000);
			break;
		case sort:
			system("cls");
			sortdate(&con);
			Sleep(2000);
			break;
		case clear:
			cleardate(&con);
			printf("已删除所有数据\n");
			Sleep(2000);
			break;
		case down:
			system("cls");
			printf("您是否选择在退出前保存数据（希望请按1，不希望请按0）");
			scanf_s("%d", &b);
			if (b == 1)
			{
				savedate(&con);
			}
			else
			{
				printf("未保存数据,");
			}
			destroy(&con);
			printf("已退出通讯录\n");
			break;
		default:
			system("cls");
			printf("输入类型错误，请重新输入\n");
			break;
		}
	} while (a);
	return 0;
}
