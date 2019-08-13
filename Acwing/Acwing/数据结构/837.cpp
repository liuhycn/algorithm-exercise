//
//  837.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/8/13.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int N = 100001;

int p[N];
int n, m;
int cnt[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}


int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        cnt[i] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        char op[2];
        scanf("%s", op);
        if (op[0] == 'C')
        {
            int a, b;
            scanf("%d%d", &a, &b);
            if (find(a) == find(b)) continue;
            cnt[find(b)] = cnt[find(a)] + cnt[find(b)];
            p[find(a)] = find(b);
        }
        else if (op[1] == '1')
        {
            int a, b;
            scanf("%d%d", &a, &b);
            if (find(a) == find(b))
                puts("Yes");
            else
                puts("No");
        }
        else if (op[1] == '2')
        {
            int a;
            scanf("%d", &a);
            printf("%d\n", cnt[find(a)]);
        }
    }
    return 0;
}
