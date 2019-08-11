//
//  849.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/8/11.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

const int N = 501;
int g[N][N];
int visit[N];
int n, m;
int dist[N];

int main()
{
    pp();
    memset(dist, 0x3f, sizeof(dist));
    memset(g, 0x3f, sizeof(g));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        g[i][i] = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
    }
    dist[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        // 确定一个点
        int cur;
        int d = 1e9;
        for (int j = 1; j <= n; j++)
        {
            if (visit[j] == 0 && dist[j] < d)
            {
                cur = j;
                d = dist[j];
            }
        }
        // 加入 S 集合
        visit[cur] = 1;
        
        // 更新其他点
        for (int j = 1; j <= n; j++)
        {
            if (visit[j] == 0 && dist[cur] + g[cur][j] < dist[j])
                dist[j] = dist[cur] + g[cur][j];
        }
    }
    if (dist[n] == 0x3f3f3f3f)
        printf("-1\n");
    else
        printf("%d\n", dist[n]);
    return 0;
}
