#include"stdio.h"
#include"time.h"
#include"windows.h"     //引入windows计时函数的头文件

#define MAXN 10000     //定义10000个待测数据

void Merge(int c[], int d[], int f, int m, int r) //归并排序的合并处理，合并c[f:m],c[m+1:r]到d[f:r]
{
    int i = f, j = m + 1, k = f;
    while((i <= m) && (j <= r)){
        if(c[i] <= c[j])
            d[k++] = c[i++];
        else  d[k++] = c[j++];
    }
    if(i > m){
        for(int q = j; q <= r; q++){
            d[k++] = c[q];
        }
    }else {
        for(int q = i; q <= m; q++){
            d[k++] = c[q];
        }
    }
}

void MergePass(int x[], int y[], int s) //合并排好序的相邻数组段
{
    int i = 0;
    while(i <= MAXN - 2 * s){
        Merge(x, y, i, i+s-1, i+2*s-1);
        i = i + 2 * s;
    }
    if((i + s) < MAXN)
        Merge(x, y, i, i + s - 1, MAXN - 1);
    else
        for(int j = i; j < MAXN; j++)
        y[j] = x[j];
}

void MergeSort(int a[]) //归并排序
{
    int s = 1;
    int b[MAXN] = {0};
    while(s < MAXN){
        MergePass(a, b, s);
        s += s;
        MergePass(b, a, s);
        s += s;
    }
}


int Partition(int a[], int first, int last)  //确定基准对数组进行划分
{
    if(first >= last) return -1;
    int i = first, j = last + 1;
    /*int s = first+rand()%(last-first+1);  //取随机的划分基准
    int temp=0;
    temp = a[s];
    a[s] = a[first];
    a[first] = temp;*/
    int k = a[first];    //取第一个元素作为划分基准
    while(1){
        while(a[++i] < k && i < j);
        while(a[--j] > k);
        if(i >= j) break;
        int t = 0;   //数据交换的中间变量t
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    a[first] = a[j];
    a[j] = k;
    return j;    //返回划分基准的位置
}


int QSort(int a[], int first, int last)
{
    if(first >= last) return -1;
    int q = Partition(a, first, last);
    QSort(a, first, q - 1);
    QSort(a, q + 1, last);
    return 0;
}

int main(){
    int a[MAXN] = {0};   //数组a存放用于归并排序的元素
    int b[MAXN] = {0};   //数组b存放用于快速排序的元素
    srand((unsigned)time(NULL));
    for(int i = 0; i < MAXN; i++)
        a[i] = rand();
    for(int i = 0; i < MAXN; i++)
        b[i] = a[i];

    double time = 0;    //用于计时
    double counts = 0;
    LARGE_INTEGER nFreq;
    LARGE_INTEGER nBeginTime;
    LARGE_INTEGER nEndTime;
    QueryPerformanceFrequency(&nFreq);
    QueryPerformanceCounter(&nBeginTime); //开始计时
    MergeSort(a);                       //用归并排序对无序数组排序
    QueryPerformanceCounter(&nEndTime); //停止计时
    time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
    for (int i = 0; i < MAXN; i++)
        printf("%d\t", a[i]);
    printf("\n\n\n%f", time * 1000);    //输出时间的单位为毫秒

    QueryPerformanceCounter(&nBeginTime);//开始计时
    MergeSort(a);                       //用归并排序对有序数组排序
    QueryPerformanceCounter(&nEndTime);//停止计时
    time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
    printf("\n\n\n%f", time*1000);


    QueryPerformanceCounter(&nBeginTime);//开始计时
    QSort(b, 0, MAXN-1);               //用快速排序对无序数组排序
    QueryPerformanceCounter(&nEndTime);//停止计时
    time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
    printf("\n\n\n%f", time * 1000);

    QueryPerformanceCounter(&nBeginTime);//开始计时
    QSort(b, 0, MAXN - 1);            //用快速排序对有序数组排序
    QueryPerformanceCounter(&nEndTime);//停止计时
    time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart) / (double)nFreq.QuadPart;
    printf("\n\n\n%f", time * 1000);
    return 0;
}
