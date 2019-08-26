//
//  1037.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/8/25.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100001;
int n, m;
int nums1[N], nums2[N];

int main()
{
    cout << endl;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &nums1[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        scanf("%d", &nums2[i]);
    sort(nums1, nums1 + n);
    sort(nums2, nums2 + m);
    int i = 0, j = 0;
    LL sum = 0;
    while (nums1[i] < 0 && nums2[j] < 0)
    {
        sum += (LL)nums1[i] * nums2[j];
        i ++;
        j ++;
    }
    i = n - 1;
    j = m - 1;
    while (nums1[i] > 0 && nums2[j] > 0)
    {
        sum += (LL)nums1[i] * nums2[j];
        i --;
        j --;
    }
    printf("%lld", sum);
    return 0;
}
