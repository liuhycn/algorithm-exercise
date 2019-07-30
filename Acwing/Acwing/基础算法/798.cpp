//
//  798.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/7/29.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int nums[1002][1002] = {0};
int dp[1002][1002] = {0};

void insert(int x1, int y1, int x2, int y2, int tmp)
{
    dp[x1][y1] += tmp;
    dp[x2 + 1][y1] -= tmp;
    dp[x1][y2 + 1] -= tmp;
    dp[x2 + 1][y2 + 1] += tmp;
}


int main()
{
    pp();
    int n, m, t;
    scanf("%d%d%d", &m, &n, &t);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++){
            int tmp;
            scanf("%d", &tmp);
            insert(i, j, i, j, tmp);
        }
    for (int i = 0; i < t; i++)
    {
        int x1, y1, x2, y2, inc;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &inc);
        insert(x1, y1, x2, y2, inc);
    }
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] += dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    return 0;
}
