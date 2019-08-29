//
//  1064.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/8/28.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1001;
int n;
vector<int> nums;
int res[N];

void dfs(int l, int r, int index)
{
    if (l == r)
    {
        res[index] = nums[l];
        return;
    }
    if (l > r) return;
    int cnt = r - l + 1;
    int right = 1;
    while (cnt >= right)
    {
        cnt -= right;
        right = right << 1;
    }
    int lastlevel, thislevel;
    int rootindex;
    if (cnt == 0)
    {
        thislevel = right;
        lastlevel = right >> 1;
        rootindex = l + ((r - l + 1) >> 1);
    }
    else
    {
        thislevel = cnt;
        lastlevel = right >> 1;
        if (thislevel <= lastlevel)
        {
            rootindex = (((r - l + 1) - thislevel - 1) >> 1) + thislevel + l;
        }
        else
        {
            rootindex = (((r - l + 1) - thislevel - 1) >> 1) + lastlevel + l;
        }
    }
    res[index] = nums[rootindex];
    dfs(l, rootindex - 1, 2 * index + 1);
    dfs(rootindex + 1, r, 2 * index + 2);
}

int main()
{
    cout << endl;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        nums.push_back(a);
    }
    sort(nums.begin(), nums.end());
    dfs(0, n - 1, 0);
    for (int i = 0; i < n; i++)
        if (i == 0) printf("%d", res[i]);
        else printf(" %d", res[i]);
    return 0;
}
