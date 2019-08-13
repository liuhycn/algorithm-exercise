//
//  836.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/8/13.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include <iostream>

using namespace std;

const int N = 100001;

int n, m;
int p[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}



int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        p[i] = i;
    char op[1];
    for (int i = 0; i < m; i++)
    {
        scanf("%s", op);
        if (*op == 'M')
        {
            int a, b;
            scanf("%d%d", &a, &b);
            p[find(a)] = find(b);
        }
        else
        {
            int a, b;
            scanf("%d%d", &a, &b);
            if (find(a) == find(b))
                puts("Yes");
            else
                puts("No");
        }
    }
    return 0;
}
