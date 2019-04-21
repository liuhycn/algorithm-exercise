//
//  Dijkstra.cpp
//  algorithm-exercise
//
//  Created by Hongyan Liu on 2019/4/21.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"


int main()
{
    int n,m;
    //pp();
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        if(m == 0 && n == 0)
        {
            break;
        }
        int a[101][101];
        int pre[101] = {0};
        int visit[101] = {0};
        int dist[101] = {0};
        for(int i = 1;i<=n;i++)
        {
            dist[i] = 123123123;
        }
        for(int i = 1;i<=n;i++)
        {
            for(int j =1;j<=n;j++)
            {
                if(i == j)
                {
                    a[i][j] = 0;
                }
                else
                {
                    a[i][j] = 123123123;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            int x,y,cost;
            scanf("%d%d%d",&x,&y,&cost);
            a[x][y] = cost;
            a[y][x] = cost;
        }
        dist[1] = 0;
        visit[1] = 1;
        int nowp = 1;
        for(int i = 0; i<n-1;i++)                           //还剩n-1个节点没有加入visit集合
        {
            for(int j = 2;j<=n;j++)                         //用nowp去扩展
            {
                if( (dist[nowp] + a[nowp][j]) < dist[j] && visit[j] == 0)
                {
                    pre[j] = nowp;
                    dist[j] = dist[nowp] + a[nowp][j];
                }
            }
            int min = 123123123;
            for(int j = 2;j <=n;j++)
            {
                if(dist[j] < min && visit[j] == 0)
                {
                    min = dist[j];
                    nowp = j;
                }
            }
            visit[nowp] = 1;
        }
        printf("%d\n",dist[n]);
    }
    return 0;
}
