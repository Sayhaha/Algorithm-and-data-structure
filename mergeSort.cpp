#include"stdio.h"
#include"time.h"
#include"windows.h"     //����windows��ʱ������ͷ�ļ�

#define MAXN 10000     //����10000����������

void Merge(int c[], int d[], int f, int m, int r) //�鲢����ĺϲ������ϲ�c[f:m],c[m+1:r]��d[f:r]
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

void MergePass(int x[], int y[], int s) //�ϲ��ź�������������
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

void MergeSort(int a[]) //�鲢����
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


int Partition(int a[], int first, int last)  //ȷ����׼��������л���
{
    if(first >= last) return -1;
    int i = first, j = last + 1;
    /*int s = first+rand()%(last-first+1);  //ȡ����Ļ��ֻ�׼
    int temp=0;
    temp = a[s];
    a[s] = a[first];
    a[first] = temp;*/
    int k = a[first];    //ȡ��һ��Ԫ����Ϊ���ֻ�׼
    while(1){
        while(a[++i] < k && i < j);
        while(a[--j] > k);
        if(i >= j) break;
        int t = 0;   //���ݽ������м����t
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    a[first] = a[j];
    a[j] = k;
    return j;    //���ػ��ֻ�׼��λ��
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
    int a[MAXN] = {0};   //����a������ڹ鲢�����Ԫ��
    int b[MAXN] = {0};   //����b������ڿ��������Ԫ��
    srand((unsigned)time(NULL));
    for(int i = 0; i < MAXN; i++)
        a[i] = rand();
    for(int i = 0; i < MAXN; i++)
        b[i] = a[i];

    double time = 0;    //���ڼ�ʱ
    double counts = 0;
    LARGE_INTEGER nFreq;
    LARGE_INTEGER nBeginTime;
    LARGE_INTEGER nEndTime;
    QueryPerformanceFrequency(&nFreq);
    QueryPerformanceCounter(&nBeginTime); //��ʼ��ʱ
    MergeSort(a);                       //�ù鲢�����������������
    QueryPerformanceCounter(&nEndTime); //ֹͣ��ʱ
    time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
    for (int i = 0; i < MAXN; i++)
        printf("%d\t", a[i]);
    printf("\n\n\n%f", time * 1000);    //���ʱ��ĵ�λΪ����

    QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ
    MergeSort(a);                       //�ù鲢�����������������
    QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ
    time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
    printf("\n\n\n%f", time*1000);


    QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ
    QSort(b, 0, MAXN-1);               //�ÿ��������������������
    QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ
    time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
    printf("\n\n\n%f", time * 1000);

    QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ
    QSort(b, 0, MAXN - 1);            //�ÿ��������������������
    QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ
    time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart) / (double)nFreq.QuadPart;
    printf("\n\n\n%f", time * 1000);
    return 0;
}
