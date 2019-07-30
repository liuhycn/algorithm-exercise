//
//  789.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/7/27.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int nums[100001] = {0};
int n;
int t;

void bsearch(int nums[], int &ansl, int &ansr, int tar, int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (nums[mid] >= tar)
            r = mid;
        else
            l = mid + 1;
    }
    if (nums[l] != tar)
    {
        ansl = -1;
        ansr = -1;
        return;
    }
    ansl = l;
    l = 0;
    r = n - 1;
    while (l < r)
    {
        int mid = l + r + 1>> 1;
        if (nums[mid] <= tar)
            l = mid;
        else
            r = mid - 1;
    }
    ansr = r;
}

int main()
{
    pp();
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
    for (int i = 0; i < t; i++)
    {
        int tar;
        scanf("%d", &tar);
        int l,r;
        bsearch(nums, l, r, tar, 0, n - 1);
        printf("%d %d\n", l, r);
    }
    return 0;
}
