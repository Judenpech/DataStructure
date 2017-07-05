#include<malloc.h>
#define NULL          0
#define TRUE          1
#define FALSE         0
#define OK            1
#define ERROR         0

typedef int Status;
typedef int ElemType;

typedef struct DuLNode                 //双向循环链表结点
{
   ElemType        data;
   struct DuLNode  * prior;
   struct DuLNode  * next;
}DuLNode,* DuLinkList;

typedef struct                         //双向循环链表
{
   DuLinkList  head;                   //双向循环链表头结点，不存放数据
   int         len;                    //双向循环链表中的结点个数，头结点不计
}LinkList;

Status InitList(LinkList &L);
    //构造一个空的线性链表
void ClearList(LinkList &L);
    //将线性链表L重置为空表，并释放原链表的结点空间
Status HeadInser(LinkList &L,ElemType e);
    //在线性链表的头结点后插入数据元素为e的新结点
Status TailInser(LinkList &L,ElemType e);
    //在线性链表的头结点前插入数据元素为e的新结点
Status HeadDelete(LinkList &L);
    //删除头结点后的第一个结点
Status ListCopy(LinkList &L,LinkList L1);
    //将L1复制给L，保持L1不变


Status InitList(LinkList &L)
{//构造一个空的线性链表
   L.head = (DuLinkList)malloc(sizeof(DuLNode));
   L.head->next  = L.head;
   L.head->prior = L.head;
   L.len = 0;
   return OK;
}

void ClearList(LinkList &L)
{//将线性链表L重置为空表，并释放原链表的结点空间
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
{//在线性链表的头结点后插入数据元素为e的新结点
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
{//在线性链表的头结点前插入数据元素为e的新结点
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
{//删除头结点后的第一个结点
   DuLinkList p;
   p = L.head->next;
   p->next->prior = p->prior;
   p->prior->next = p->next;
   free(p);
   --L.len;
   return OK;
}

Status ListCopy(LinkList &L,LinkList L1)
{//将L1复制给L，保持L1不变
   DuLinkList p;
   ClearList(L);
   for(p = L1.head->next;p != L1.head;p = p->next)
	   TailInser(L,p->data);
   return OK;
}