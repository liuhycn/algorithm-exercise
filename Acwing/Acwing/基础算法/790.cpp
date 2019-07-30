//
//  790.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/7/27.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    pp();
    double n;
    scanf("%lf", &n);
    double l, r;
    if (n < 0)
    {
        l = n;
        r = 0;
    }
    else
    {
        l = 0;
        r = n;
    }
    while (r - l > 1e-8)
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid > n)
            r = mid;
        else
            l = mid;
    }
    printf("%.6lf", l);
    return 0;
}
