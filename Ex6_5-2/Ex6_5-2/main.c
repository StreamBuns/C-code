//
//  main.c
//  Ex6_5-2
//
//  Created by 赵桐 on 2020/5/29.
//  Copyright © 2020 赵桐. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
void bubbleSort (int arr[], int len);
void select_sort(int arr[],int len);
int intcmp(const void *v1, const void *v2);
int main(int argc, const char * argv[]) {
    // insert code here...
    struct timeval bs_begin,bs_end,ses_begin,ses_end,qs_begin,qs_end;
    srand(1);
    int arr1[50000],arr2[50000],arr3[50000],i;
    for(i=0;i<50000;i++)
    {
        arr1[i]=arr2[i]=arr3[i]=rand();
    }
    
    gettimeofday(&bs_begin, NULL);
    bubbleSort(arr1, 50000);
    gettimeofday(&bs_end, NULL);
    
    gettimeofday(&ses_begin, NULL);
    select_sort(arr2, 50000);
    gettimeofday(&ses_end, NULL);
    
    gettimeofday(&qs_begin, NULL);
    qsort(arr3, 50000, sizeof(arr3[0]), intcmp);
    gettimeofday(&qs_end, NULL);
    
    
    printf("冒泡排序的耗时:%ld微秒\n",bs_end.tv_usec-bs_begin.tv_usec);
    printf("选择排序的耗时:%ld微秒\n",ses_end.tv_usec-ses_begin.tv_usec);
    printf("快速排序的耗时:%ld微秒\n",qs_end.tv_usec-qs_begin.tv_usec);
        
    return 0;
}
void bubbleSort (int arr[], int len) {
    int temp;
    int i, j;
    for (i=0; i<len-1; i++) /* 外循环为排序趟数，len个数进行len-1趟 */
        for (j=0; j<len-1-i; j++) { /* 内循环为每趟比较的次数，第i趟比较len-i次 */
            if (arr[j] > arr[j+1]) { /* 相邻元素比较，若逆序则交换（升序为左大于右，降序反之） */
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
}
void select_sort(int arr[],int len)
 
{
 
    register int i,j,min,t;
 
    for(i=0;i<len-1;i++)
 
    {
 
        min=i;//查找最小值
 
        for(j=i+1;j<len;j++)
 
            if(arr[min]>arr[j])
 
                min=j;//交换
 
        if(min!=i)
 
        {
 
            t=arr[min];
 
            arr[min]=arr[i];
 
            arr[i]=t;
 
        }
 
    }
 
}

int intcmp(const void *v1, const void *v2)
{
  return (*(int *)v1 - *(int *)v2);
}
