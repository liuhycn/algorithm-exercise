//
//  858.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/8/12.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

const int N = 501;

int g[N][N];
int dist[N];
int visit[N];

int n, m;
int ans;
int flag;

int main()
{
    pp();
    scanf("%d%d", &n, &m);
    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= n; i++)
        g[i][i] = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
        g[b][a] = g[a][b];
    }
    memset(dist, 0x3f, sizeof dist);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            dist[1] = 0;
            visit[1] = 1;
            for (int j = 2; j <= n; j++)
            {
                if (visit[j] == 0 && dist[j] > g[j][1])
                    dist[j] = g[j][1];
            }
        }
        else
        {
            int min = 0x3f3f3f3f, cur = -1;
            for (int j = 2; j <= n; j++)
            {
                if (dist[j] < min && visit[j] == 0)
                {
                    cur = j;
                    min = dist[j];
                }
            }
            if (cur == -1)
            {
                flag = 1;
                break;
            }
            dist[cur] = 0;
            visit[cur] = 1;
            ans += min;
            for (int j = 2; j <= n; j++)
            {
                if (dist[j] > g[cur][j] && visit[j] == 0)
                    dist[j] = g[cur][j];
            }
        }
    }
    if (flag) puts("impossible");
    else printf("%d\n", ans);
}
