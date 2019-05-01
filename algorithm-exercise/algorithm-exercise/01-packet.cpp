//
//  01-packet.cpp
//  algorithm-exercise
//
//  Created by Hongyan Liu on 2019/4/30.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int val[101];
int cost[101];
int dp[101][1001];


int main()
{
    int t,m;
    //pp();
    while (scanf("%d%d",&t,&m)!=EOF)
    {
        memset(dp, 0, sizeof(dp));
        memset(val, 0, sizeof(val));
        memset(cost, 0, sizeof(cost));
        for(int i = 1;i<=m;i++)
        {
            scanf("%d%d",&cost[i],&val[i]);
        }
        for(int i = 1;i<=m;i++)
        {
            for(int j = 1;j<=t;j++)
            {
                int temp1;
                int temp2;
                if(j - cost[i] < 0)
                {
                    temp1 = 0;
                }
                else
                {
                    temp1 = dp[i - 1][j - cost[i]] + val[i];
                }
                temp2 = dp[i-1][j];
                dp[i][j] = max(temp1,temp2);
            }
        }
        printf("%d\n",dp[m][t]);
    }
    return 0;
}
