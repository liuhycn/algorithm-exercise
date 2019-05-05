//
//  A-1065.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/5.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    long long int a,b,c;
    int n;
    pp();
    scanf("%d",&n);
    for (int i = 1;i<=n;i++)
    {
        int flag;
        scanf("%lld%lld%lld",&a,&b,&c);
        if(a > 0 && b > 0 && a+b < 0)
        {
            flag = 1;
        }
        else if (a < 0 && b < 0 && (a + b) >= 0)
        {
            flag = 0;
        }
        else if (a+b > c)
        {
            flag = 1;
        }
        else if (a+b <= c)
        {
            flag = 0;
        }
        
        if(flag == 1)
        {
            printf("Case #%d: ",i);
            printf("true\n");
            
        }
        else
        {
            printf("Case #%d: ",i);
            printf("false\n");
            
        }
    }
    return 0;
}
