//
//  main.cpp
//  Cholesky_C++_2
//
//  Created by 赵桐 on 2020/6/1.
//  Copyright © 2020 赵桐. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cmath>
int k;
const int n=4;
using namespace std;
double q_s1(double array[][n],int i,int j);
double q_s2(double array[][n],int j);
double q_s3(double array[][n],double Y[],int i);
double q_s4(double array[][n],double X[],int i);
int main()
{
   int i,j;
 double a[n][n];
 cout<<"please input a[i][j]:"<<endl;
 for(i=0;i<n;i++)                         //输入a[i][j]
 {
  for(j=0;j<n;j++)
   cin>>a[i][j];
 }
 double b[n];
 cout<<"please input b[i]:"<<'/n';
 for(i=0;i<n;i++)                            //输入b[i]
  cin>>b[i];
 double l[n][n];
 for(j=0;j<n;j++)                    //求l[i]
 {
  for(i=j;i<n;i++)
  {
   if(i==j)
                l[j][j]=sqrt(a[j][j]-q_s2(l,j));
   else
    l[i][j]=(a[i][j]-q_s1(l,i,j))/l[j][j];
  }
 }
 double y[n];
 double x[n];
 for(i=0;i<n;i++)                                        //求y[i]
  y[i]=(b[i]-q_s3(l,y,i))/l[i][i];
 for(i=n-1;i>=0;i--)                            //求x[i]
   x[i]=(y[i]-q_s4(l,x,i))/l[i][i];
 cout<<"x=(";                                           //输出x[i]
 for(i=0;i<n;i++)
 {
  if(i==n-1)
            cout<<x[i];
  else
   cout<<x[i]<<", ";
 }
 cout<<")T"<<endl;
     return 0;
}


double q_s1(double array[][n],int i,int j)           //求l[i][j]中的和
{
 double s1=0;
 for(k=0;k<j;k++)
  s1+=array[i][k]*array[j][k];
 return (s1);
}

 

double q_s2(double array[][n],int j)                      //求l[j][j]中的和
{
 double s2=0;
 for(k=0;k<j;k++)
  s2+=array[j][k]*array[j][k];
 return (s2);
}

 

double q_s3(double array[][n],double Y[],int i)      //求y[i]中的和
{
 double s3=0;
 for(k=0;k<i;k++)
  s3+=array[i][k]*Y[k];
 return (s3);
}

 

double q_s4(double array[][n],double X[],int i)                //求x[i]中的和
{
 double s4=0;
 for(k=i+1;k<n;k++)
  s4+=array[k][i]*X[k];
 return (s4);
}
 
