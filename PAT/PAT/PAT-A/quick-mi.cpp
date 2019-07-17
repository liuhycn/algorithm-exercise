//
//  quick-mi.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/4.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int x,y;

long long int f(int x, int y)
{
    if(y == 0) return 1;
    if(x == 0 || y == 1) return x;
    
    if(y % 2 == 0)
    {
        long long int tmp =f(x,y/2);
        return tmp * tmp;
    }
    else
    {
        long long int tmp = f(x,(y-1)/2);
        return tmp * tmp * x;
    }
}


int main()
{
    pp();
    while (scanf("%d%d",&x,&y)!=EOF)
    {
        printf("%lld\n",f(x,y));
    }
    return 0;
}
