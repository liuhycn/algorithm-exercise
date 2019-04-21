//
//  mst.cpp
//  algorithm-exercise
//
//  Created by Hongyan Liu on 2019/4/21.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//
//kruskal算法
#include "Header.h"

struct Edge
{
    int src;
    int dst;
    int cost;
    bool operator < (const Edge &x)const
    {
        bool ans;
        if(cost < x.cost)
        {
            ans = true;
        }
        else
        {
            ans = false;
        }
        return ans;
    }
}edge[6001];                                                    //边数量远多于城市数量

int citys[101];

int findroot(int x)
{
    if(citys[x] == -1)
    {
        return x;
    }
    else
    {
        int temp = findroot(citys[x]);
        citys[x] = temp;
        return temp;
    }
}

void merge(int x, int y)
{
    citys[y] = x;
}

int main()
{
    int n;
    //pp();
    while (scanf("%d",&n)!=EOF)
    {
        if(n == 0) break;
        memset(citys,-1,sizeof(citys));
        for (int i = 0;i<n*(n-1)/2;i++)
        {
            scanf("%d%d%d",&edge[i].src,&edge[i].dst,&edge[i].cost);
        }
        sort(edge, edge + n*(n-1)/2);
        int ans = 0;
        for(int i = 0;i<n*(n-1)/2;i++)
        {
            int root1 = findroot(edge[i].src);
            int root2 = findroot(edge[i].dst);
            if(root1 == root2)
            {
                continue;
            }
            else
            {
                ans = ans + edge[i].cost;
                merge(root1,root2);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
