//
//  1091.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/23.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    int a,b;
    while (scanf("%d%d",&a,&b)!=EOF)
    {
        if(a == 0 && b == 0) break;
        printf("%d\n",a+b);
    }
    return 0;
}
