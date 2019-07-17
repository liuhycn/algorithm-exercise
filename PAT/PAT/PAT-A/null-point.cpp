//
//  null-point.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/4.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

double f(double x)
{
    return x * x - 3;
}

int main()
{
    double left = 0;
    pp();
    double right = 2;
    int flag = 0;
    while (right - left > 1e-5)
    {
        double mid = left + (right-left)/2;
        if(f(mid) == 0)
        {
            flag = 1;
            printf("%lf\n",mid);
        }
        else if (f(mid) > 0)
        {
            right = mid;
        }
        else if (f(mid) < 0)
        {
            left = mid;
        }
    }
    if (flag == 0)
    {
        printf("%lf\n",left);
    }
    return 0;
}
