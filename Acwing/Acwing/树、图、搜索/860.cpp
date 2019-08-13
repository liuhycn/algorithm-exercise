//
//  860.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/8/13.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

const int N = 100001;
const int M = 200001;

int n, m;
int h[N], e[M], ne[M], idx;
int color[N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

bool dfs(int x, int c)
{
    if (color[x] == 0)
    {
        color[x] = c;
        for (int i = h[x]; i != -1; i = ne[i])
        {
            if (!dfs(e[i], 3 - c))
                return false;
        }
    }
    
    else if (color[x] == c)
        return true;
    
    else
        return false;
    
    return true;
}

int main()
{
    pp();
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    int flag = 0;
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0 && !dfs(i, 1))
        {
            flag = 1;
            break;
        }
    }
    if (flag) puts("No");
    else puts("Yes");
    
    return 0;
}
