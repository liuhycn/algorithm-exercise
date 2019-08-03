//
//  803.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/7/31.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"


typedef pair<int, int> PII;

PII buf[100001];
bool cmp(PII a, PII b)
{
    return a.first < b.first;
}

int main()
{
    pp();
    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        printf("1");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        int l , r;
        scanf("%d%d", &l, &r);
        buf[i] = {l, r};
    }
    sort(buf, buf + n);
    int l = buf[0].first;
    int r = buf[0].second;
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (buf[i].first > r)
        {
            ans++;
            l = buf[i].first;
            r = buf[i].second;
        }
        else
        {
            if (buf[i].second <= r)
            {
                continue;
            }
            else
            {
                r = buf[i].second;
            }
        }
    }
    printf("%d", ans);
    return 0;
}
