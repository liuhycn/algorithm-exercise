//
//  1007.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/7/26.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int primeBuf[10000] = {0};
int primeCnt = 0;
int dp[100001] = {0};
int buf[100001] = {0};

void init(int n)
{
    for (int i = 2; i <=n; i++)
    {
        if (buf[i] == 0)
        {
            primeBuf[primeCnt++] = i;
            
            for (int j = i + i; j <=n; j = j + i)
            {
                buf[j] = 1;
            }
        }
    }
}
void process()
{
    for (int i = 2; i < primeCnt; i++)
    {
        dp[i] = (int)(primeBuf[i] - primeBuf[i - 1] == 2) + dp[i - 1];
    }
}

int main()
{
    pp();
    int n;
    scanf("%d", &n);
    init(n);
    process();
    printf("%d", dp[primeCnt - 1]);
    return 0;
}
