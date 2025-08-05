#include <iostream>
#include <stdlib.h>
#define ElemType int 
typedef struct DNode
{
    ElemType data;
    struct DNode  * prior,*next;
}DNode,*DLinklist;

bool InitDLinklist(DLinklist &L){
    L=(DNode*)malloc(sizeof(DNode));
    if(L==NULL) return false;
    L->prior=NULL;
    L->next=NULL;
    return true;
}

bool Empty(DLinklist &L){
    if(L->next==NULL) 
        return true;
    else
        return false;
}

bool InsertNextDNode(DNode*p,DNode* s){
    if(p==NULL||s==NULL)
        return false;
    s->next=p->next;
    if(p->next!=NULL) //如果p结点后继不为空
        p->next->prior=s;
    s->prior=p;
    p->next=s;
    return true;
}
