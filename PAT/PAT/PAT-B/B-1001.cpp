//
//  B-1001.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/1.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    int n;
    pp();
    scanf("%d",&n);
    int cnt = 0;
    while(n != 1)
    {
        if(n%2 == 0)
        {
            n = n/2;
            cnt++;
        }
        else
        {
            n = (3*n+1)/2;
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
