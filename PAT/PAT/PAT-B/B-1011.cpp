//
//  B-1011.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/5.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    int T;
    pp();
    scanf("%d",&T);
    int cas = 0;
    while (T-- != 0)
    {
        long long int a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        printf("Case #%d: ",++cas);
        if(a+b>c)
        {
            printf("true\n");
        }
        else
        {
            printf("false\n");
        }
    }
    return 0;
}
