#include"stdio.h"
#include"malloc.h"


//���Ա��˳��洢�ṹ
/*#define MAXSIZE 100

typedef struct
{
    int data[MAXSIZE];
    int len;
}SeqList;

//��ʼ��˳���
SeqList *Init_SeqList()
{
    SeqList *L;
    L = (SeqList *)malloc(sizeof(SeqList));
    L->len = -1;
    return L;
}

//��˳����в�������
int Insert_SeqList(SeqList *L, int i, int e)
{
    if(L->len == MAXSIZE-1){
        printf("�������\n");
        return -1;
    }
    if(i<1 || i>L->len+2){
        printf("����λ�ò���\n");
        return -1;
    }
    int j;
    for(j=L->len; j>=i-1; j--){
        L->data[j+1] = L->data[j];
    }
    L->data[i-1] = e;
    L->len++;
    printf("����ɹ�\n");
    return 1;
}

//ɾ��˳����е�����
int Delete_SeqList(SeqList *L, int i)
{
    if(L->len==-1){
        printf("��գ���Ԫ�ؿ���ɾ����\n");
        return -1;
    }
    if(i<1 || i>L->len+1){
        printf("�����ڵ�%d��Ԫ��\n", i);
        return -1;
    }
    for(int j=i; j<L->len+1; j++){
        L->data[j-1] = L->data[j];
    }
    L->len--;
    return 1;
}

//��ֵ����
int Locate_SeqList(SeqList *L, int e)
{
    for(int i=0; i<L->len+1; i++){
        if(L->data[i]==e) return i;
    }
    printf("�������ݷֲ�����\n");
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
    printf("�ձ���Ԫ��\n");
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



//���Ա����ʽ�洢�ṹ
typedef struct node
{
    int data;
    struct node *next;
}LNode,*LinkList;

//������������
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


//˳����������
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


























