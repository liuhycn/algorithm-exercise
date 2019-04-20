//
//  lcm.cpp
//  wangdao_exercise
//
//  Created by Hongyan Liu on 2019/4/18.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int gcd(int a,int b)
{
    if(b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b,a%b);
    }
}

int main()
{
    int a,b;
    printf("welcome\n");
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        printf("%d\n",a*b/gcd(a, b));
    }
    return 0;
}
