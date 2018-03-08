#include"stdio.h"
#include"malloc.h"


//线性表的顺序存储结构
/*#define MAXSIZE 100

typedef struct
{
    int data[MAXSIZE];
    int len;
}SeqList;

//初始化顺序表
SeqList *Init_SeqList()
{
    SeqList *L;
    L = (SeqList *)malloc(sizeof(SeqList));
    L->len = -1;
    return L;
}

//向顺序表中插入数据
int Insert_SeqList(SeqList *L, int i, int e)
{
    if(L->len == MAXSIZE-1){
        printf("表满溢出\n");
        return -1;
    }
    if(i<1 || i>L->len+2){
        printf("插入位置不对\n");
        return -1;
    }
    int j;
    for(j=L->len; j>=i-1; j--){
        L->data[j+1] = L->data[j];
    }
    L->data[i-1] = e;
    L->len++;
    printf("插入成功\n");
    return 1;
}

//删除顺序表中的数据
int Delete_SeqList(SeqList *L, int i)
{
    if(L->len==-1){
        printf("表空，无元素可以删除！\n");
        return -1;
    }
    if(i<1 || i>L->len+1){
        printf("不存在第%d个元素\n", i);
        return -1;
    }
    for(int j=i; j<L->len+1; j++){
        L->data[j-1] = L->data[j];
    }
    L->len--;
    return 1;
}

//按值查找
int Locate_SeqList(SeqList *L, int e)
{
    for(int i=0; i<L->len+1; i++){
        if(L->data[i]==e) return i;
    }
    printf("查找内容分不存在\n");
    return -1;
}

int show_SeqList(SeqList *L)
{
    for(int i=0; i<=L->len; i++){
        if(L->len==i){
            printf("%d\n",L->data[i]);
            return 1;
        }
        printf("%d  ", L->data[i]);
    }
    printf("空表，无元素\n");
    return 0;
}

int main()
{
    SeqList* L = Init_SeqList();
    Insert_SeqList(L,1,0);
    Insert_SeqList(L,1,1);
    Insert_SeqList(L,1,2);
    Insert_SeqList(L,1,90);
    show_SeqList(L);
    Delete_SeqList(L,1);
    show_SeqList(L);
    int j = Locate_SeqList(L,2);
    printf("%d\n", j);
    return 0;
}*/



//线性表的链式存储结构
typedef struct node
{
    int data;
    struct node *next;
}LNode,*LinkList;

//建立逆序单链表
LinkList Creath_LinkList()
{
    LinkList L=NULL;
    LNode *s;
    int e;
    int flag = -1;
    scanf("%d", &e);
    while(e!=flag)
    {
        s=(LNode *)malloc(sizeof(LNode));
        s->data=e;
        s->next=L;
        L=s;
        scanf("%d",&e);
    }
    return L;
}


//顺序建立单链表
LinkList Creath_LinkList()
{
    LinkList L=NULL;
    LNode *s,*q=NULL;
    int e;
    int flag = -1;
    scanf("%d", &e);
    while(e!=flag){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        if(L == NULL) L = s;
        else q->next = s;
        q = s;
        scanf("%d", &e);
    }
    if(q!=NULL) q->next=NULL;
    return L;
}


























