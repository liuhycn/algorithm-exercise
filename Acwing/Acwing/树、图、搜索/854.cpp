//
//  854.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/8/12.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

const int N = 201;
int g[N][N];
int n, m, k;


int main()
{
    pp();
    scanf("%d%d%d", &n, &m, &k);
    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= n; i++)
        g[i][i] = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
    }
    
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    
    for (int i = 0; i < k; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if (g[a][b] > 0x3f3f3f3f >> 1)
            printf("impossible\n");
        else
            printf("%d\n", g[a][b]);
    }
    
    
    return 0;
}
