//
//  kruskal.cpp
//  algorithm-exercise
//
//  Created by Hongyan Liu on 2019/4/21.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"


struct point
{
    double x;
    double y;
    double getDistance(point b)
    {
        return sqrt((x-b.x)*(x-b.x)+(y-b.y)*(y-b.y));
    }
}list[101];

struct Edge
{
    int src;
    int dst;
    double cost;
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
}edge[6001];

int set[101];

int findroot(int x)
{
    if(set[x] == -1)
    {
        return x;
    }
    else
    {
        int temp = findroot(set[x]);
        set[x] = temp;
        return temp;
    }
}
void merge(int x,int y)
{
    set[y] = x;
}

int main()
{
    int n;
    pp();
    while (scanf("%d",&n)!=EOF)
    {
        memset(set,-1,sizeof(set));
        for (int i = 1; i <= n; i++)
        {
            scanf("%lf%lf", &list[i].x, &list[i].y);
        }
        int size = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                edge[size].src = i;
                edge[size].dst = j;
                edge[size].cost = list[i].getDistance(list[j]);
                size++;
            }
        }
        sort(edge, edge+size);
        double ans = 0;
        for(int i = 0;i<size;i++)
        {
            int root1 = findroot(edge[i].src);
            int root2 = findroot(edge[i].dst);
            if(root1 == root2)
            {
                continue;
            }
            else
            {
                merge(root1, root2);
                ans = ans + edge[i].cost;
            }
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}
