//
//  796.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/7/29.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int nums[1001][1001] = {0};
int dp[1001][1001] = {0};

int main()
{
    pp();
    int m, n, t;
    scanf("%d%d%d", &m, &n, &t);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &nums[i][j]);
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + nums[i][j];
        }
    for (int i = 0; i < t; i++)
    {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("%d\n", dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1]);
    }
    return 0;
}
