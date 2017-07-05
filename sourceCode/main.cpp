#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>
#include "Interface.h"

void main()
{
	char select,i;
	i='1';
	while(1)
	{
		select=ShowMenu();
		switch(select)
		{
			case '1':	
				while(i=='1')
				{i=ShowPlus();}
				i='1';
				break;
			case '2':
				while(i=='1')
				{i=ShowMinus();}
				i='1';
				break;
			case '3':
				printf("3\n\n感谢使用，再见！\n");
			default :break;
		}
		if(select=='3')break;
	}
	getch();
}