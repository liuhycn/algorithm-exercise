//
//  Enumeration.cpp
//  algorithm-exercise
//
//  Created by Hongyan Liu on 2019/4/22.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    //pp();
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int x,y;
        for(x = 0;x<=100;x++)
        {
            for (y = 0; y<100;y++)
            {
                if(14*x + 8*y + 100 <= 3 *n)
                {
                    printf("x=%d,y=%d,z=%d\n",x,y,100-x-y);
                }
            }
        }
    }
    return 0;
}

