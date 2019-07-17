//
//  A-1011.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/6.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

char buf[] = {'W', 'T', 'L'};

int main()
{
    double odds[4] = {0};
    pp();
    double ans = 1;
    int index = 0;
    for (int i = 0; i<3; i++)
    {
        double max = -1e9;
        for (int j = 0; j<3; j++)
        {
            scanf("%lf",&odds[j]);
            if(odds[j] > max)
            {
                max = odds[j];
                index = j;
            }
        }
        ans = ans * max;
        printf("%c ",buf[index]);
    }
    printf("%.2lf",(ans*0.65-1)*2);
    return 0;
}
