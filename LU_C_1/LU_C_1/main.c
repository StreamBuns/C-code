//
//  main.c
//  LU_C_1
//
//  Created by 赵桐 on 2020/6/7.
//  Copyright © 2020 赵桐. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

#define MAX 8

double A[MAX][MAX]= {1,2,3,2,5,2,3,1,
                   5,9,3,4,5,6,7,4,
                   4,4,7,7,8,4,3,1,
                   1,2,4,5,7,8,9,2,
                   1,2,3,8,9,7,1,2,
                   1,2,1,2,4,3,3,8,
                   8,3,6,4,5,8,6,3,
                   1,2,3,1,2,9,8,4
};
double b[MAX]={2,4,6,8,10,14,18,20};
void PLU(void);
void LU(void);

int main(int argc, const char * argv[]) {
// insert code here...
    struct timeval plu_begin,plu_end,lu_begin,lu_end;

    gettimeofday(&lu_begin, NULL);
    LU();
    gettimeofday(&lu_end, NULL);
    printf("LU分解耗时：%lld 毫秒\n",(long long)lu_end.tv_usec-lu_begin.tv_usec);
    
    gettimeofday(&plu_begin, NULL);
    PLU();
    gettimeofday(&plu_end, NULL);
    printf("PLU分解耗时：%lld 毫秒\n",(long long)plu_end.tv_usec-plu_begin.tv_usec);
    return 0;
}

void PLU()
{
    double u[MAX][MAX] = { 0 };
    double l[MAX]={0};
    double X[MAX];
    int i,j,k,column;
    double max,A_temp,b_temp,mik,sum;

    for (i = 0; i<MAX; i++)
    {
        for (j=0; j<MAX; j++)
        {
            u[j][i] = A[j][i];
        }
    }
    for (i = 0; i<MAX; i++)
    {
        l[i]=b[i];
    }

    for(k=0; k<MAX-1; k++)
    {
        column=k;
        max=0;
        for(i=k; i<MAX; i++)
        {
            if(fabs(u[i][k])>max)
            {
                max=fabs(u[i][k]);
                column=i;
            }
        }
        for(j=k; j<MAX; j++)
        {
            A_temp = u[k][j];
            u[k][j] = u[column][j];
            u[column][j] = A_temp;
        }
        b_temp = l[k];
        l[k] = l[column];
        l[column] = b_temp;
        for(i=k+1; i<MAX; i++)//消元过程
        {
            mik = u[i][k]/u[k][k];
            for(j=k; j<MAX; j++)
                u[i][j]-=mik*u[k][j];
            l[i]-= mik*l[k];
        }

    }
    X[MAX-1]=l[MAX-1]/u[MAX-1][MAX-1];
    for(i=MAX-2; i>=0; i--)
    {
        sum = 0;
        for(j=i+1; j<MAX; j++)
            sum+=u[i][j]*X[j];
        X[i]=(l[i]-sum)/u[i][i];
    }
    printf("PLU分解结果X:\n");
    for(i=0; i<MAX; i++)
    {
        printf("x[%d]:%lf\n",i,X[i]);
    }
    return;
}
void LU()
{
    double l[MAX][MAX] = { 0 };
    double u[MAX][MAX] = { 0 };
    int i, r, k;
    
    for (i = 0; i<MAX; i++)
    {
        u[0][i] = A[0][i];
    }
    
    for (i = 1; i<MAX; i++)
    {
        l[i][0] = A[i][0] / u[0][0];
    }

    for (r = 1; r<MAX; r++)
    {
        for (i = r; i <MAX; i++)
        {
            double sum1 = 0;
            for (k = 0; k < r; k++)
            {
                sum1 += l[r][k] * u[k][i];
                //cout << "" << r << "" << sum1 << endl;
            }
            u[r][i] = A[r][i] - sum1;
        }


        if(r!=MAX)
        for(i=r+1;i<MAX;i++)
        {
            double sum2 = 0;
              for (k = 0; k<r; k++)
            {
                  sum2 += l[i][k] * u[k][r];
            }
                l[i][r] = (A[i][r] - sum2) / u[r][r];
        }

    }

    double y[MAX] = { 0 };
    y[0] = b[0];
    for (i = 1; i<MAX; i++)
    {
        double sum3 = 0;
        for (k = 0; k<i; k++)
            sum3 += l[i][k] * y[k];
        y[i] = b[i] - sum3;
    }

    double x[MAX] = { 0 };
    x[MAX - 1] = y[MAX - 1] / u[MAX - 1][MAX - 1];
    for (i = MAX - 2; i >= 0; i--)
    {
        double sum4 = 0;
        for (k = i + 1; k<MAX; k++)
            sum4 += u[i][k] * x[k];
        x[i] = (y[i] - sum4) / u[i][i];
    }
    printf("LU分解结果X:\n");
    for (i = 0; i<MAX; i++)
        {
            printf("x[%d]:%lf\n",i,x[i]);
        }
    return;
}
