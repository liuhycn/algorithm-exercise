//
//  1028.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/6.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

struct date
{
    char name[6];
    int year;
    int month;
    int day;
    bool operator > (const date& y)const
    {
        if (year != y.year)
        {
            return year < y.year;
        }
        if (month != y.month)
        {
            return month < y.month;
        }
        return day < y.day;
    }
    bool operator < (const date& y)const
    {
        if (year != y.year)
        {
            return year > y.year;
        }
        if (month != y.month)
        {
            return month > y.month;
        }
        return day > y.day;
    }
    bool islegel()
    {
        if(year > 2014)
        {
            return false;
        }
        if(year == 2014 && month > 9)
        {
            return false;
        }
        if(year == 2014 && month == 9 && day > 6)
        {
            return false;
        }
        if(year < 1814)
        {
            return false;
        }
        if(year == 1814 && month < 9)
        {
            return false;
        }
        if(year == 1814 && month == 9 && day < 6)
        {
            return false;
        }
        return true;
    }
}pthis,pmax,pmin;

int main()
{
    int n;
    pp();
    int sum = 0;
    pmax.year = 2015;
    pmax.month= 9;
    pmax.day = 6;
    pmin.year = 1813;
    pmin.month = 9;
    pmin.day = 6;
    scanf("%d",&n);
    for (int i = 0;i<n;i++)
    {
        scanf("%s%d/%d/%d",pthis.name,&pthis.year,&pthis.month,&pthis.day);
        if(pthis.islegel())
        {
            sum++;
        }
        else
        {
            continue;
        }
        if(pthis > pmax)
        {
            strcpy(pmax.name, pthis.name);
            pmax.year = pthis.year;
            pmax.month= pthis.month;
            pmax.day = pthis.day;
        }
        if(pthis < pmin)
        {
            strcpy(pmin.name, pthis.name);
            pmin.year = pthis.year;
            pmin.month = pthis.month;
            pmin.day = pthis.day;
        }
    }
    if(sum)
    {
        printf("%d %s %s\n",sum,pmax.name,pmin.name);
    }
    else
    {
        printf("0\n");
    }
    
    return 0;
}
