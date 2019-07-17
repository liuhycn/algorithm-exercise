//
//  1022.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/17.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    pp();
    int a,b,d;
    scanf("%d%d%d",&a,&b,&d);
    char ans[50] = {0};
    int temp = a + b;
    int cnt = 0;
    while (temp != 0)
    {
        ans[cnt++] = (temp % d) + '0';
        temp = temp / d;
    }
    reverse(ans,ans+cnt);
    if (strlen(ans) == 0)
    {
        ans[0] = '0';
    }
    printf("%s",ans);
}
