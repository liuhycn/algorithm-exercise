//
//  binary-exponentiation.cpp
//  wangdao_exercise
//
//  Created by Hongyan Liu on 2019/4/19.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    int a,b;
    printf("welcome\n");
    while (scanf("%d%d",&a,&b)!=EOF)
    {
        int ans = 1;
        while(b!=0)
        {
            if(b%2 == 1)
            {
                ans = ans * a;
                ans = ans % 1000;
            }
            b = b >> 1;
            a = a * a;
            a = a % 1000;
        }
        printf("%d\n",ans);
    }
    return 0;
}
