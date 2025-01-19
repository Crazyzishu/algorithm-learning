#include<stdio.h>
#include<malloc.h>
typedef struct DNode{
    int data;
    struct DNode *prior,*next;
}DNode,*DLinkList;

//初始化一个双向链表(带头结点)
bool InitDLinkList(DLinkList &L){
    L=(DNode*)malloc(sizeof(DNode));
    if(L==NULL)
        return false;
    L->prior=NULL;
    L->next=NULL;
    return true;
}

//判断双向链表是否为空
bool Empty(DLinkList L){
    //判断头结点的next是否为空,为空则没有下一个节点，为空表
    if(L->next==NULL)
        return true;
    else
        return false;
}

//双链表的插入(后插)
bool InsertNextDNode(DNode *p,DNode *s){
    //判断p和s是否为空
    if(p==NULL||s==NULL)
        return false;
    //将s的next指向p的next
    s->next=p->next;
    //判断p的next是否为空
    if(p->next!=NULL)
        //将p的next的prior指向s
        p->next->prior=s;
    //将s的prior指向p
    s->prior=p;
    //将p的next指向s
    p->next=s;
    return true;
}

//双链表的删除
bool DeleteNextDNode(DNode *p,DNode *&q){
    //判断p是否为空
    if(p==NULL)
        return false;
    //将q指向p的next
    q=p->next;
    //判断q是否为空
    if(q==NULL)
        return false;
    //将p的next指向q的next
    p->next=q->next;
    //判断q的next是否为空
    if(q->next!=NULL)
        //将q的next的prior指向p
        q->next->prior=p;
    free(q);
    return true;
}

//销毁双链表
void DestroyList(DLinkList &L){
    //循环删除头结点的下一个节点
    while(L->next!=NULL)
        DeleteNextDNode(L,L->next);
    free(L);
    //将L置为空
    L=NULL;
}

//打印双链表(后向遍历)
void PrintList(DLinkList L){
    //将p指向头结点的下一个节点
    DNode *p=L->next;
    //循环打印
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;//将p指向下一个节点
    }
    printf("\n");
}

//打印双链表(前向遍历)
void PrintList2(DLinkList L){
    //将p指向尾结点
    DNode *p=L;
    //循环打印
    while(p->prior!=NULL){
        printf("%d ",p->data);
        p=p->prior;//将p指向上一个节点
    }
    printf("\n");
}

//前向遍历(跳过头节点)
void PrintList3(DLinkList L){
    //将p指向头结点的下一个节点
    DNode *p=L->next;
    //循环打印
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;//将p指向下一个节点
    }
    printf("\n");
}

//后向遍历(跳过头节点)
void PrintList4(DLinkList L){
    //将p指向尾结点
    DNode *p=L->prior;
    //循环打印
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->prior;//将p指向上一个节点
    }
    printf("\n");
}