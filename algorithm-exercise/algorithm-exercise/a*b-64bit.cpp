//
//  a*b-64bit.cpp
//  algorithm-exercise
//
//  Created by Hongyan Liu on 2019/5/18.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

long long int f(long long int a,long long int b,long long int p)
{
    if (b == 0)
    {
        return 0;
    }
    else if (b == 1)
    {
        return a % p;
    }
    else
    {
        if (b % 2 == 1)
        {
            long long int temp = f(a,(b - 1)/2,p);
            temp = (temp + temp) % p;
            return (temp + a) % p;
        }
        else
        {
            long long int temp = f(a,b/2,p);
            temp = (temp + temp) % p;
            return temp;
        }
    }
}


int main()
{
    pp();
    long long int a,b,p;
    while (scanf("%lld%lld%lld",&a,&b,&p)!=EOF)
    {
        if (a == 0 && b == 0 && p == 0)
        {
            break;
        }
        if (a < b)
        {
            swap(a, b);
        }
        printf("%lld\n",f(a,b,p));
    }
    return 0;
}
