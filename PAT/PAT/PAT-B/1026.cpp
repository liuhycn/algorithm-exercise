//
//  1026.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/5.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"
#define CLK 100

int main()
{
    int c1,c2;
    pp();
    scanf("%d%d",&c1,&c2);
    int temp = c2 - c1;
    int flag = temp % 100;
    if(flag >= 50)
    {
        flag = 1;
    }
    else
    {
        flag = 0;
    }
    temp = temp / 100 + flag;
    int hh,mm,ss;
    ss = temp % 60;
    temp = temp / 60;
    mm = temp % 60;
    hh = temp / 60;
    printf("%02d:%02d:%02d\n",hh,mm,ss);
    return 0;
}
