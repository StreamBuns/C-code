//
//  main.cpp
//  Cholesky_C++_1
//
//  Created by 赵桐 on 2020/5/31.
//  Copyright © 2020 赵桐. All rights reserved.
//
#include<iostream>
#include<cmath>
#include <iomanip>
#include<sys/time.h>
using namespace std;

const int n = 8;

void Square(double a[n][n], double b[n]);
void Improve_Square(double a[n][n], double b[n]);

int main(int argc, const char * argv[]) {
    // insert code here...
    struct timeval square_begin,square_end;
    double a[n][n] = {1,2,2,4,7,1,8,1,
                      2,3,3,3,3,3,3,2,
                      2,3,4,5,4,4,2,3,
                      4,3,5,6,5,5,4,4,
                      7,3,4,5,6,2,5,6,
                      1,3,4,5,2,3,8,1,
                      8,3,2,4,5,8,2,4,
                      1,2,3,4,6,1,4,3
    };
    double b[n] = {32,45,86,19,31,24,21,43};
    gettimeofday(&square_begin, NULL);
    Improve_Square(a,b);
    gettimeofday(&square_end, NULL);
    cout << "改进平方根法分解此矩阵耗时："<<(long long)(square_end.tv_usec-square_begin.tv_usec)<<"微妙\n";
//    Square(a,b);
    return 0;
}
void Square(double a[n][n], double b[n])
{
    double l[n][n];
    double y[n];
    double x[n];
    int i, j, k;


    for (j = 0; j < n; j++)
    {
        double sum1 = 0;
        for (k = 0; k < j; j++)
        {
            sum1 += l[j][k] * l[j][k];
        }
        l[j][j] = sqrt(a[j][j] - sum1);
        for (i = j + 1; j < n; j++)
        {
            double sum2 = 0;
            for (k = 0; k < j; k++)
            {
                sum2 += l[i][k] * l[j][k];
            }
            if (l[j][j] < 0)
            throw("division is zero,can't do!!");

            l[i][j] = (a[i][j] - sum2)/l[j][j];
        }
    }

    for (i = 0; i < n; i++)
    {
        double sum3 = 0;
        for ( k = 0; k < i; k++)
            sum3 += l[i][k] * y[k];
        y[i] = (b[i] - sum3) / l[i][i];
    }



    for (i = n - 1; i >= 0; --i)
    {
        double sum4 = 0;
        for (k = i + 1; k < n; k++)
            sum4 += l[k][i] * x[k];
        x[i] = (y[i] - sum4) / l[i][i];
    }
    for(i=0;i<n;i++)
        cout << "x[" << i + 1 << "]=" << x[i] << "    " << endl;
}




void Improve_Square(double a[n][n], double b[n])
{
    int i, j, k;
    double t[n][n];
    double d[n];
    double l[n][n];
    
    for (i = 0;i < n; i++)
    {
        double sum1 = 0;
        for (j = 0; j <= i - 1; j++)
        {
            for (k = 0; k <= j - 1; k++)
                sum1 += t[i][k] * l[j][k];
            t[i][j] = a[i][j] - sum1;
            l[i][j] = t[i][j] / d[j];
        }
        double sum2 = 0;
        for (k = 0; k <= i - 1; k++)
            sum2 += t[i][k] * l[i][k];
        d[i] = a[i][i] - sum2;
    }


    double y[n];
    y[0] = b[0];
    for (i = 1; i < n; i++)
    {
        double sum3 = 0;
        for (k = 0; k <= i - 1; k++)
            sum3 += l[i][k] * y[k];
        y[i] = b[i] - sum3;
    }

    double x[n];
    x[n-1] = y[n - 1] / d[n - 1];
    for (i = n - 2; i >= 0; i--)
    {
       double sum4 = 0;
        for (k = i + 1; k < n; k++)
            sum4 += l[k][i] * x[k];
        x[i] = y[i] / d[i] - sum4;
    }
    for(i=0;i<n;i++)
        cout << "x[" << i + 1 << "]=" << x[i] << "    " << endl;
}
