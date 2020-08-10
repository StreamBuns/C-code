# include<iostream>
# include<fstream>
# include<cmath>
# include<iomanip>
using namespace std;
double a[10][10]= {1,2,2,4,7,1,8,1,2,3,
                  2,3,3,3,3,3,3,2,4,5,
                  2,3,4,5,4,4,2,3,5,2,
                  4,3,5,6,5,5,4,4,3,5,
                  7,3,4,5,6,2,5,6,7,2,
                  1,3,4,5,2,3,8,1,2,4,
                  8,3,2,4,5,8,2,4,6,5,
                  1,2,3,4,6,1,4,3,1,2,
                  1,2,2,4,7,1,8,1,2,3,
                  2,3,3,3,3,3,3,2,4,5
};
const int N=8;
double b[N+1]= {32,45,86,19,31,24,21,43,123},xx[N+1],yy[N+1];
void printArry(double a[][10])//输出系数矩阵
{
    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=8;j++)
        {
            cout<<setw(3)<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}int main()
{
//     a[10][10]
//     b[N+1]
//    cout<<"【运用平方根算法解对称正定方程组】"<<endl;
//    /*读入系数矩阵*/
//    ifstream in;
//    in.open("data2.txt");
//    if(!in)
//    {
//        cerr<<"file open failed!"<<endl;
//        return 0;
//    }
//    int i=1,j=1;
//    while(i<=N)
//    {
//        in>>a[i][j];
//        j++;
//        if(j>8)
//        {
//            i++;j=1;
//        }
//    }
//    /*读入b[]*/
//    for(int i=1;i<=N;i++)
//        in>>b[i];

    cout<<"系数矩阵："<<endl<<"++++++++++++++++++++++++++"<<endl;
    printArry(a);
    cout<<endl<<endl<<"b："<<endl;
    for(int i=1;i<=N;i++)
        cout<<setw(3)<<b[i]<<" ";
    cout<<endl<<"++++++++++++++++++++++++++";

    //開始计算。A=GG',G存在A的下三角
    for(int k=1;k<=N;k++)
    {
        double s1=0;
        for(int m=1;m<=k-1;m++)
            s1+=pow(a[k][m],2);
        a[k][k]=sqrt(a[k][k]-s1);
        for(int i=k+1;i<=N;i++)
        {
            double s2=0;
            for(int m=1;m<=k-1;m++)
                s2+=a[i][m]*a[k][m];
            a[i][k]=(a[i][k]-s2)/a[k][k];
        }
        //计算y
        double s3=0;
        for(int m=1;m<=k-1;m++)
            s3+=a[k][m]*yy[m];
        yy[k]=(b[k]-s3)/a[k][k];
    }
    //计算x
    xx[N]=yy[N]/a[N][N];
    for(int k=N-1;k>=1;k--)
    {
        double s4=0;
        for(int m=k+1;m<=N;m++)
            s4+=a[m][k]*xx[m];
        xx[k]=(yy[k]-s4)/a[k][k];
    }
    cout<<endl<<"解向量为:"<<endl;
    for(int i=1;i<=N;i++)
        cout<<setw(3)<<xx[i]<<" ";
    cout<<endl;
    return 0;
}
