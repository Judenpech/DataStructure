void ScanNum(LinkList &L);
    //从键盘输入一个长整数，存至L
void PrintNum(LinkList L);
    //在屏幕打印长整数L
void NumPlus(LinkList L1,LinkList L2,LinkList &L3);
    //将L1与L2相加，结果存至L3
void NumChange(LinkList &L);
    //将长整数L还原成一般格式
void NumMinus(LinkList L1,LinkList L2,LinkList &L3);
    //计算L1减去L2的值，结果存至L3
void ScanNum(LinkList &L)
{//从键盘输入一个长整数，存至L
   ElemType e;
   ClearList(L);
   fflush(stdin);
   scanf("%5d",&e);                              //首结点可能为负数，需要5位
   TailInser(L,e);
   while(getchar() == ',')                       //输入未结束
   {
      scanf("%4d",&e);                           //非首结点，只需4位
	  TailInser(L,e);
   }
}

void PrintNum(LinkList L)
{//在屏幕打印长整数L
   DuLinkList p;
   if(L.len)
   {
      p = L.head->next;
	  printf("%d",p->data);
	  while(p->next != L.head)
	  {
	     p = p->next;
		 printf(",%04d",p->data);
	  }
   }
}

void NumPlus(LinkList L1,LinkList L2,LinkList &L3)
{//将L1与L2相加，结果存至L3
   LinkList La,Lb,p;
   DuLinkList p1,p2;
   InitList(La);
   InitList(Lb);
   InitList(p);
   ListCopy(La,L1);                              //保持L1、L2不被破坏
   ListCopy(Lb,L2);
   while(La.len > 1 && La.head->next->data == 0)     //清除值等于0的首结点，若只剩一个结点，则结束
		HeadDelete(La);
   while(Lb.len > 1 && Lb.head->next->data == 0)
		HeadDelete(Lb);
   if(La.head->next->data < 0)                                       //负数，还原每个结点的真值
	   for(p1 = La.head->next->next;p1 != La.head;p1 = p1->next)
		   p1->data *= -1;
   if(Lb.head->next->data < 0)
	   for(p1 = Lb.head->next->next;p1 != Lb.head;p1 = p1->next)
		   p1->data *= -1;
   if(La.len > Lb.len)                           //取较长的长整数作为结果的基础
   {
      ListCopy(L3,La);
	  p = Lb;
	  p2 = Lb.head->prior;
   }//if
   else
   {
      ListCopy(L3,Lb);
	  p = La;
	  p2 = La.head->prior;
   }//else
   for(p1 = L3.head->prior;p1 != L3.head && p2 != p.head;p1 = p1->prior,p2 = p2->prior)
	   p1->data += p2->data;                     //真值相加
   NumChange(L3);                                //还原回一般格式
   ClearList(La);
   ClearList(Lb);
}

void NumChange(LinkList &L)
{//将长整数L还原成一般格式
	DuLinkList p;
	int m = 0;               //负数标记
	while(L.len > 1 && L.head->next->data == 0)  //清除值等于0的首结点，若只剩一个结点，则结束
		HeadDelete(L);
	if(L.head->next->data < 0)                   //负数，先转换成正数还原
	{
		for(p = L.head->next;p != L.head;p = p->next)
			p->data *= -1;
		m = 1;                                   //负数标记置1
	}
	for(p =L.head->prior;p != L.head;p = p->prior)
	{
		if(p->data > 9999)                       //进位
		{
			if(p->prior != L.head)
				p->prior->data += p->data / 10000;
			else
				HeadInser(L,p->data / 10000);
			p->data %= 10000;
		}//if
		if(p->data < 0)                          //借位
		{
			if(p->prior != L.head)
			{
				p->prior->data -= 1;
				p->data += 10000;
				p = p->next;
			}//if
			else if(p->data < -9999)             //p为第一个结点，且值小于-9999需要调整
			{
				HeadInser(L,p->data / 10000);
				p->data = -(p->data % 10000);
			}//else if
		}//if
	}//for
	while(L.len > 1 && L.head->next->data == 0)  //清除值等于0的首结点，若只剩一个结点，则结束
		HeadDelete(L);
	if(m)                                        //负数标记为1，添负号
		L.head->next->data *= -1;
}

void NumMinus(LinkList L1,LinkList L2,LinkList &L3)
{//计算L1减去L2的值，结果存至L3
	LinkList La,Lb;
	InitList(La);
	InitList(Lb);
	ListCopy(La,L1);
    ListCopy(Lb,L2);
	while(Lb.len > 1 && Lb.head->next->data == 0)
		HeadDelete(Lb);
	Lb.head->next->data *= -1;
	NumPlus(La,Lb,L3);
	ClearList(La);
	ClearList(Lb);
}