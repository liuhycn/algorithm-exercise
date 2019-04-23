//
//  1001.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/23.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int SUM(int x)
{
    if(x == 1)
    {
        return x;
    }
    else
    {
        return x + SUM(x - 1);
    }
        
}

int main()
{
    int n;
    pp();
    int fiest = 0;
    while (scanf("%d",&n)!=EOF)
    {
        if (fiest == 0)
        {
            fiest = 1;
            printf("%d\n",SUM(n));
        }
        else
        {
            printf("\n");
            printf("%d\n",SUM(n));
        }
    }
    return 0;
}
