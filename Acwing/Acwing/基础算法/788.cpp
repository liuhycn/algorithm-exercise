//
//  788.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/7/27.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int buf[100001] = {0};
int n;
long long int ans = 0;
int tmp[100001] = {0};
void merge_sort(int q[], int l, int r)
{
    if (l >= r) return;
    
    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);
    
    int i = l, j = mid + 1;
    int index = 0;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j])
            tmp[index++] = q[i++];
        else
        {
            tmp[index++] = q[j++];
            ans += mid - i + 1;
        }
    }
    while (i <= mid) tmp[index++] = q[i++];
    while (j <= r) tmp[index++] = q[j++];
    index = 0;
    for (int i = l; i <= r; i++)
    {
        q[i] = tmp[index++];
    }
}



int main()
{
    pp();
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &buf[i]);
    }
    merge_sort(buf, 0, n - 1);
    printf("%lld", ans);
    return 0;
}
