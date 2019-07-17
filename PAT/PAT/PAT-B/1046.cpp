//
//  1046.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/5.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

//  甲喊 甲划 乙喊 乙划

int main()
{
    int a,b,c,d;
    pp();
    int n;
    int sum1 = 0;
    int sum2 = 0;
    scanf("%d",&n);
    for (int i = 0; i<n; i++)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        int sum = a + c;
        if (b == sum && d != sum)
        {
            sum2++;
        }
        else if (d == sum && b!= sum)
        {
            sum1++;
        }
        else
        {
            continue;
        }
    }
    printf("%d %d\n",sum1,sum2);
    return 0;
}
