//
//  853.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/8/11.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

const int N = 501;
const int M = 10001;

struct Edge
{
    int a, b, w;
}edge[M];

int n, m, k;
int backup[N], dist[N];


int main()
{
    pp();
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edge[i] = {a, b, c};
    }
    
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < k; i++)
    {
        memcpy(backup, dist, sizeof dist);
        for (int j = 0; j < m; j++)
        {
            int a, b, w;
            a = edge[j].a;
            b = edge[j].b;
            w = edge[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }
    if (dist[n] > 0x3f3f3f3f >> 1)
        printf("impossible\n");
    else
        printf("%d\n", dist[n]);
    return 0;
}
