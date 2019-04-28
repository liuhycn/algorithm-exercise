//
//  LIS.cpp
//  algorithm-exercise
//
//  Created by Hongyan Liu on 2019/4/28.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    int n;
    pp();
    while (scanf("%d",&n)!=EOF)
    {
        int list[30001] = {0};
        for(int i = 1;i<=n;i++)
        {
            scanf("%d",&list[i]);
        }
        int dp[30001];
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2;i<=n;i++)
        {
            int flag = 0;
            int max = 0;
            for(int j = 1;j<=i-1;j++)
            {
                if(list[i] <= list[j])
                {
                    flag = 1;
                    if(dp[j]+1>max)
                    {
                        max = dp[j]+1;
                    }
                }
            }
            if(flag == 0)
            {
                max = 1;
            }
            dp[i] = max;
        }
        int max = 0;
        for(int i = 1;i<=n;i++)
        {
            if(dp[i] > max)
            {
                max = dp[i];
            }
        }
        printf("%d\n",max);
    }
    return 0;
}
