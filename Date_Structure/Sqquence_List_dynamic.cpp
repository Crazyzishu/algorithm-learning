#include <stdio.h>
#include <malloc.h>
#define InitSize 10 // 默认最大长度

// 动态分配-顺序表
typedef struct
{
    int *data; // 指示动态分配数组的指针
    int MaxSize;
    int length;
} SqList;

// 初始化一个顺序表
void InitList(SqList &L)
{
    // 用malloc函数申请一片连续的存储空间
    L.data = (int *)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}

// 增加动态数组的长度
void IncreaseSize(SqList &L, int len)
{
    int *p = L.data;
    // 用malloc函数申请一片连续的存储空间
    L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = p[i]; // 将数据复制到新区域,时间开销大
    }
}

// 查找操作-按位查找
int GetElem(SqList L, int i)
{
    return L.data[i - 1];
}

// 查找操作-按值查找
int LocateElem(SqList L, int e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        // 查找成功，返回其逻辑位序i+1
            return i + 1;
    }
    return 0;
}

// 插入操作
bool ListInsert(SqList &L, int i, int e)
{
    // 判断i的范围是否有效
    if (i < 1 || i > L.length + 1)
        return false;
    // 判断存储空间是否已满
    if (L.length >= L.MaxSize)
        return false;
    // 将第i个元素及之后的元素后移
    for (int j = L.length; j >= i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;
    L.length++;
    return true;
}

// 删除操作
bool ListDelete(SqList &L, int i, int &e)
{
    if (i < 1 || i > L.length)
        return false;
    // 将被删除的元素赋值给e
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
        // 将第i+1个元素及之后的元素前移
        L.data[j - 1] = L.data[j];
    L.length--;
    return true;
}

//比较结构体是否相等，一个个比较其中的内容，时间复杂度O(n)，空间复杂度O(1)
bool equal(SqList L1, SqList L2)
{
    if (L1.length != L2.length)
        return false;
    for (int i = 0; i < L1.length; i++)
    {
        if (L1.data[i] != L2.data[i])
            return false;
    }
    return true;
}
// 销毁顺序表
void DestroyList(SqList &L)
{
    free(L.data);
}

int main()
{
    SqList L;
    InitList(L);
    IncreaseSize(L, 5);
    return 0;
}