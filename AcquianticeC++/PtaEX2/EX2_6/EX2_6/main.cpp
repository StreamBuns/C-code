//
//  main.cpp
//  EX2_6
//
//  Created by 赵桐 on 2019/11/17.
//  Copyright © 2019 赵桐. All rights reserved.
//

#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
    queue<int> q;
    int n;
    cin>>n;

    int a[10002];
    int sum=-1;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i]%2==1)
            sum=i;
    }
    int k=0;
    int u=0;

    for(int i=0; i<n; i++)
    {
        if(a[i]%2==1)
        {
            if(u==0)
            {
                cout<<a[i];
                u=1;
            }
            else
                cout<<" "<<a[i];
            k++;
        }
        else if(a[i]%2==0)
        {
            q.push(a[i]);
        }
        if((k==2&&q.empty()==false)||(i>sum&&q.empty()==false))
        {
            if(sum==-1)
            {
                cout<<q.front();
                sum=-2;
            }
            else
                cout<<" "<<q.front();
            q.pop();
            k=0;
        }
    }
    return 0;
}
