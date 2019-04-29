//
//  2021.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/29.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int dp[10001];

void init()
{
    memset(dp,0,sizeof(dp));
    dp[0] = 0;
    for(int i = 1;i<=10000;i++)
    {
        int min = 1e9;
        if(i>=1)
        {
            if(min > dp[i-1]+1)
            {
                min = dp[i-1]+1;
            }
        }
        if(i>=2)
        {
            if(min > dp[i-2]+1)
            {
                min = dp[i-2]+1;
            }
        }
        if(i>=5)
        {
            if(min > dp[i-5]+1)
            {
                min = dp[i-5]+1;
            }
        }
        if(i>=10)
        {
            if(min > dp[i-10]+1)
            {
                min = dp[i-10]+1;
            }
        }
        if(i>=50)
        {
            if(min > dp[i-50]+1)
            {
                min = dp[i-50]+1;
            }
        }
        if(i>=100)
        {
            if(min > dp[i-100]+1)
            {
                min = dp[i-100]+1;
            }
        }
        dp[i] = min;
    }
}

int main()
{
    int n;
    init();
    pp();
    while (scanf("%d",&n)!=EOF)
    {
        if(n == 0)
        {
            break;
        }
        int sum = 0;
        int buf[101];
        for(int i = 0;i<n;i++)
        {
            scanf("%d",&buf[i]);
            sum = sum + dp[buf[i]];
        }
        printf("%d\n",sum);
    }
    return 0;
}
