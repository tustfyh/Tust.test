//�ļ���ͨѶ¼ʵ��
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
	//����ͨѶ¼
	peoinfo con;
//��ʼ��ͨѶ¼
	confirst(&con);
	do
	{
		system("cls");
		menu();
		printf("������ѡ��");
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
			printf("�����ѱ���");
			Sleep(2000);
			break;
		case sort:
			system("cls");
			sortdate(&con);
			Sleep(2000);
			break;
		case clear:
			cleardate(&con);
			printf("��ɾ����������\n");
			Sleep(2000);
			break;
		case down:
			system("cls");
			printf("���Ƿ�ѡ�����˳�ǰ�������ݣ�ϣ���밴1����ϣ���밴0��");
			scanf_s("%d", &b);
			if (b == 1)
			{
				savedate(&con);
			}
			else
			{
				printf("δ��������,");
			}
			destroy(&con);
			printf("���˳�ͨѶ¼\n");
			break;
		default:
			system("cls");
			printf("�������ʹ�������������\n");
			break;
		}
	} while (a);
	return 0;
}
