#include<malloc.h>
#define NULL          0
#define TRUE          1
#define FALSE         0
#define OK            1
#define ERROR         0

typedef int Status;
typedef int ElemType;

typedef struct DuLNode                 //˫��ѭ��������
{
   ElemType        data;
   struct DuLNode  * prior;
   struct DuLNode  * next;
}DuLNode,* DuLinkList;

typedef struct                         //˫��ѭ������
{
   DuLinkList  head;                   //˫��ѭ������ͷ��㣬���������
   int         len;                    //˫��ѭ�������еĽ�������ͷ��㲻��
}LinkList;

Status InitList(LinkList &L);
    //����һ���յ���������
void ClearList(LinkList &L);
    //����������L����Ϊ�ձ����ͷ�ԭ����Ľ��ռ�
Status HeadInser(LinkList &L,ElemType e);
    //�����������ͷ�����������Ԫ��Ϊe���½��
Status TailInser(LinkList &L,ElemType e);
    //�����������ͷ���ǰ��������Ԫ��Ϊe���½��
Status HeadDelete(LinkList &L);
    //ɾ��ͷ����ĵ�һ�����
Status ListCopy(LinkList &L,LinkList L1);
    //��L1���Ƹ�L������L1����


Status InitList(LinkList &L)
{//����һ���յ���������
   L.head = (DuLinkList)malloc(sizeof(DuLNode));
   L.head->next  = L.head;
   L.head->prior = L.head;
   L.len = 0;
   return OK;
}

void ClearList(LinkList &L)
{//����������L����Ϊ�ձ����ͷ�ԭ����Ľ��ռ�
   DuLinkList p;
   while(L.head->next != L.head)
   {
      p = L.head->next;
	  p->next->prior = p->prior;
	  p->prior->next = p->next;
	  free(p);
   }
   L.len = 0;
}

Status HeadInser(LinkList &L,ElemType e)
{//�����������ͷ�����������Ԫ��Ϊe���½��
   DuLinkList p;
   p = (DuLinkList)malloc(sizeof(DuLNode));
   p->data = e;
   p->next = L.head->next;
   p->prior = L.head;
   L.head->next->prior = p;
   L.head->next = p;
   ++L.len;
   return OK;
}

Status TailInser(LinkList &L,ElemType e)
{//�����������ͷ���ǰ��������Ԫ��Ϊe���½��
   DuLinkList p;
   p = (DuLinkList)malloc(sizeof(DuLNode));
   p->data = e;
   p->prior = L.head->prior;
   p->next = L.head;
   L.head->prior->next = p;
   L.head->prior = p;
   ++L.len;
   return OK;
}

Status HeadDelete(LinkList &L)
{//ɾ��ͷ����ĵ�һ�����
   DuLinkList p;
   p = L.head->next;
   p->next->prior = p->prior;
   p->prior->next = p->next;
   free(p);
   --L.len;
   return OK;
}

Status ListCopy(LinkList &L,LinkList L1)
{//��L1���Ƹ�L������L1����
   DuLinkList p;
   ClearList(L);
   for(p = L1.head->next;p != L1.head;p = p->next)
	   TailInser(L,p->data);
   return OK;
}