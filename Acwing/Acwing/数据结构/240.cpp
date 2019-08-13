//
//  240.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/8/13.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

const int N = 50001;

int p[N], kind[N];
int n ,k;
int ans;

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    printf("hello\n");
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        kind[i] = 0;
    }
    for (int i = 0; i < k; i++)
    {
        int d, x, y;
        scanf("%d%d%d", &d, &x, &y);
        if (d == 1 && x != y)
        {
            if (x > n || y > n)
            {
                ans++;
                continue;
            }
            if (kind[find(x)] == 0 && kind[find(y)] == 0)
            {
                kind[find(x)] = kind[find(y)];
                p[find(x)] = find(y);
            }
            else if (kind[find(x)] != 0 && kind[find(y)] == 0)
            {
                kind[find(y)] = kind[find(x)];
                p[find(y)] = find(x);
            }
            else if (kind[find(x)] == 0 && kind[find(y)] != 0)
            {
                kind[find(x)] = kind[find(y)];
                p[find(x)] = find(y);
            }
            else
            {
                if (kind[find(x)] != kind[find(y)])
                {
                    cout << i + 1 << endl;
                    ans ++;
                    continue;
                }
            }
        }
        else if (d == 2)
        {
            if (x > n || y > n)
            {
                ans++;
                continue;
            }
            if (kind[find(x)] == 0 && kind[find(y)] == 0)
            {
                kind[find(x)] = 1;
                kind[find(y)] = 2;
            }
            else if (kind[find(x)] != 0 && kind[find(y)] == 0)
            {
                kind[find(y)] = (kind[find(x)] + 1) % 3;
            }
            else if (kind[find(x)] == 0 && kind[find(y)] != 0)
            {
                kind[find(x)] = (kind[find(y)] + 2) % 3;
            }
            else
            {
                if (kind[find(x)] == kind[find(y)])
                {
                    cout << i + 1 << endl;
                    ans ++;
                    continue;
                }
                else
                {
                    if (kind[find(y)] != (kind[find(x)] + 1) % 3)
                    {
                        cout << i + 1 << endl;
                        ans ++;
                        continue;
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
