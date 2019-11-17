//
//  main.cpp
//  EX2_5
//
//  Created by 赵桐 on 2019/11/17.
//  Copyright © 2019 赵桐. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    vector<int> v1,v;
    scanf("%d",&n);
    vector<int>::iterator it;
    while(n--)
    {
        char ch[15];
        scanf("%s",ch);
        string s = ch;
        if(s == "Push")
        {
            int temp;
            scanf("%d",&temp);
            v1.push_back(temp);
            it = lower_bound(v.begin(),v.end(),temp);
            v.insert(it,temp);
        }
        else if(s == "Pop")
        {
            if(v1.size() == 0)
                printf("Invalid\n");
            else
            {
                it = lower_bound(v.begin(),v.end(),v1[v1.size()-1]);
                v.erase(it);
                printf("%d\n",v1[v1.size()-1]);
                v1.pop_back();
            }
        }
        else if(s == "PeekMedian")
        {
            if(v1.size() == 0)
            {
                printf("Invalid\n");
                continue;
            }
            if(v.size() % 2 == 0)
                printf("%d\n",v[v.size()/2-1]);
            else
                printf("%d\n",v[v.size()/2]);
        }
    }
    return 0;
}
