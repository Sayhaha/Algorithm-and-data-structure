/*//电子钟
#include"iostream"
#include"string.h"
using namespace std;

int main()
{
    int b[5];
    string c;
    while(cin >> b[0] >> b[1] >> b[2] >> b[3])
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<4; j++)
            {
                if(0 == i)
                {
                    if(b[j]==1 || b[j]==4)
                    {
                        c = "   ";
                        cout << c;
                    }
                    else
                    {
                        c = " _ ";
                        cout << c;
                    }
                    if(j==3) cout << endl;
                }
                if(1 == i)
                {
                    if(b[j]==1 || b[j]==7)
                    {
                        c = "  |";
                        cout << c;
                    }
                    else if(b[j]==0)
                    {
                        c = "| |";
                        cout << c;
                    }
                    else if(b[j]==2 || b[j]==3)
                    {
                        c = " _|";
                        cout << c;
                    }
                    else if(b[j]==5 || b[j]==6)
                    {
                        c = "|_ ";
                        cout << c;
                    }
                    else
                    {
                        c = "|_|";
                        cout << c;
                    }
                    if(j==3) cout << endl;
                }
                if(2 == i)
                {
                    if(b[j]==2)
                    {
                        c = "|_ ";
                        cout << c;
                    }
                    else if(b[j]==1 || b[j]==4 || b[j]==7)
                    {
                        c = "  |";
                        cout << c;
                    }
                    else if(b[j]==3 || b[j]==5 || b[j]==9)
                    {
                        c = " _|";
                        cout << c;
                    }
                    else if(b[j]==0 || b[j]==6 || b[j]==8)
                    {
                        c = "|_|";
                        cout << c;
                    }
                    if(j==3) cout << endl;
                }
            }
        }
    }
    return 0;
}*/


//菱形回文数
/*#include"iostream"
using namespace std;

int main()
{
    int n,j,k,i,m=0;
    while(cin >> n){
        for(i=1; i<=n; i++){
            for(j=0; j<n; j++){
                if(j<n-i) {cout << " "; m++;}      //j<abs(n-i)出现了超时
               else cout << j-m+1;
            }
            k = j-m;
            m = 0;
            for(j=k-1; 0<j; j--){
                cout << j;
            }
            cout << endl;
        }
        for(i = i-2; 0<i; i--){
            for(j=0; j<n; j++){
                if(j<n-i) {cout << " "; m++;}
               else cout << j-m+1;
            }
            k = j-m;
            m = 0;
            for(j=k-1; 0<j; j--){
                cout << j;
            }
            cout << endl;
        }
    }
    return 0;
}*/

//放大 X
/*#include"iostream"

using namespace std;

int main()
{
    int t,n,i,k;
    cin >> t;
    while(t--){
        cin >> n;
        k = n/2+1;
        for(i=1; i<=k; i++){
            for(int j=1; j<=n; j++){
                if(j == (2*k-i)) {cout<<"X"<<endl;break;}
                else if(j == i) cout<<"X";
                else cout<<" ";
            }
        }
        i = i-2;
        for( ; 1<=i; i--){
            for(int j=1; j<=n; j++){
                if(j == (2*k-i)) {cout<<"X"<<endl;break;}
                else if(j==i) cout <<"X";
                else cout<<" ";
            }
        }
        cout << endl;
    }
    return 0;
}*/

//对只含有ZOJ的字符串排序
/*#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int length,i,cz,co,cj;

    while(getline(cin,str)){
        if(str == "E")break;

        cz=co=cj=0;
        length = str.length();
        for(i=0;i<length;++i){
            if(str[i]=='Z')++cz;
            else if(str[i]=='O')++co;
            else ++cj;
        }
        while((cz!=0)||(co!=0)||(cj!=0)){
            if(cz!=0){
                cout<<"Z";
                --cz;
            }
            if(co!=0){
                cout<<"O";
                --co;
            }
            if(cj!=0){
                cout<<"J";
                --cj;
            }
        }
        cout<<endl;
    }
    return 0;
}*/

//当总统
/*#include"iostream"
#include"algorithm"
using namespace std;

#define MAX 101


int main()
{
    int n, c=0, sum=0;
    int a[MAX+1];

    while(cin >> n){
        if(0 == n) break;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        sort(a,a+n);
        for(int i=0; i<n; i++){
            sum += a[i]/2+1;
            c++;
            if(c>n/2) break;
        }
        cout << sum << endl;
        sum = 0;
        c = 0;
    }
    return 0;
}*/


//布尔矩阵
/*#include"iostream"
#define R 100
#define D 100
using namespace std;

int main()
{
    int matrix, sum=0, sum1=0;
    int a[R+5][D+5] ={0};
    while(cin >> matrix){
        if(0 == matrix) break;
            for(int i=1; i<=matrix; i++){
                for(int j=1; j<=matrix; j++){
                    cin >> a[i][j];
                    sum += a[i][j];
                }
                if(sum%2 != 0) a[i][matrix+1] = 1;
                sum = 0;
            }
            for(int i=1; i<=matrix; i++){
                for(int j=1; j<=matrix; j++){
                    sum += a[j][i];
                    a[j][i] = 0;
                }
                if(sum%2 != 0) a[matrix+1][i] = 1;
                sum = 0;
            }
            for(int i=1; i<=matrix; i++){
                sum += a[i][matrix+1];
                sum1 += a[matrix+1][i];
            }
            if((0==sum)&&(0==sum1)) cout << "OK" << endl;
            else if((1==sum)&&(1==sum1)){
                for(int i=1; i<=matrix; i++){
                    for(int j=1; j<=matrix; j++){
                        if(a[i][matrix+1]==1 && a[matrix+1][j]==1) cout << "Change bit (" << i << "," << j << ")" << endl;
                    }
                }
            }
            else  cout << "Corrupt" << endl;
            sum = 0;
            sum1 = 0;
            for(int i=1; i<=matrix; i++){
                a[i][matrix+1]=0;
                a[matrix+1][i]=0;
            }
    }
    return 0;
}*/


/*#include"stdio.h"

int main()
{
	int a,b,c,temp;
	int *pa,*pb,*pc;
	pa = &a;
	pb = &b;
	pc = &c;
	scanf("%d%d%d", &a,&b,&c);
	if(*pa < *pb){
        temp = *pa;
        *pa = *pb;
        *pb = temp;
	}
	if(*pa < *pc){
        temp = *pa;
        *pa = *pc;
        *pc = temp;
	}
	if(*pb < *pc){
        temp = *pb;
        *pb = *pc;
        *pc = temp;
	}
	printf("%d %d %d", *pa,*pb,*pc);
	return 0;
}*/


/*#include"iostream"
using namespace std;


typedef struct node{
    int data;
    struct node *next;
}LNode,*LinkList;

int main()
{
    LinkList l=NULL;
    LNode *s,*p;
    s = new LNode();
    l = s;
    p =s;
    s->next = NULL;
    int e;
    while(cin >> e && e){
        s = new LNode();
        s->data = e;
        p->next = s;
        p = s;
        p->next = NULL;
    }
    int i,n=0;
    cin >> i;
    p = l;
    while(p->next){
        p = p->next;
        n++;
        if(i == p->data) break;
    }
    cout << n << endl;
    return 0;
}*/


/*#include"iostream"

using namespace std;

typedef struct node{
    int data;
    struct node *next;
}LNode,*LinkList;

int main()
{
    LinkList h;
    LNode *p, *s;
    s = new LNode();
    h = s;
    p = s;
    p->next = NULL;
    int n = 0, e;
    cin >> n;
    while(n--){
        cin >> e;
        s = new LNode();
        s->data = e;
        p->next = s;
        p = s;
        p->next = NULL;
    }
    int insert_e, flag = 0;
    cin >> insert_e;
    s = new LNode();
    s->data = insert_e;
    s->next = NULL;
    p = h;
    while(p->next){
        if((s->data) < ((p->next)->data)){
            s->next = p->next;
            p->next = s;
            flag = 1;
            break;
        } else p = p->next;
    }
        if(0 == flag){
            p->next = s;
            p = p->next;
            p->next = NULL;
        }
        p = h;
        while(p->next){
            p = p->next;
            cout << p->data << " ";
        }
    return 0;
}*/

//错误票据
/*#include"iostream"
#include"cstdio"
#include"algorithm"
using namespace std;
#define MAXN 10000000
#define SUM 100000


int main()
{
    int N;
    char a[105][MAXN+100];
    int b[SUM+10];
    while(~scanf("%d", &N)){
        cin.ignore();
        int i = 0;
        while(N--){
            cin.getline(a[i],MAXN+100);
            i++;
        }
        int n=0,p=0;
        for(int j=0; j<i; j++){
            int len = 0;
            while(a[j][len] != '\0') len++;
            while(a[j][len-1]==' ') len--;
            for(int k=0; k<len; k++){
                if(a[j][k]>='0' && a[j][k]<='9') n = n*10+(a[j][k]-'0');
                if(a[j][k]==' ' && a[j][k-1!=' ']) { b[p++] = n; n = 0; }
            }
            b[p++] = n;
            n = 0;
        }
        sort(b,b+p);
        for(int j=0; j<p; j++){
            if(b[j]+1<b[j+1]) cout << b[j]+1 << " ";
        }
        for(int j=0; j<p; j++){
            if(b[j]==b[j-1]) cout << b[j] << endl;
        }
    }
    return 0;
}*/



/*#include"iostream"

using namespace std;

typedef struct node
{
    int  id=0;
    string name="";
    char sex[3];
    int age=0;
    struct node *next;
}student,*stu_list;

int main()
{
    int m=0;
    cin >> m;
    while(m--){
        stu_list h;
        student *s,*r;
        s = new student();
        h = s;
        r = s;
        s->next = NULL;
        int n=0;
        cin >> n;
        //if(0 == n) break;
        while(n--){
            s = new student();
            cin >> s->id;
            cin >> s->name;
            cin >> s->sex;
            cin >> s->age;
           // cout << s->id << " " << s->name << " " << s->sex << " " << s->age <<endl;
            r->next = s;
            r = s;
            r->next = NULL;
        }
        r = h;
        int x=0;
        cin >> x;
        while(r->next){
            if(r->next->id == x) {
                cout << r->next->id << " " << r->next->name << " " << r->next->sex << " " << r->next->age <<endl;
                break;
            }
            r = r->next;
        }
    }
    return 0;
}*/



/*#include <iostream>

using namespace std;

void Qsort(int a[], int low, int high)
{
    if(low >= high)
    {
        return;
    }
    int first = low;
    int last = high;
    int key = a[first];//用字表的第一个记录作为枢轴

    while(first < last)
    {
        while(first < last && a[last] >= key)
        {
            --last;
        }

        a[first] = a[last];//将比第一个小的移到低端

        while(first < last && a[first] <= key)
        {
            ++first;
        }

        a[last] = a[first];
//将比第一个大的移到高端
    }
    a[first] = key;    //枢轴记录到位
    Qsort(a, low, first-1);
    Qsort(a, first+1, high);
}
int main()
{
    int a[] = {57, 68, 59, 52, 72, 28, 96, 33, 24};

    Qsort(a, 0, sizeof(a) / sizeof(a[0]) - 1);//这里原文第三个参数要减1否则内存越界

    //cout << sizeof(a) / sizeof(a[0]) << endl;

    for(int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}*/


//TeX中的引号
/*#include"stdio.h"

int main(){
    int q = 1;
    int c;
    while((c = getchar()) != EOF) {
        if(c == '"') {
            printf("%s", q ? "``" : "''");
            q = !q;
        }else  printf("%c", c);
    }
    return 0;
}*/


/*#include<stdio.h>

int main()
{
    int a = 0;
    int b = 0;
    b = sizeof(a);
    printf("%d\n", b);
    return 0;
}*/


/*#include <stdio.h>
void func(int* a)
{
    static int j = -1;
    do
    {
        j +=1;
        a[j] = a[j] + a[j+1];
    }
    while (j < 2);
}

int main( )
{
    int k, a[10] = {1, 2, 3, 4, 5};
    for (k=1; k<3; k++) func(a);
    for (k=0; k<5; k++) printf("%d", a[k]);
    printf("\n");
    return 0;
}*/

#include <stdio.h>

int main()
{
    char x='12';
    printf("%d", x);
    return 0;
}



