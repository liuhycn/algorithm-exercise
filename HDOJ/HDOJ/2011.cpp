//
//  2011.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/25.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

double F(double x)
{
    if(x == 1)
    {
        return 1.0;
    }
    if((int)x%2 ==1)
    {
        return 1.0/x + F(x-1);
    }
    else
    {
        return -1.0 / x + F(x-1);
    }
}


int main()
{
    int n;
    pp();
    while (scanf("%d",&n)!=EOF)
    {
        double ans = 0;
        for (int i = 0;i<n;i++)
        {
            double x;
            scanf("%lf",&x);
            ans = F(x);
            printf("%.2lf\n",ans);
        }
    }
    return 0;
}
