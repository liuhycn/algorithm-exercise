//
//  1114.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/30.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int val[501];
int cost[501];
int dp[501][10001];

int main()
{
    int T;
    pp();
    scanf("%d",&T);
    while(T--)
    {
        int p,n;
        scanf("%d%d",&p,&n);
        int tar = n - p;
        int m;
        memset(cost, 0, sizeof(cost));
        memset(dp, 0, sizeof(dp));
        memset(val, 0, sizeof(val));
        scanf("%d",&m);
        for(int i = 1;i<=m;i++)
        {
            scanf("%d%d",&val[i],&cost[i]);
        }
        for (int i = 0; i<=m; i++)
        {
            dp[i][0] = 0;
        }
        for(int i = 1;i<=tar;i++)
        {
            dp[0][i] = 1e9;
        }
        for(int i = 1;i<=m;i++)
        {
            for(int j = 1;j<=tar;j++)
            {
                int min = 1e9;
                for(int k = 0;;k++)
                {
                    if(j - k* cost[i] < 0)
                    {
                        break;
                    }
                    if(dp[i-1][j-k*cost[i]]!=1e9)       //若存在
                    {
                        if(dp[i-1][j-k*cost[i]]+k*val[i] < min)
                        {
                            min = dp[i-1][j-k*cost[i]]+k*val[i];
                        }
                    }
                }
                dp[i][j] = min;
            }
        }
        if(dp[m][tar] == 1e9)
        {
            printf("This is impossible.\n");
        }
        else
        {
            printf("The minimum amout of money in the piggy-bank is %d.\n",dp[m][tar]);
        }
        
    }
    
    return 0;
}
