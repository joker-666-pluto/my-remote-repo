/*
顺序表的动态分配
*/
#include <stdio.h>
#include <stdlib.h>
#define InitSize 10
#define ElemType int

typedef struct 
{
    ElemType *data;
    int length,MaxSize;
}SqList;

void InitList(SqList &L)
{
    L.data=(ElemType*)malloc(InitSize*sizeof(ElemType));
    L.length=0;
    L.MaxSize=InitSize;
}

void IncreaseSize(SqList &L,int len)
{
    int *p=L.data;
    L.data=(ElemType*)malloc((L.MaxSize+len)*sizeof(ElemType));
    for(int i=0;i<L.length;i++) //迁移数据
    {
        L.data[i]=p[i];
    }
    L.MaxSize=L.MaxSize+len;
    free(p);
}

int main()
{
    SqList L;
    InitList(L);
    IncreaseSize(L,5);
    return 0;
}