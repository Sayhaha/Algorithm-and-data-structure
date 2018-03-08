#include"stdio.h"
#include"time.h"
#include"stdlib.h"
#include"windows.h"

#define MAXN 10000

int Partition(int a[], int first, int last)
{
    if(first >= last) return -1;
    int i=first, j=last+1;
    /*int s = first+rand()%(last-first+1);
    int temp=0;
    temp = a[s];
    a[s] = a[first];
    a[first] = temp;*/
    int k = a[first];
    while(1){
        while(a[++i]<k && i<j);
        while(a[--j]>k);
        if(i >= j) break;
        int temp=0;
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    a[first] = a[j];
    a[j] = k;
    return j;
}


int Qsort(int a[], int first, int last)
{
    if(first >= last) return -1;
    int q = Partition(a,first,last);
    Qsort(a,first, q-1);
    Qsort(a,q+1, last);
    return 0;
}

int main()
{
    int i = 0;
    int a[MAXN]={0};
    srand((unsigned)time(NULL));
    for(i=0; i<MAXN; i++)
        a[i] = rand();
   // DWORD start, finish;
    //start = GetTickCount();
    double time=0;
    double counts=0;
    LARGE_INTEGER nFreq;
    LARGE_INTEGER nBeginTime;
    LARGE_INTEGER nEndTime;
    QueryPerformanceFrequency(&nFreq);
    QueryPerformanceCounter(&nBeginTime);//开始计时
    Qsort(a, 0, MAXN-1);
    QueryPerformanceCounter(&nEndTime);//停止计时
    time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
    //finish = GetTickCount();
    for(i=0; i<MAXN; i++)
        printf("%d\t", a[i]);
    printf("\n\n\n%f", time*1000);

    QueryPerformanceCounter(&nBeginTime);//开始计时
    Qsort(a, 0, MAXN-1);
    QueryPerformanceCounter(&nEndTime);//停止计时
    time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
    printf("\n\n\n%f", time*1000);
    //start = GetTickCount();
   // Qsort(a, 0, MAXN-1);
   // finish = GetTickCount();
   // printf("\n\n\n%f", (double)(finish-start));
    //printf("\n\n\n%d", CLOCKS_PER_SEC);
    return 0;
}
