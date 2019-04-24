//
//  2009.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/24.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    int m;
    double n;
    pp();
    while (scanf("%lf%d",&n,&m)!=EOF)
    {
        double sum = n;
        for(int i = 1;i<m;i++)
        {
            n = sqrt(n);
            sum = sum + n;
        }
        printf("%.2lf\n",sum);
    }
    return 0;
}
