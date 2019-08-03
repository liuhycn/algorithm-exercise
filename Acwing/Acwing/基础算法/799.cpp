//
//  799.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/7/30.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"


int main()
{
    int n;
    int nums[100001] = {0};
    int s[100001] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
    int ans = 0;
    for (int i = 0, j = 0; j < n; i++)
    {
        while (j < n && s[nums[j]] == 0)
        {
            s[nums[j]]++;
            j++;
        }
        ans = max(ans, j - i);
        if (j == n) break;
        while (nums[i] != nums[j])
        {
            s[nums[i]]--;
            i++;
        }
        s[nums[i]]--;
    }
    printf("%d", ans);
    return 0;
}
