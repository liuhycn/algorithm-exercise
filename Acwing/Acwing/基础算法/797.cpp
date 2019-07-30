//
//  797.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/7/29.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int nums[100001] = {0};
int dp[100001] = {0};

int main()
{
    pp();
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &nums[i]);
        dp[i] = nums[i] - nums[i - 1];
    }
    for (int i = 0; i < m; i++)
    {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        dp[l] += c;
        dp[r + 1] -= c;
    }
    for (int i = 1; i <= n; i++)
    {
        nums[i] = dp[i] + nums[i - 1];
        printf("%d ", nums[i]);
    }
    return 0;
}
