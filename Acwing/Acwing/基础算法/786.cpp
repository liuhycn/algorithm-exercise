//
//  786.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/7/27.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int buf[100001] = {0};
int n;
int k;

int main()
{
    pp();
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &buf[i]);
    }
    sort(buf, buf + n);
    printf("%d", buf[k - 1]);
    return 0;
}

