//
//  main.c
//  Catup_C_1
//
//  Created by 赵桐 on 2020/6/2.
//  Copyright © 2020 赵桐. All rights reserved.
//

//#include <stdio.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<sys/time.h>
void Catup(float *u,int n,float x[]);
#define N 10 //矩阵的阶级
int main()
{
    int i;
    struct timeval Catup_begin,Catup_end;
    float y[N];
    float d[N][N+1]={-4,1,0,0,0,0,0,0,0,0,-11,
                     1,-4,1,0,0,0,0,0,0,0,-12,
                     0,1,-4,1,0,0,0,0,0,0,-13,
                     0,0,1,-4,1,0,0,0,0,0,-14,
                     0,0,0,1,-4,1,0,0,0,0,-15,
                     0,0,0,0,1,-4,1,0,0,0,-16,
                     0,0,0,0,0,1,-4,1,0,0,-17,
                     0,0,0,0,0,0,1,-4,1,0,-18,
                     0,0,0,0,0,0,0,1,-4,1,-19,
                     0,0,0,0,0,0,0,0,1,-4,-20};
    gettimeofday(&Catup_begin, NULL);
    Catup(d[0],10,y);
    gettimeofday(&Catup_end, NULL);
    
    printf("追赶法用时：%lld微妙。\n",(long long)(Catup_end.tv_usec-Catup_begin.tv_usec));
    printf("解集为:");
    for(i=0;i<=9;i++)printf("x[%d]=%f\n",i+1,y[i]);
    return 0;
}
//追赶法
void Catup(float *u,int n,float x[])
{
    int i,j;
    float p;

for(i=1;i<=n-1;i++)
    {
        p=*(u+i*(n+1)+i-1)/(*(u+(i-1)*(n+1)+i-1));
        *(u+i*(n+1)+i-1)=0;
        *(u+i*(n+1)+i)-=p*(*(u+(i-1)*(n+1)+i));
        *(u+i*(n+1)+n)-=p*(*(u+(i-1)*(n+1)+n));
    }

    x[n-1]=(*(u+(n-1)*(n+1)+n))/(*(u+(n-1)*(n+1)+n-1));
    for(j=n-2;j>=0;j--)
    {

        x[j]=((*(u+j*(n+1)+n))-x[j+1]*(*(u+j*(n+1)+j+1)))/(*(u+j*(n+1)+j));
    }
}

