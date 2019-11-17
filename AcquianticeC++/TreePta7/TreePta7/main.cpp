//
//  main.cpp
//  TreePta7
//
//  Created by 赵桐 on 2019/11/17.
//  Copyright © 2019 赵桐. All rights reserved.
//

#include <iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<int> v[100010];
int level[100010];
int main()
{
    int i,j,n,m,k,t,root,num;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&m);
        if(m==-1)
            root=i;
        else
            v[m].push_back(i);
    }
    queue<int> q;
    q.push(root);
    level[root]=1;
    num=1;
    while(!q.empty())
    {
       int tmp=q.front();
       q.pop();
       for(i=0;i<v[tmp].size();i++)
       {
           level[v[tmp][i]]=level[tmp]+1;
           if(level[v[tmp][i]]>num)
           {
               num=level[v[tmp][i]];
           }
           q.push(v[tmp][i]);
       }
    }
    printf("%d\n",num);
    int flag=0;
    for(i=1;i<=n;i++)
    {
        if(level[i]==num)
        {
            if(flag==0)
            {
                printf("%d",i);
                flag=1;
            }
            else
            {
                printf(" %d",i);
            }
        }
    }
    return 0;
}


