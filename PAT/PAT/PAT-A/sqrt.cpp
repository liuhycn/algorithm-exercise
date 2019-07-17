//
//  sqrt.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/4.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//
//利用x^2的f单调性，求sqrt(x);


#include "Header.h"

double f(double x)
{
    return x * x;
}

int main()
{
    pp();
    double x = 2;
    double left = 1.0;
    double right = 2.0;
    int flag = 0;
    while (right - left > 1e-5)
    {
        double mid = left+(right - left)/2;
        if(f(mid) == x)
        {
            flag = 1;
            printf("%lf\n",mid);
        }
        else if (f(mid) > x)
        {
            right = mid;
        }
        else if (f(mid) < x)
        {
            left = mid;
        }
    }
    if(flag == 0)
    {
        printf("%lf\n",left);
    }
    return 0;
}
