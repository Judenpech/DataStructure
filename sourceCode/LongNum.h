void ScanNum(LinkList &L);
    //�Ӽ�������һ��������������L
void PrintNum(LinkList L);
    //����Ļ��ӡ������L
void NumPlus(LinkList L1,LinkList L2,LinkList &L3);
    //��L1��L2��ӣ��������L3
void NumChange(LinkList &L);
    //��������L��ԭ��һ���ʽ
void NumMinus(LinkList L1,LinkList L2,LinkList &L3);
    //����L1��ȥL2��ֵ���������L3
void ScanNum(LinkList &L)
{//�Ӽ�������һ��������������L
   ElemType e;
   ClearList(L);
   fflush(stdin);
   scanf("%5d",&e);                              //�׽�����Ϊ��������Ҫ5λ
   TailInser(L,e);
   while(getchar() == ',')                       //����δ����
   {
      scanf("%4d",&e);                           //���׽�㣬ֻ��4λ
	  TailInser(L,e);
   }
}

void PrintNum(LinkList L)
{//����Ļ��ӡ������L
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
{//��L1��L2��ӣ��������L3
   LinkList La,Lb,p;
   DuLinkList p1,p2;
   InitList(La);
   InitList(Lb);
   InitList(p);
   ListCopy(La,L1);                              //����L1��L2�����ƻ�
   ListCopy(Lb,L2);
   while(La.len > 1 && La.head->next->data == 0)     //���ֵ����0���׽�㣬��ֻʣһ����㣬�����
		HeadDelete(La);
   while(Lb.len > 1 && Lb.head->next->data == 0)
		HeadDelete(Lb);
   if(La.head->next->data < 0)                                       //��������ԭÿ��������ֵ
	   for(p1 = La.head->next->next;p1 != La.head;p1 = p1->next)
		   p1->data *= -1;
   if(Lb.head->next->data < 0)
	   for(p1 = Lb.head->next->next;p1 != Lb.head;p1 = p1->next)
		   p1->data *= -1;
   if(La.len > Lb.len)                           //ȡ�ϳ��ĳ�������Ϊ����Ļ���
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
	   p1->data += p2->data;                     //��ֵ���
   NumChange(L3);                                //��ԭ��һ���ʽ
   ClearList(La);
   ClearList(Lb);
}

void NumChange(LinkList &L)
{//��������L��ԭ��һ���ʽ
	DuLinkList p;
	int m = 0;               //�������
	while(L.len > 1 && L.head->next->data == 0)  //���ֵ����0���׽�㣬��ֻʣһ����㣬�����
		HeadDelete(L);
	if(L.head->next->data < 0)                   //��������ת����������ԭ
	{
		for(p = L.head->next;p != L.head;p = p->next)
			p->data *= -1;
		m = 1;                                   //���������1
	}
	for(p =L.head->prior;p != L.head;p = p->prior)
	{
		if(p->data > 9999)                       //��λ
		{
			if(p->prior != L.head)
				p->prior->data += p->data / 10000;
			else
				HeadInser(L,p->data / 10000);
			p->data %= 10000;
		}//if
		if(p->data < 0)                          //��λ
		{
			if(p->prior != L.head)
			{
				p->prior->data -= 1;
				p->data += 10000;
				p = p->next;
			}//if
			else if(p->data < -9999)             //pΪ��һ����㣬��ֵС��-9999��Ҫ����
			{
				HeadInser(L,p->data / 10000);
				p->data = -(p->data % 10000);
			}//else if
		}//if
	}//for
	while(L.len > 1 && L.head->next->data == 0)  //���ֵ����0���׽�㣬��ֻʣһ����㣬�����
		HeadDelete(L);
	if(m)                                        //�������Ϊ1������
		L.head->next->data *= -1;
}

void NumMinus(LinkList L1,LinkList L2,LinkList &L3)
{//����L1��ȥL2��ֵ���������L3
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