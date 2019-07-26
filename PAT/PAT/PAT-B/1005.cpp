//
//  1005.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/7/26.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int visit[100001] = {0};
int nums[100001] = {0};

void process(int x)
{
    if (x == 1) return;
    if (x % 2 == 1)
    {
        x = x * 3 + 1 >> 1;
        visit[x] = 1;
        process(x);
    }
    else
    {
        x = x >> 1;
        visit[x] = 1;
        process(x);
    }
}
bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    
    pp();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        nums[i] = tmp;
        process(tmp);
    }
    sort(nums, nums + n, cmp);
    int first = 0;
    for (int i = 0; i < n; i++)
    {
        if (visit[nums[i]] == 0 && first == 0)
        {
            printf("%d", nums[i]);
            first = 1;
        }
        else if (visit[nums[i]] == 0 && first == 1)
            printf(" %d", nums[i]);
    }
    return 0;
}
