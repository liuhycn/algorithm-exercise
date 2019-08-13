//
//  861.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/8/13.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

const int N = 1001;
const int M = 100001;

int h[N], ne[M], e[M], idx;
int n1, n2, m;
int match[N];
int visit[N];

bool find(int x)
{
    for (int i = h[x]; i != -1; i = ne[i])
    {
        
        int j = e[i];
        if (!visit[j])
        {
            visit[j] = 1;
            if (match[j] == 0)
            {
                match[j] = x;
                return true;
            }
            else
            {
                int pre = match[j];
                match[j] = x;
                if (find(pre))
                    return true;
                else
                    match[j] = pre;
                
            }
        }
        
    }
    return false;
}


void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

int main()
{
    pp();
    scanf("%d%d%d", &n1, &n2, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b + n1);
        add(b + n1, a);
    }
    
    int ans = 0;
    for (int i = 1; i <= n1; i++)
    {
        memset(visit, 0, sizeof visit);
        if (find(i))
            ans ++;
    }
    printf("%d\n", ans);
    
    return 0;
}
