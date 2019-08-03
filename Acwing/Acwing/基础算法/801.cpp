//
//  801.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/7/30.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int help(int x)
{
    unsigned int tmp = (unsigned int)x;
    int sum = 0;
    while (tmp != 0)
    {
        if (tmp % 2 == 1)
            sum++;
        tmp = tmp >> 1;
    }
    return sum;
}

int nums[100001];
int n;

int main()
{
    pp();
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
        printf("%d ", help(nums[i]));
    }
    return 0;
}
