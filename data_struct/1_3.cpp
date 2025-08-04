#include <stdio.h>
#include <stdlib.h>
#define ElemType int
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

bool InitList_head(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
        return false;
    L->next = NULL; // L本身是一个指针，所以要用->
    return true;
}

bool Empty_head(LinkList &L)
{
    if (L->next == NULL)
        return true;
    else
        return false;
}

bool ListInsert_head(LinkList &L, int i, ElemType e)
{
    // 带头结点的插入
    if (i < 1) // 不合法
        return false;
    // 循环找到第i-1个节点
    LNode *p;
    int j = 0; // 当前指向的是第0个结点，也就是头结点
    p = L;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL) // 越界
        return false;
    // 现在p指向第i-1个结点，开始插入元素
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 后插
bool InsertNextNode(LNode *p, ElemType e)
{
    if (p == NULL) // 非法
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) // 内存分配失败
        return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 前插
bool InsertPriorNode(LNode *p, ElemType e)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
        return false;
    // 本质上是先后插，然后交换两个结点的元素
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

bool ListDelete(LinkList &L, int i, ElemType &e)
{
    if (i < 1)
        return false;
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    if (p->next == NULL)
        return false;
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

// 删除指定结点，p最后一个结点的时候不能用
bool DeleteNode(LNode *p)
{
    if (p == NULL)
        return false;
    LNode *q = p->next;
    p->data = q->data;
    p->next = q->next;
    free(q);
    return true;
}

LNode *GetElem(LinkList &L, int i)
{
    // 按位查找
    if (i < 0)
        return NULL;
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

LNode *LocateElem(LinkList &L, ElemType e)
{
    LNode *p = L->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p;
}

int Length(LinkList &L)
{
    int len = 0;
    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

// 辅助函数：打印链表
void PrintList(LinkList &L)
{
    LNode *p = L->next; // 跳过头结点
    printf("链表内容: ");
    if (p == NULL)
    {
        printf("(空链表)");
    }
    else
    {
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
    }
    printf("\n");
}

// 辅助函数：释放链表内存
void DestroyList(LinkList &L)
{
    LNode *p = L;
    while (p != NULL)
    {
        LNode *temp = p;
        p = p->next;
        free(temp);
    }
    L = NULL;
}

int main()
{
    LinkList L;
    ElemType deleteValue;

    printf("=== 单链表(带头结点)功能测试 ===\n\n");

    // 1. 测试初始化
    printf("1. 测试链表初始化:\n");
    if (InitList_head(L))
    {
        printf("   链表初始化成功\n");
    }
    else
    {
        printf("   链表初始化失败\n");
        return -1;
    }

    // 2. 测试空链表判断
    printf("\n2. 测试空链表判断:\n");
    if (Empty_head(L))
    {
        printf("   链表为空\n");
    }
    else
    {
        printf("   链表不为空\n");
    }

    // 3. 测试插入操作
    printf("\n3. 测试插入操作:\n");
    printf("   在位置1插入元素10: ");
    if (ListInsert_head(L, 1, 10))
    {
        printf("成功\n");
        PrintList(L);
    }
    else
    {
        printf("失败\n");
    }

    printf("   在位置1插入元素20: ");
    if (ListInsert_head(L, 1, 20))
    {
        printf("成功\n");
        PrintList(L);
    }
    else
    {
        printf("失败\n");
    }

    printf("   在位置2插入元素30: ");
    if (ListInsert_head(L, 2, 30))
    {
        printf("成功\n");
        PrintList(L);
    }
    else
    {
        printf("失败\n");
    }

    printf("   在位置4插入元素40: ");
    if (ListInsert_head(L, 4, 40))
    {
        printf("成功\n");
        PrintList(L);
    }
    else
    {
        printf("失败\n");
    }

    // 测试越界插入
    printf("   在位置10插入元素50(越界测试): ");
    if (ListInsert_head(L, 10, 50))
    {
        printf("成功\n");
    }
    else
    {
        printf("失败(正常，位置越界)\n");
    }

    // 4. 测试长度
    printf("\n4. 测试链表长度:\n");
    printf("   当前链表长度: %d\n", Length(L));

    // 5. 测试按位查找
    printf("\n5. 测试按位查找:\n");
    for (int i = 1; i <= 4; i++)
    {
        LNode *node = GetElem(L, i);
        if (node != NULL)
        {
            printf("   第%d个元素: %d\n", i, node->data);
        }
        else
        {
            printf("   第%d个元素: 不存在\n", i);
        }
    }

    // 6. 测试按值查找
    printf("\n6. 测试按值查找:\n");
    int searchValues[] = {20, 30, 99};
    for (int i = 0; i < 3; i++)
    {
        LNode *node = LocateElem(L, searchValues[i]);
        if (node != NULL)
        {
            printf("   查找元素%d: 找到\n", searchValues[i]);
        }
        else
        {
            printf("   查找元素%d: 未找到\n", searchValues[i]);
        }
    }

    // 7. 测试后插操作
    printf("\n7. 测试后插操作:\n");
    LNode *p = GetElem(L, 2); // 获取第2个结点
    if (p != NULL)
    {
        printf("   在第2个结点后插入元素25: ");
        if (InsertNextNode(p, 25))
        {
            printf("成功\n");
            PrintList(L);
        }
        else
        {
            printf("失败\n");
        }
    }

    // 8. 测试前插操作
    printf("\n8. 测试前插操作:\n");
    p = GetElem(L, 3); // 获取第3个结点
    if (p != NULL)
    {
        printf("   在第3个结点前插入元素35: ");
        if (InsertPriorNode(p, 35))
        {
            printf("成功\n");
            PrintList(L);
        }
        else
        {
            printf("失败\n");
        }
    }

    // 9. 测试按位删除
    printf("\n9. 测试按位删除:\n");
    printf("   删除第1个元素: ");
    if (ListDelete(L, 1, deleteValue))
    {
        printf("成功，删除的元素是%d\n", deleteValue);
        PrintList(L);
    }
    else
    {
        printf("失败\n");
    }

    printf("   删除第3个元素: ");
    if (ListDelete(L, 3, deleteValue))
    {
        printf("成功，删除的元素是%d\n", deleteValue);
        PrintList(L);
    }
    else
    {
        printf("失败\n");
    }

    // 测试越界删除
    printf("   删除第10个元素(越界测试): ");
    if (ListDelete(L, 10, deleteValue))
    {
        printf("成功\n");
    }
    else
    {
        printf("失败(正常，位置越界)\n");
    }

    // 10. 测试删除指定结点
    printf("\n10. 测试删除指定结点:\n");
    p = GetElem(L, 2); // 获取第2个结点
    if (p != NULL && p->next != NULL)
    { // 确保不是最后一个结点
        printf("    删除第2个结点(值为%d): ", p->data);
        if (DeleteNode(p))
        {
            printf("成功\n");
            PrintList(L);
        }
        else
        {
            printf("失败\n");
        }
    }
    else
    {
        printf("    第2个结点不存在或是最后一个结点，无法使用此方法删除\n");
    }

    // 11. 再次测试空链表判断
    printf("\n11. 当前链表状态:\n");
    printf("    链表长度: %d\n", Length(L));
    if (Empty_head(L))
    {
        printf("    链表为空\n");
    }
    else
    {
        printf("    链表不为空\n");
        PrintList(L);
    }

    // 12. 清空链表测试
    printf("\n12. 清空链表测试:\n");
    while (!Empty_head(L))
    {
        if (ListDelete(L, 1, deleteValue))
        {
            printf("    删除元素: %d\n", deleteValue);
        }
        else
        {
            break;
        }
    }
    printf("    链表清空完成\n");
    if (Empty_head(L))
    {
        printf("    确认：链表为空\n");
    }

    // 13. 释放内存
    printf("\n13. 释放链表内存\n");
    DestroyList(L);
    printf("    内存释放完成\n");

    printf("\n=== 测试完成 ===\n");
    return 0;
}