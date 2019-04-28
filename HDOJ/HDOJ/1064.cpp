//
//  1064.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/28.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    double x;
    pp();
    while (scanf("%lf",&x)!=EOF)
    {
        double sum = x;
        for(int i = 2;i<=12;i++)
        {
            scanf("%lf",&x);
            sum = sum + x;
        }
        //printf("$");
        printf("$%.2lf\n",sum / 12.0);
    }
    return 0;
}
