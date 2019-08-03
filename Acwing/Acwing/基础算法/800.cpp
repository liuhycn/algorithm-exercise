//
//  800.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/7/30.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"
/*
int nums1[100001];
int nums2[100001];
int n ,m, tar;

bool bsearch(int tar, int &res)
{
    int l = 0;
    int r = m - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (nums2[mid] >= tar)
            r = mid;
        else
            l = mid + 1;
    }
    res = l;
    if (nums2[l] == tar)
        return true;
    else
        return false;
}

int main()
{
    pp();
    int ans1, ans2;
    scanf("%d%d%d", &n, &m, &tar);
    for (int i = 0; i < n; i++)
        scanf("%d", &nums1[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &nums2[i]);
    for (int i = 0; i < n; i++)
    {
        int tmp = tar - nums1[i];
        if (bsearch(tmp, ans2))
        {
            ans1 = i;
            break;
        }
    }
    printf("%d %d", ans1, ans2);
}
*/
int nums1[100001];
int nums2[100001];
int n ,m, tar;

int main()
{
    pp();
    scanf("%d%d%d", &n, &m, &tar);
    for (int i = 0; i < n; i++)
        scanf("%d", &nums1[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &nums2[i]);
    int i = 0, j = m - 1;
    while (i < n && j >= 0)
    {
        if (nums1[i] + nums2[j] > tar)
            j --;
        else if (nums1[i] + nums2[j] < tar)
            i ++;
        else
            break;
    }
    printf("%d %d", i , j);
    return 0;
}
