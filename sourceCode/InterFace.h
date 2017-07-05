#include"LinkList.h"
#include"LongNum.h"
char ShowMenu()
{//显示主菜单,返回选择
	char i;
	system("cls");
	printf("\t\t***************************************\n");
	printf("\t\t1.加法\t\t2.减法\t\t3.退出\n");
	printf("\t\t***************************************\n\n输入选择:");
	i=getch();
	fflush(stdin);
	while(i>'3'||i<'1')
	{//输入出错处理
		i=getch();
		fflush(stdin);
	}
	return i;
}

char ShowPlus()
{//完成一次加法运算，返回下一步操作
	char i=0;
	LinkList a,b,c;
	InitList(a);InitList(b);InitList(c);
	system("cls");
	printf("********\n加法运算\n********\n");
	printf("请输入数据A（四位一组，用逗号隔开）：\n\n");
	printf("A: ");ScanNum(a);
	printf("\n请输入数据B（四位一组，用逗号隔开）：\n\n");
	printf("B: ");ScanNum(b);
	fflush(stdin);
	NumPlus(a,b,c);
	printf("\nA+B= ");
	PrintNum(c);putch('\n');
	ClearList(a);ClearList(b);ClearList(c);
	printf("\n\n\n\n请选择:\n\n1.继续\t\t2.返回\n");	
	while(i!='1'&&i!='2')
	{
		i=getch();
	}	
	fflush(stdin);
	return i;
}

char ShowMinus()
{//完成一次减法运算，返回下一步操作
	char i=0;
	LinkList a,b,c;
	InitList(a);InitList(b);InitList(c);
	system("cls");
	printf("********\n减法运算\n********\n");
	printf("请输入数据A（四位一组，用逗号隔开）\n\n");
	printf("A: ");ScanNum(a);
	printf("\n请输入数据B（四位一组，用逗号隔开）：\n\n");
	printf("B: ");ScanNum(b);
	fflush(stdin);
	NumMinus(a,b,c);
	printf("\nA-B= ");
	PrintNum(c);putch('\n');
	ClearList(a);ClearList(b);ClearList(c);
	printf("\n\n\n\n请选择:\n\n1.继续\t\t2.返回\n");	
	while(i!='1'&&i!='2')
	{
		i=getch();
	}	
	fflush(stdin);
	return i;	
}