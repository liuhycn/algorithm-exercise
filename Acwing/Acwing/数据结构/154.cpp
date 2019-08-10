//
//  154.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/8/7.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"


int q[100001];
int ff = 0;
int tt = -1;
int n, k;
int nums[100001];

int main()
{
    pp();
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);
    for (int i = 0; i < n; i++)
    {
        if (q[ff] == i - k)
            ff ++;
        while (ff <= tt && nums[i] <= nums[q[tt]])
            tt --;
        q[++tt] = i;
        if (i >= k - 1)
            printf("%d ", nums[q[ff]]);
    }
    printf("\n");
    ff = 0;
    tt = -1;
    for (int i = 0; i < n; i++)
    {
        if (q[ff] == i - k)
            ff ++;
        while (ff <= tt && nums[i] >= nums[q[tt]])
            tt --;
        q[++tt] = i;
        if (i >= k - 1)
            printf("%d ", nums[q[ff]]);
    }
    return 0;
}
