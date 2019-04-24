//
//  2002.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/24.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

#define PI 3.1415927

int main()
{
    double r;
    while (scanf("%lf",&r)!=EOF)
    {
        printf("%.3lf\n",(4.0 / 3.0) * PI * r*r*r);
    }
    return 0;
}
