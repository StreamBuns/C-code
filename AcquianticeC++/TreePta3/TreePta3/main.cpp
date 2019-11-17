//
//  main.cpp
//  TreePta3
//
//  Created by 赵桐 on 2019/11/17.
//  Copyright © 2019 赵桐. All rights reserved.
//

#include <iostream>
#include<cstring>
#include<vector>
using namespace std;
const int Inf=1e5+5;
vector<int> vec[Inf];//存关系图
bool vis[Inf];//标记五服以内的亲属
char sex[Inf];//记录性别
bool flag;//标记情侣是否为近亲
void Dfs(int x,int num)//num表示第几代，从0开始
{
    if(num>=4)//超过五代直接退出
        return;
    for(int i=0;i<vec[x].size();i++)
    {
        if(!vis[vec[x][i]])
        {
            vis[vec[x][i]]=1;//标记出现的人
            Dfs(vec[x][i],num+1);
        }
        else
            flag=1;//五服之内出现一样的人
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int t,fa,ma;
        char ch;
        scanf("%d ",&t);
        sex[t]=getchar();
        scanf(" %d %d",&fa,&ma);
        if(fa!=-1) //-1不用保存，避免数据处理不当导致数组越界
        {
            vec[t].push_back(fa);//保存双亲
            sex[fa]='M';//记录父亲性别
        }
        if(ma!=-1)
        {
            vec[t].push_back(ma);
            sex[ma]='F';
        }
    }
    cin>>T;
    while(T--)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        if(sex[x]==sex[y])//同性
            cout<<"Never Mind"<<endl;
        else
        {
            memset(vis,0,sizeof(vis));
            vis[x]=1;
            vis[y]=1;
            flag=0;
            Dfs(x,0);
            Dfs(y,0);
            if(flag)//被标记过说明这两人为近亲
                cout<<"No"<<endl;
            else
                cout<<"Yes"<<endl;
        }
    }
    return 0;
}


