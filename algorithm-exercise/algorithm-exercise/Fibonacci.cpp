//
//  Fibonacci.cpp
//  algorithm-exercise
//
//  Created by Hongyan Liu on 2019/4/26.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

long long int ans[91];

void init()
{
    memset(ans, 0, sizeof(ans));
    ans[1] = 1;
    ans[2] = 1;
    for (int i = 3; i <= 90; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2];
    }
}

int main()
{
    int n;
    pp();
    init();
    while (scanf("%d", &n) != EOF)
    {
        printf("%lld\n", ans[n]);
    }
    return 0;
}
