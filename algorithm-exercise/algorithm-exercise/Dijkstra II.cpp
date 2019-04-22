//
//  Dijkstra II.cpp
//  algorithm-exercise
//
//  Created by Hongyan Liu on 2019/4/22.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

struct node
{
    int no;
    int length;
    int cost;
};

vector<node> edge[1001];

int dist[1001];
int cost[1001];

int visit[1001];

void init(int n)
{
    for(int i = 1;i<=n;i++)
    {
        dist[i] = 123123123;
    }
    for(int i = 1;i<=n;i++)
    {
        cost[i] = 0;
    }
    for(int i = 1;i<=n;i++)
    {
        visit[i] = 0;
    }
    for(int i = 1;i<=n;i++)
    {
        edge[i].clear();
    }
}

int main()
{
    int n,m;
    pp();
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        if(m==0 && n==0) break;
    
        init(n);
        
        for(int i = 0;i < m;i++)
        {
            node x,y;
            int a,b,d,p;
            scanf("%d%d%d%d",&a,&b,&d,&p);
            x.no = a;
            y.no = b;
            x.length = d;
            y.length = d;
            x.cost = p;
            y.cost = p;
            edge[b].push_back(x);
            edge[a].push_back(y);
        }
        int src,dst;
        scanf("%d%d",&src,&dst);
        
        dist[src] = 0;
        visit[src] = 1;
        int newp = src;
        for(int i = 2;i<=n;i++)
        {
            for(int j = 0;j<=edge[newp].size();j++)
            {
                
                if(visit[edge[newp][j].no] == 0 && ((dist[edge[newp][j].no] > (dist[newp] + edge[newp][j].length) || ((dist[edge[newp][j].no] == (dist[newp] + edge[newp][j].length)) && cost[edge[newp][j].no] > (cost[newp] + edge[newp][j].cost)))))
                {
                    dist[edge[newp][j].no] = dist[newp] + edge[newp][j].length;
                    cost[edge[newp][j].no] = cost[newp] + edge[newp][j].cost;
                }
            }
            int min = 123123123;
            for(int j = 1;j <= n; j++)
            {
                if(visit[j] == 0 && dist[j] < min)
                {
                    min = dist[j];
                    newp = j;
                }
            }
            visit[newp] = 1;
        }
        printf("%d %d\n",dist[dst],cost[dst]);
    }
    return 0;
}
