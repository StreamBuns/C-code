//
//  main.cpp
//  LU_C++_2
//
//  Created by 赵桐 on 2020/5/31.
//  Copyright © 2020 赵桐. All rights reserved.
//

#include<iostream>
#include <sys/time.h>

using namespace std;

const int n = 8;
//矩阵的ALU分解
void ALU(double a[n][n], double b[n]);

int main(int argc, const char * argv[]) {
    // insert code here...
    double a[n][n] = { 1,2,3,2,5,2,3,1,
                       5,9,3,4,5,6,7,4,
                       4,4,7,7,8,4,3,1,
                       1,2,4,5,7,8,9,2,
                       1,2,3,8,9,7,1,2,
                       1,2,1,2,4,3,3,8,
                       8,3,6,4,5,8,6,3,
                       1,2,3,1,2,9,8,4
    };
    double b[n] = { 2,4,6,8,10,14,18,20 };
    struct timeval alu_begin,alu_end;
    
    gettimeofday(&alu_begin, NULL);
    ALU(a, b);
    gettimeofday(&alu_end, NULL);
    
    cout << "LU分解此矩阵耗时："<<(long long)(alu_end.tv_usec-alu_begin.tv_usec)<<"微妙\n";
    return 0;
}
void ALU(double a[n][n], double b[n])
{
    double l[n][n] = { 0 };
    double u[n][n] = { 0 };
    int i, r, k;
    
    for (i = 0; i<n; i++)
    {
        u[0][i] = a[0][i];
    }
    
    for (i = 1; i<n; i++)
    {
        l[i][0] = a[i][0] / u[0][0];
    }

    for (r = 1; r<n; r++)
    {
        for (i = r; i <n; i++)
        {
            double sum1 = 0;
            for (k = 0; k < r; k++)
            {
                sum1 += l[r][k] * u[k][i];
                //cout << "" << r << "" << sum1 << endl;
            }
            u[r][i] = a[r][i] - sum1;
        }


        if(r!=n)
        for(i=r+1;i<n;i++)
        {
            double sum2 = 0;
              for (k = 0; k<r; k++)
            {
                  sum2 += l[i][k] * u[k][r];
            }
                l[i][r] = (a[i][r] - sum2) / u[r][r];
        }

    }

    double y[n] = { 0 };
    y[0] = b[0];
    for (i = 1; i<n; i++)
    {
        double sum3 = 0;
        for (k = 0; k<i; k++)
            sum3 += l[i][k] * y[k];
        y[i] = b[i] - sum3;
    }

    double x[n] = { 0 };
    x[n - 1] = y[n - 1] / u[n - 1][n - 1];
    for (i = n - 2; i >= 0; i--)
    {
        double sum4 = 0;
        for (k = i + 1; k<n; k++)
            sum4 += u[i][k] * x[k];
        x[i] = (y[i] - sum4) / u[i][i];
    }
    for (i = 0; i<n; i++)
        cout << "x[" << i + 1 << "]=" << x[i] << endl;
    return;
}
