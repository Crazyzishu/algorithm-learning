#include <stdio.h>
#include <malloc.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 初始化一个链表(带头结点)
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
        return false;
    L->next = NULL;
    return true;
}

// 按位序插入
/**
 * @brief 在链表的指定位置插入一个新的节点
 *
 * @param L 指向链表头节点的指针
 * @param i 要插入节点的位置
 * @param e 要插入节点的数据值
 * @return true 插入成功
 * @return false 插入失败
 */
bool ListInsert(LinkList &L, int i, int e)
{
    // 检查插入位置是否合法
    if (i < 1)
        return false;

    // 初始化指针p指向头节点
    LNode *p;
    // 初始化计数器j为0
    int j = 0;
    // 将指针p指向头节点
    p = L;
    // 循环找到第i-1个节点
    while (p != NULL && j < i - 1)
    {
        // 将指针p指向下一个节点
        p = p->next;
        // 计数器j加1
        j++;
    }
    // 检查是否找到第i-1个节点
    if (p == NULL)
        return false;

    // 为新节点分配内存
    LNode *s = (LNode *)malloc(sizeof(LNode));
    // 检查内存分配是否成功
    if (s == NULL)
        return false;

    // 设置新节点的数据域
    s->data = e;
    // 将新节点的指针域指向p的下一个节点
    s->next = p->next;
    // 将p的指针域指向新节点
    p->next = s;

    return true;
}

//尾插法建立单链表
/**
 * @brief 从尾到头创建单链表
 *
 * @param L 指向链表头节点的指针
 * @param n 链表中节点的数量
 * @return true 创建成功
 * @return false 创建失败
 */
bool ListTailInsert(LinkList &L, int n)
{
    // 初始化指针r指向头节点
    LNode *r = L;
    // 循环n次
    for (int i = 0; i < n; i++)
    {
        // 为新节点分配内存
        LNode *p = (LNode *)malloc(sizeof(LNode));
        // 检查内存分配是否成功
        if (p == NULL)
            return false;

        // 输入新节点的数据
        scanf("%d", &p->data);
        // 将新节点的指针域置为NULL
        p->next = NULL;
        // 将r的指针域指向新节点
        r->next = p;
        // 将r指向新节点
        r = p;
    }
    return true;
}

//头插法建立单链表
bool ListHeadInsert(LinkList &L, int n)
{
    // 循环n次
    for (int i = 0; i < n; i++)
    {
        // 为新节点分配内存
        LNode *p = (LNode *)malloc(sizeof(LNode));
        // 检查内存分配是否成功
        if (p == NULL)
            return false;

        // 输入新节点的数据
        scanf("%d", &p->data);
        // 将新节点的指针域指向头节点的下一个节点
        p->next = L->next;
        // 将头节点的指针域指向新节点
        L->next = p;
    }
    return true;
}

// 后插操作
/**
 * @brief 在指定节点之后插入新节点
 *
 * @param p 指向指定节点的指针
 * @param e 要插入的新节点的数据值
 * @return true 插入成功
 * @return false 插入失败
 */
bool InsertNextNode(LNode *p, int e)
{
    // 检查指针p是否为空
    if (p == NULL)
        return false;

    // 为新节点分配内存
    LNode *s = (LNode *)malloc(sizeof(LNode));
    // 检查内存分配是否成功
    if (s == NULL)
        return false;

    // 设置新节点的数据域
    s->data = e;
    // 将新节点的指针域指向p的下一个节点
    s->next = p->next;
    // 将p的指针域指向新节点
    p->next = s;

    return true;
}

// 前插操作
/**
 * @brief 在指定节点之前插入新节点
 *
 * @param p 指向指定节点的指针
 * @param e 要插入的新节点的数据值
 * @return true 插入成功
 * @return false 插入失败
 */
bool InsertPriorNode(LNode *p, int e)
{
    // 检查指针p是否为空
    if (p == NULL)
        return false;

    // 为新节点分配内存
    LNode *s = (LNode *)malloc(sizeof(LNode));
    // 检查内存分配是否成功
    if (s == NULL)
        return false;

    // 设置新节点的数据域
    s->next = p->next;
    // 将p的指针域指向新节点
    p->next = s;
    // 将新节点的数据域设置为p的数据域
    s->data = p->data;
    // 将p的数据域设置为e
    p->data = e;
    return true;
}

// 按位序删除
/**
 * @brief 删除链表中指定位置的节点
 * 
 * @param L 指向链表头节点的指针
 * @param i 要删除节点的位置
 * @param e 用于存储被删除节点的数据值
 * @return true 删除成功
 * @return false 删除失败
 */
bool ListDelete(LinkList &L, int i, int &e)
{
    // 检查删除位置是否合法
    if (i < 1)
        return false;

    // 初始化指针p指向头节点
    LNode *p;
    // 初始化计数器j为0
    int j = 0;
    // 将指针p指向头节点
    p = L;
    // 循环找到第i-1个节点
    while (p != NULL && j < i - 1)
    {
        // 将指针p指向下一个节点
        p = p->next;
        // 计数器j加1
        j++;
    }
    // 检查是否找到第i-1个节点
    if (p == NULL)
        return false;

    // 检查第i个节点是否存在
    if (p->next == NULL)
        return false;

    // 初始化指针q指向第i个节点
    LNode *q = p->next;
    // 将p的指针域指向q的下一个节点
    p->next = q->next;
    // 将e设置为q的数据域
    e = q->data;
    // 释放q的内存
    free(q);
    return true;
}

//按位查找
/**
 * @brief 在链表中查找指定位置的节点
 *
 * @param L 指向链表头节点的指针
 * @param i 要查找节点的位置
 * @param e 用于存储被查找节点的数据值
 * @return true 查找成功
 * @return false 查找失败
 */
bool GetElem(LinkList L, int i, int &e)
{
    // 检查查找位置是否合法
    if (i < 1)
        return false;

    // 初始化指针p指向头节点
    LNode *p;
    // 初始化计数器j为0
    int j = 0;
    // 将指针p指向头节点
    p = L;
    // 循环找到第i个节点
    while (p!= NULL && j < i)
    {
        // 将指针p指向下一个节点
        p = p->next;
        // 计数器j加1
        j++;
    }
    // 检查是否找到第i个节点
    if (p == NULL)
        return false;

    // 将e设置为p的数据域
    e = p->data;
    return true;
}

// 按值查找
/**
 * @brief 在链表中查找指定值的节点
 *
 * @param L 指向链表头节点的指针
 * @param e 要查找的节点的数据值
 * @return LNode* 指向被查找节点的指针，如果未找到则返回NULL
 */
LNode *LocateElem(LinkList L, int e)
{
    // 初始化指针p指向头节点
    LNode *p = L->next;
    // 循环遍历链表，直到找到值为e的节点或到达链表末尾
    //p接收到NULL时，代表链表结束
    while (p!= NULL && p->data != e)
    {
        // 将指针p指向下一个节点
        p = p->next;
    }
    // 返回指向被查找节点的指针
    return p;
}

//求单链表的长度
int length(LinkList L){
    int len = 0;
    LNode *p = L;
    while(p->next!=NULL){
        p = p->next;
        len++;
    }
    return len;
}

int main()
{
    LinkList L;
    InitList(L);

    return 0;
}