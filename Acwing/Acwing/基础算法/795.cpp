//
//  795.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/7/29.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int n, m;
int buf[100001] = {0};
int dp[100001] = {0};
int main()
{
    pp();
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &buf[i]);
        dp[i] = dp[i - 1] + buf[i];
    }
    for (int i = 0; i < m; i++)
    {
        int l , r;
        scanf("%d%d", &l, &r);
        printf("%d\n", dp[r] - dp[l - 1]);
    }
    return 0;
}
