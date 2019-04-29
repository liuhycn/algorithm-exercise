//
//  dp.cpp
//  algorithm-exercise
//
//  Created by Hongyan Liu on 2019/4/28.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"
int weight[2001];


int dp[2001][1001];
//dp[i][j]，代表前i件物品中拿走j组时的最小cost

void init(int n,int k)
{
    for(int i = 1;i<=k;i++)
    {
        dp[0][i] = 1e9;
        dp[1][i] = 1e9;
    }
    for(int i = 0;i<=n;i++)
    {
        dp[i][0] = 0;
    }
    for(int i = 2;i<=n;i++)
    {
        for(int j = 1;j<=k;j++)
        {
            //printf("1\n");
            if(2*j <= i)
            {
                dp[i][j] = min(dp[i-1][j],dp[i-2][j-1]+(weight[i]-weight[i-1])*(weight[i]-weight[i-1]));
            }
            else
            {
                dp[i][j] = 1e9;
            }
        }
    }
}

int main()
{
    int n,k;
    pp();
    while (scanf("%d%d",&n,&k)!=EOF)
    {
        memset(weight,0,sizeof(weight));
        memset(dp, 0,sizeof(dp));
        for(int i = 1;i<=n;i++)
        {
            scanf("%d",&weight[i]);
        }
        sort(weight+1, weight+n+1);
        init(n,k);
        printf("%d\n",dp[n][k]);
    }
    return 0;
}
