//
//  1090.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/23.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i = 0;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            printf("%d\n",a+b);
        }
    }
    return 0;
}
