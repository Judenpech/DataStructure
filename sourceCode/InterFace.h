#include"LinkList.h"
#include"LongNum.h"
char ShowMenu()
{//��ʾ���˵�,����ѡ��
	char i;
	system("cls");
	printf("\t\t***************************************\n");
	printf("\t\t1.�ӷ�\t\t2.����\t\t3.�˳�\n");
	printf("\t\t***************************************\n\n����ѡ��:");
	i=getch();
	fflush(stdin);
	while(i>'3'||i<'1')
	{//���������
		i=getch();
		fflush(stdin);
	}
	return i;
}

char ShowPlus()
{//���һ�μӷ����㣬������һ������
	char i=0;
	LinkList a,b,c;
	InitList(a);InitList(b);InitList(c);
	system("cls");
	printf("********\n�ӷ�����\n********\n");
	printf("����������A����λһ�飬�ö��Ÿ�������\n\n");
	printf("A: ");ScanNum(a);
	printf("\n����������B����λһ�飬�ö��Ÿ�������\n\n");
	printf("B: ");ScanNum(b);
	fflush(stdin);
	NumPlus(a,b,c);
	printf("\nA+B= ");
	PrintNum(c);putch('\n');
	ClearList(a);ClearList(b);ClearList(c);
	printf("\n\n\n\n��ѡ��:\n\n1.����\t\t2.����\n");	
	while(i!='1'&&i!='2')
	{
		i=getch();
	}	
	fflush(stdin);
	return i;
}

char ShowMinus()
{//���һ�μ������㣬������һ������
	char i=0;
	LinkList a,b,c;
	InitList(a);InitList(b);InitList(c);
	system("cls");
	printf("********\n��������\n********\n");
	printf("����������A����λһ�飬�ö��Ÿ�����\n\n");
	printf("A: ");ScanNum(a);
	printf("\n����������B����λһ�飬�ö��Ÿ�������\n\n");
	printf("B: ");ScanNum(b);
	fflush(stdin);
	NumMinus(a,b,c);
	printf("\nA-B= ");
	PrintNum(c);putch('\n');
	ClearList(a);ClearList(b);ClearList(c);
	printf("\n\n\n\n��ѡ��:\n\n1.����\t\t2.����\n");	
	while(i!='1'&&i!='2')
	{
		i=getch();
	}	
	fflush(stdin);
	return i;	
}