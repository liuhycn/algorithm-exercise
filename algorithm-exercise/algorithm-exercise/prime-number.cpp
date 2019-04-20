//
//  prime-number.cpp
//  wangdao_exercise
//
//  Created by Hongyan Liu on 2019/4/18.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

bool isprime(int a)
{
    if (a <= 1)                         //1 is not a prime number
    {
        return false;
    }
    for(int i = 2;i< sqrt(a)+1;i++)     //sqrt()+1
    {
        if(a%i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int x;
    printf("welcome\n");
    while (scanf("%d",&x)!=EOF)
    {
        printf("%d\n",isprime(x));
    }
    return 0;
}
