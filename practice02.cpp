/*#include"stdio.h"
#include"math.h"
int main()
{
    for(int a = 1; a <= 9; a++){
        for(int b = 0; b <= 9; b++){
            int n = a*1100 + b*11;
            int m = floor(sqrt(n) + 0.5);
            if(m*m == n) printf("%d\n", n);
        }
    }
    return 0;
}*/


/*#include"stdio.h"

int main()
{
    long long n, t = 0;
    scanf("%lld", &n);
    while(1){
        if(n == 1) break;
        if(n%2 != 0) n = 3*n +1;
        else n = n/2;
        t++;
    }
    printf("%lld\n", t);
    return 0;
}*/

// 水仙花数
/*#include"stdio.h"

int main()
{
    int a, b, c;
    for(int n = 100; n <= 999; n++){
        a = n % 10;
        b = (n /10) % 10;
        c = n / 100;
        if(n == a*a*a + b*b*b + c*c*c)
             printf("%d \n", n);
    }
    return 0;
}*/

//韩信点兵
/*#include"stdio.h"

int main()
{
    int x, y, z;
    int i=0, flag=0;
    while(~scanf("%d %d %d", &x, &y, &z))
    {
        i++;
        for(int n = 10; n <= 100; n++){
           if((n - x) % 3 == 0 && (n - y) % 5 == 0 && (n - z) % 7 == 0){
                printf("Case %d: %d\n", i, n);
                flag = 1;
           }
        }
        if(flag == 0) printf("Case %d: No answer", i);
        flag = 0;
    }
    return 0;
}*/


//倒三角形
/*#include"stdio.h"

int main()
{
    int n;
    while(~scanf("%d", &n)){
        int t = n;
        for( ; n > 0; n--){
           for(int j = n ; t - j >0; j++)
            printf(" ");
           for(int i = 1; i <= (2 * n - 1); i++){
               printf("#");
           }
           printf("\n");
        }
    }
    return 0;
}*/


//开灯问题
/*#include"stdio.h"
#include<string.h>
#define maxn 1010

int a[maxn]={0};
int main()
{
    int n, k, first;
    while(~scanf("%d %d", &n, &k)){
        first = 1;
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= k; i++)
        for(int j = 1; j <= n; j++)
            if(j % i == 0) a[j] = !a[j];
        for(int i = 1; i <= n; i++){
            if(a[i]){
                if(first) first = 0;
                else printf(" ");
                printf("%d", i);
            }
        }
    }
    return 0;
}*/

//蛇形填数
/*#include<stdio.h>
#include<string.h>
#define maxn 20
int a[maxn][maxn];

int main()
{
    int x = 0, y, n, tot = 1;
    memset(a, 0, sizeof(a));
    scanf("%d", &n);
    a[x][y=n-1] = 1;
    while(tot < n*n){
        while(x + 1 < n && !a[x+1][y]) a[++x][y] = ++tot;
        while(y - 1 >= 0 && !a[x][y-1]) a[x][--y] = ++tot;
        while(x - 1 >= 0 && !a[x-1][y]) a[--x][y] = ++tot;
        while(y + 1 < n && !a[x][y+1]) a[x][++y] = ++tot;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            printf("%4d", a[i][j]);
        printf("\n");
    }
    return 0;
}*/


//TeX中的引导
/*#include"stdio.h"

int main()
{
    char c;
    int flag = 1;
    while(~(c = getchar())){
        if(c == '"') { printf("%s", flag? "‘‘" : "''"); flag = !flag;}
        else printf("%c", c);
    }
    return 0;
}*/


//回文词
/*#include"stdio.h"
#include"string.h"

int main()
{
    char s[100] = {0}, s1[100] = {0};
    int t;
    while(~scanf("%s", s)){
        t = strlen(s);
        for(int i = 1; i <= t; i++){
            s1[i-1] = s[t-i];
        }
        if(strcmp(s, s1) == 0) printf("%s -- is a regular palindrome.\n", s);
        else printf("%s -- is not a regular palindrome.\n", s);
    }
    return 0;
}*/


//生成元
/*#include"stdio.h"
#include"string.h"
#include"stdlib.h"
int main()
{
    int a[10] = {0}, sum = 0, n;
    char b[10] = {0};
    while(~scanf("%d", &n)){
        int flag = 0;
        itoa(n, b, 10);
        int t = strlen(b);
        for(int i = n-45; i < n; i++){
            a[9] = i;
        for(int j = 0; j < t; j++){
            a[j] = i % 10;
            i = i / 10;
            sum += a[j];
        }
        i = a[9];

        if(i + sum == n) { printf("%d\n", i); flag = 1; break;}
        sum = 0;
        }
        if(flag == 0) printf("0\n");
    }
    return 0;
}*/

//环状序列
/*#include"stdio.h"
#include"string.h"
#define maxn 105
char a[maxn];
char b[maxn];
int main()
{
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    while(~scanf("%s", a)){
        int t = 0;
        int tt = strlen(a);
        for(int i = 0; i < 4; i++)
        for(int j = 0; j < tt; j++){
            if(i == 0) { if(a[j] == 'A') b[t++] = a[j]; }
            if(i == 1) { if(a[j] == 'C') b[t++] = a[j]; }
            if(i == 2) { if(a[j] == 'G') b[t++] = a[j]; }
            if(i == 3) { if(a[j] == 'T') b[t++] = a[j]; }
           // j = t;
        }
        printf("%s\n", b);
    }
    return 0;
}*/


//得分
/*#include<stdio.h>
#include<string.h>
#define maxn 85
char a[maxn];
int main()
{
    memset(a, 0, sizeof(a));
    while(~scanf("%s", a)){
        int t = 0, sum = 0;
        int m = strlen(a);
        int i = 0;
        while(i < m){
            if(a[i] == 'O')
            for(int j = i; j < m; j++){
                if(a[j] == 'X') { t = 0; break; }
                t++;
                sum += t;
                i = j;
            }
            i++;
        }
        printf("%d\n", sum);
    }
    return 0;
}*/


//数数字
/*#include<stdio.h>
#include<string.h>
#define maxn 10010
char a[maxn];
int main()
{
    memset(a, 0, sizeof(a));
    while(~scanf("%s", a)){
        int t = strlen(a);
        int b[15]={0};
        for(int i = 0; i < t; i++){
            if(a[i] == '0') b[0] += 1;
            if(a[i] == '1') b[1] += 1;
            if(a[i] == '2') b[2] += 1;
            if(a[i] == '3') b[3] += 1;
            if(a[i] == '4') b[4] += 1;
            if(a[i] == '5') b[5] += 1;
            if(a[i] == '6') b[6] += 1;
            if(a[i] == '7') b[7] += 1;
            if(a[i] == '8') b[8] += 1;
            if(a[i] == '9') b[9] += 1;
        }
        for(int j = 0; j < 10; j++)
            printf("%d\n", b[j]);
    }
    return 0;
}*/


/*//周期串
#include<stdio.h>
#include<string.h>
int main()
{
    char a[85] = {0};
    while(~scanf("%s", a))
    {
        int t = strlen(a);
        int k = 2, i, flag = 0;
        for(i =0; i < t; i++)
        {
            if(a[i] == a[0])
                for(int j = i+1; j < k*i; )
                {
                    if(k == 2 && j == t) break;
                    if(j == t ) { flag = 1; goto loop; }
                    if(a[j] == a[j%i]) { j++; if(j == k*i) k++; continue; }
                    else break;
                }
                k = 2;
        }
        if(flag == 0) printf("非周期串\n");
        else loop: printf("周期为：%d\n", i);
    }
    return 0;
}*/



//判断素数
/*#include<math.h>
int main()
{
    int n, flag;
    while(~scanf("%d", &n)){
        if(n <= 1) return 0;
        flag = 0;
        for(int i = 2; i <= sqrt(n); i++)
            if(n % i == 0) { flag = 1; printf("It is not a prime.\n"); }
        if(flag == 0 || n == 1) printf("It is a prime.\n");
    }
    return 0;
}*/


//发放救济金(未完成)
/*#include<stdio.h>
#define maxn 25
int a[maxn];
int main()
{
    int n, k, m;
    while(~scanf("%d%d%d", &n, &k, &m))
    {
        int A = 0, B = n+1;
        for(int i = 1; i <= n; i++)  a[i] = i;
        while(1)
        {
            int t = 0;
            for(int i = 1; i <= n; i++)
            {
                if(a[i])
                {
                    t++;
                    a[t] = a[i];
                }
            }
            if(t == 0) break;
            for(int i = 1; i <= t; i++)
            {
                if(k%t == i)
                {
                    A = i;
                }
                if((t - m%t + 1) == i)
                {
                    B = i;
                }
                if(A == i && A == B) printf("%3d", a[A]);
                else if(A == i) {printf("%3d", a[A]); a[i] = 0;}
                if(B == i) {printf("%3d\n", a[B]); a[i] = 0;}
            }
        }
    }
    return 0;
}*/


/*#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 10+5;
int a[maxn];
int main()
{
    long long a, b;
    while(cin >> a >> b){
        cout << min(a,b) << endl;
    }
    return 0;
}*/

//最大波动数
/*#include<stdio.h>
#include<math.h>
#define maxn 1005
int a[maxn];
int main()
{

    int n,flag = 0;
    while(~scanf("%d", &n)){
        scanf("%d", &a[0]);
        for(int i = 1; i < n; i++){
            scanf("%d", &a[i]);
            flag=fabs(a[i]-a[i-1])>flag?fabs(a[i]-a[i-1]):flag ;
        }
        printf("%d\n", flag);
    }
    return 0;
}*/


