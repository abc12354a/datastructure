/**
 * 冒泡排序：C 语言
 *
 * @author skywang
 * @date 2014/03/11
 */
#include <stdlib.h>
#include <stdio.h>
#include<time.h>
// 数组长度
#define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )
// 交互数值
#define swap(a,b)    (a^=b,b^=a,a^=b)
#define CLK_TCK 1000
/*
 * 冒泡排序
 *
 * 参数说明：
 *     a -- 待排序的数组
 *     n -- 数组的长度
 */
void bubble_sort1(int a[], int n)
{
    int i,j;

    for (i=n-1; i>0; i--)
    {
        // 将a[0...i]中最大的数据放在末尾
        for (j=0; j<i; j++)
        {
            if (a[j] > a[j+1])
                swap(a[j], a[j+1]);
        }
    }
}

/*
 * 冒泡排序(改进版)
 *
 * 参数说明：
 *     a -- 待排序的数组
 *     n -- 数组的长度
 */
void bubble_sort2(int a[], int n)
{
    int i,j;
    int flag;                 // 标记

    for (i=n-1; i>0; i--)
    {
        flag = 0;            // 初始化标记为0

        // 将a[0...i]中最大的数据放在末尾
        for (j=0; j<i; j++)
        {
            if (a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
                flag = 1;    // 若发生交换，则设标记为1
            }
        }

        if (flag==0)
            break;            // 若没发生交换，则说明数列已有序。
    }
}
int main()
{
    clock_t start,end;  
    srand(time(NULL));
    int *d;
    int n,m,i,c,b,t;
    n = 10000;
    m = 10000;
    d=(int *)malloc((n+1)*sizeof(int));
    if (NULL==d) return 1;
    for (i=0;i<=n;i++) d[i]=i;/* 填写0～n */
    for (i=n+1;i>0;i--) {/* 打乱0～n */
        c=i-1;b=rand()%i;
        if (c!=b) {t=d[c];d[c]=d[b];d[b]=t;}
    }
    //…calculating…     
    int ilen = LENGTH(d);
    printf("%d\n",m);
    printf("before sort:");
    for (i=0; i<m; i++)
        printf("%d ", d[i]);
    printf("\n");
    start = clock();  
    bubble_sort1(d, m);
    //bubble_sort2(a, ilen);
    end = clock();  
    printf("after  sort:");
    for (i=0; i<m; i++)
        printf("%d ", d[i]);
    printf("\n");
    printf("time=%f\n",((double)end-start/1000));  
    printf("\n");
    free(d);
    return 0;
}
