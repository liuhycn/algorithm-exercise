//
//  piggy-bank.cpp
//  algorithm-exercise
//
//  Created by Hongyan Liu on 2019/5/4.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int cost[501];
int val[501];

int dp[10001];

void init()
{
    memset(cost,0,sizeof(cost));
    memset(val,0,sizeof(val));
    memset(dp,0,sizeof(dp));
}

int main()
{
    int T;
    //pp();
    scanf("%d",&T);
    while (T-- != 0)
    {
        init();
        int e,f;
        scanf("%d%d",&e,&f);
        int tar = f - e;
        int n;
        scanf("%d",&n);
        for (int i = 1;i<=n;i++)
        {
            scanf("%d%d",&val[i],&cost[i]);
        }
        for(int i = 1;i<=tar;i++)
        {
            dp[i] = 1e9;
        }
        for (int i = 1;i<=n;i++)
        {
            for(int j = cost[i];j<=tar;j++)
            {
                int temp1 = 1e9;
                if(dp[j-cost[i]] != 1e9)
                {
                    temp1 = dp[j-cost[i]] + val[i];
                }
                //printf("%d %d\n",j,temp1);
                dp[j] = min(temp1,dp[j]);
            }
        }
        if(dp[tar] != 1e9)
        {
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[tar]);
        }
        else
        {
            printf("This is impossible.\n");
        }
    }
    return 0;
}
