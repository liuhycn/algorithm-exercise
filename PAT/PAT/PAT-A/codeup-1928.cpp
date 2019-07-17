//
//  date-process.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/1.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"


bool isLeap(int x)
{
    if((x%4 == 0&& x%100!=0) || x%400 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int dayofmonth[13][2]
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
struct date
{
    int y;
    int m;
    int d;
    void inc()
    {
        d++;
        int flag = isLeap(y);
        if(d > dayofmonth[m][flag])
        {
            d = 1;
            m++;
        }
        if(m > 12)
        {
            m = 1;
            y++;
        }
    }
};
int buf[5001][13][32] = {0};

void init()
{
    date temp;
    temp.y = 0;
    temp.m = 1;
    temp.d = 1;
    int sum = 0;
    while(temp.y != 5001)
    {
        buf[temp.y][temp.m][temp.d] = sum;
        temp.inc();
        sum++;
    }
}

int main()
{
    int yy,mm,dd;
    pp();
    init();
    {
        while (scanf("%4d%2d%2d",&yy,&mm,&dd)!=EOF)
        {
            int temp1 = buf[yy][mm][dd];
            scanf("%4d%2d%2d",&yy,&mm,&dd);
            int temp2 = buf[yy][mm][dd];
            printf("%d\n",abs(temp1 - temp2)+1);
        }
    }
    return 0;
}
