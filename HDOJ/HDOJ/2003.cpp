//
//  2003.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/24.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    double n;
    while (scanf("%lf",&n)!=EOF)
    {
        printf("%.2lf\n",fabs(n));
    }

    return 0;
}
