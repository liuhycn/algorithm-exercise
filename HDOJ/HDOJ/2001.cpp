//
//  2001.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/24.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    double x1,y1,x2,y2;
    pp();
    while (scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2)!=EOF)
    {
        printf("%.2lf\n",sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
    }
    return 0;
    
}
