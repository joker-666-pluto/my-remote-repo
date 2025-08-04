/*
顺序表的静态分配
*/
#include <stdio.h>
#define InitSize 10
#define ElemType int

typedef struct 
{
    ElemType data[InitSize];
    int length;
}SqList;

void InitList(SqList &L)
{
    for(int i=0;i<InitSize;i++){
        L.data[i]=0;
    }
    L.length=0;
}

void iterList(SqList &L)
{
    for(int i=0;i<L.length;i++)
    {
        printf("%d,",L.data[i]);
    }
    printf("\n");
}
bool ListInsert(SqList &L,int i,int e)
{
    if(i<1||i>L.length+1)
        return false;
    if (L.length>=InitSize)
        return false;
    // 将第i个以及以后元素后移
    for(int j=L.length;j>=i;j--)
    {
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;
    L.length++;
    return true;
}

bool ListDelete(SqList &L,int i,int &e){
    if(i<1||i>L.length)
        return false;
    e=L.data[i-1];
    for(int j=i;j<L.length;j++){
        L.data[j-1]=L.data[j];
    }
    L.length--;
    return true;
}

ElemType GetElem(SqList &L,int i)
{
    return L.data[i-1];
}

int LocateElem(SqList &L,ElemType e)
{
    for(int i=0;i<L.length;i++)
    {
        if(L.data[i]==e)
            return i+1;
    }
    return 0;
}
int main()
{
    SqList L;
    int e;  // 用于存储删除的元素
    
    printf("=== 顺序表操作演示 ===\n\n");
    
    // 1. 初始化顺序表
    printf("1. 初始化顺序表\n");
    InitList(L);
    printf("初始化完成，当前长度：%d\n", L.length);
    printf("当前列表内容：");
    iterList(L);
    printf("\n");
    
    // 2. 插入元素
    printf("2. 插入元素测试\n");
    printf("在位置1插入元素10：%s\n", ListInsert(L, 1, 10) ? "成功" : "失败");
    printf("在位置2插入元素20：%s\n", ListInsert(L, 2, 20) ? "成功" : "失败");
    printf("在位置3插入元素30：%s\n", ListInsert(L, 3, 30) ? "成功" : "失败");
    printf("在位置2插入元素15：%s\n", ListInsert(L, 2, 15) ? "成功" : "失败");
    printf("当前长度：%d\n", L.length);
    printf("当前列表内容：");
    iterList(L);
    printf("\n");
    
    // 3. 查找元素
    printf("3. 查找元素测试\n");
    printf("查找元素15的位置：%d\n", LocateElem(L, 15));
    printf("查找元素30的位置：%d\n", LocateElem(L, 30));
    printf("查找元素99的位置：%d (不存在时返回0)\n", LocateElem(L, 99));
    printf("\n");
    
    // 4. 按位置获取元素
    printf("4. 按位置获取元素测试\n");
    printf("第1个元素：%d\n", GetElem(L, 1));
    printf("第3个元素：%d\n", GetElem(L, 3));
    printf("第4个元素：%d\n", GetElem(L, 4));
    printf("\n");
    
    // 5. 删除元素
    printf("5. 删除元素测试\n");
    printf("删除前的状态：");
    iterList(L);
    printf("删除前长度：%d\n", L.length);
    
    bool result1 = ListDelete(L, 2, e);
    printf("删除第2个元素：%s", result1 ? "成功" : "失败");
    if(result1) {
        printf("，删除的元素是：%d\n", e);
    } else {
        printf("\n");
    }
    printf("删除后长度：%d\n", L.length);
    printf("删除后内容：");
    iterList(L);
    
    printf("删除前的状态：");
    iterList(L);
    printf("删除前长度：%d\n", L.length);
    
    bool result2 = ListDelete(L, 1, e);
    printf("删除第1个元素：%s", result2 ? "成功" : "失败");
    if(result2) {
        printf("，删除的元素是：%d\n", e);
    } else {
        printf("\n");
    }
    printf("删除后长度：%d\n", L.length);
    printf("删除后内容：");
    iterList(L);
    printf("\n");
    
    // 6. 边界测试
    printf("6. 边界条件测试\n");
    printf("在无效位置0插入元素：%s\n", ListInsert(L, 0, 5) ? "成功" : "失败");
    printf("在超出范围位置插入元素：%s\n", ListInsert(L, 10, 5) ? "成功" : "失败");
    printf("删除无效位置0的元素：%s\n", ListDelete(L, 0, e) ? "成功" : "失败");
    printf("删除超出范围位置的元素：%s\n", ListDelete(L, 10, e) ? "成功" : "失败");
    printf("\n");
    
    // 7. 填满顺序表测试
    printf("7. 填满顺序表测试\n");
    printf("当前长度：%d，最大容量：%d\n", L.length, InitSize);
    for(int i = L.length + 1; i <= InitSize; i++) {
        ListInsert(L, i, i * 10);
    }
    printf("填满后长度：%d\n", L.length);
    printf("填满后列表内容：");
    iterList(L);
    
    printf("尝试再插入一个元素：%s\n", ListInsert(L, L.length + 1, 999) ? "成功" : "失败（列表已满）");
    
    return 0;
}