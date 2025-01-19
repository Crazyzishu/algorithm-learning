#include <stdio.h>
#define MaxSize 10 // 默认最大长度

// 静态分配-顺序表
typedef struct
{
    int data[MaxSize];
    int length;
} SqList;

// 初始化一个顺序表
void InitList(SqList &L)
{
    for (int i = 0; i < MaxSize; i++)
    {
        L.data[i] = 0;
    }
    L.length = 0;
}

// 插入,平均时间复杂度O(n)
bool ListInsert(SqList &L, int i, int e)
{
    // 判断i的范围是否有效
    if (i < 1 || i > L.length + 1)
        return false;
    // 判断存储空间是否已满
    if (L.length >= MaxSize)
        return false;
    // 将第i个元素及之后的元素后移
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

// 删除,平均时间复杂度O(n)
bool ListDelete(SqList &L, int i, int &e)
{
    if (i < 1 || i > L.length)
        return false;
    //将被删除的元素赋值给e
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
    //将第i+1个元素及之后的元素前移
        L.data[j - 1] = L.data[j];
    L.length--;
    return true;
}

int main()
{
    SqList L;
    InitList(L);
    ListInsert(L, 1, 3);
    ListInsert(L, 2, 5);
    ListInsert(L, 3, 7);
    ListInsert(L, 4, 9);
    int e = -1;//用变量e把要删除的元素返回
    if (ListDelete(L, 3, e))
    for (int i = 0; i < L.length; i++)
    {
        printf("%d ", L.data[i]);
    }
}