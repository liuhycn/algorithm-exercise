//
//  2005.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/24.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"


int dayofmonth[13][2]=
{
    0,0,
    31,31,
    28,29,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31
};

bool isLeap(int x)
{
    if((x%4 == 0 && x%100 !=0) || x%400 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int y,m,d;
    pp();
    while (scanf("%d/%d/%d",&y,&m,&d)!=EOF)
    {
        int flag = isLeap(y);
        int sum = 0;
        for(int i = 1;i<=m-1;i++)
        {
            sum = sum + dayofmonth[i][flag];
        }
        printf("%d\n",sum+d);
    }
    return 0;
}
