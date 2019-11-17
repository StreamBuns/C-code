//
//  main.cpp
//  TreePta14
//
//  Created by 赵桐 on 2019/11/17.
//  Copyright © 2019 赵桐. All rights reserved.
//

#include <iostream>
 
using namespace std;
 
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int MAXN=111111;
 
int stree[MAXN<<2];
 
void pushup(int rt)
{
    stree[rt]=stree[rt<<1]+stree[rt<<1|1];
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        stree[rt]=0;
        return;
    }
    int mid=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
 
void update(int c,int c1,int l,int r,int rt)
{
    if(l==r)
    {
        stree[rt]+=c1;
        return;
    }
    int mid=(l+r)>>1;
    if(c<=mid) update(c,c1,lson);
    if(c>mid) update(c,c1,rson);
    pushup(rt);
}
 
int query(int c,int l,int r,int rt)
{
    if(l==r)
    {
        return l;
    }
    int mid=(l+r)>>1;
    int ans=0;
    if(c<=stree[rt<<1]) ans=query(c,lson);
    else  ans=query(c-stree[rt<<1],rson);
    return ans;
}
int num[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    build(1,MAXN,1);
    int cont=0;
    while(n--)
    {
        char str[20];
        scanf("%s",str);
        if(str[1]=='u')
        {
            int k;
            scanf("%d",&k);
            update(k,1,1,MAXN,1);
            num[cont++]=k;
        }
        else if(str[1]=='o')
        {
            if(!cont)
                printf("Invalid\n");
            else
            {
                printf("%d\n",num[cont-1]);
                update(num[cont-1],-1,1,MAXN,1);
                cont--;
            }
        }
        else if(str[1]=='e')
        {
            int num1;
            if(cont&1)
                num1=(cont+1)/2;
            else num1=cont/2;
            if(!num1)
                printf("Invalid\n");
            else
            {
                int ans=query(num1,1,MAXN,1);
                if(!ans) printf("Invalid\n");
                else printf("%d\n",ans);
            }
        }
    }
    return 0;
}


