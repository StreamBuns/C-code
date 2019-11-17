//
//  main.cpp
//  TreePta4
//
//  Created by 赵桐 on 2019/11/17.
//  Copyright © 2019 赵桐. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;
#define maxn 335
int n ;
int lod[maxn];
int mod[maxn];
int cnt = 0;
 
struct node
{
    int l;
    int r;
    int v;
    node (): l(0) , r(0) {}
};
node data[maxn];
 
int dfs(int la[],int mo[], int len)
{
 
    if( len <= 0 )return -1;
    int k = 0;
    for(int i = 0 ; i < len ; ++i) {
        if( la[len-1] == mo[i] ){
            k = i;
            break;
        }
    }
    int rt = cnt++;
    data[rt].v = mo[k];
    data[rt].l = dfs(la,mo,k);
    data[rt].r = dfs(la+k,mo+k+1,len-k-1);
    return rt;
}
 
int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; ++i)
        scanf("%d",&lod[i]);
    for(int i = 0 ; i < n ; ++i)
        scanf("%d",&mod[i]);
    int rt = dfs(lod,mod,n);
 
    queue<int>q;
    q.push(rt);
    bool first = 1;
    while (!q.empty())
    {
        int fr = q.front(); q.pop();
        if (data[fr].l != -1) q.push(data[fr].l);
        if (data[fr].r != -1) q.push(data[fr].r);
        if (first) { first = 0; }
        else printf(" ");
        printf("%d", data[fr].v);
    }
    printf("\n");
}

