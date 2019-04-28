//
//  LCS.cpp
//  algorithm-exercise
//
//  Created by Hongyan Liu on 2019/4/28.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int dp[101][101];

int main()
{
    char str1[101];
    char str2[101];
    pp();
    while (scanf("%s%s",str1,str2)!=EOF)
    {
        int x = strlen(str1);
        int y = strlen(str2);
        for(int i = 0;i<=x;i++)
        {
            dp[0][i] = 0;
        }
        for(int i = 0;i<=y;i++)
        {
            dp[i][0] = 0;
        }
        for(int j =1;j<=y;j++)
        {
            for(int i = 1;i<=x;i++)
            {
                if(str1[i-1] == str2[j-1])
                {
                    dp[j][i] = dp[j-1][i-1]+1;
                }
                else
                {
                    dp[j][i] = max(dp[j-1][i],dp[j][i-1]);
                }
            }
        }
        printf("%d\n",dp[y][x]);
    }
    return 0;
}
