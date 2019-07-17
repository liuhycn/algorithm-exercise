//
//  A-1006.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/17.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

struct time
{
    int hh;
    int mm;
    int ss;
    bool operator < (const time &y) const
    {
        bool ans = false;
        if (hh < y.hh)
        {
            ans = true;
        }
        else if (hh == y.hh && mm < y.mm)
        {
            ans = true;
        }
        else if (hh == y.hh && mm == y.mm && ss < y.ss)
        {
            ans = true;
        }
        return ans;
    }
    bool operator > (const time &y) const
    {
        bool ans = false;
        if (hh > y.hh)
        {
            ans = true;
        }
        else if (hh == y.hh && mm > y.mm)
        {
            ans = true;
        }
        else if (hh == y.hh && mm == y.mm && ss > y.ss)
        {
            ans = true;
        }
        return ans;
    }
}fir,las;

int main()
{
    pp();
    struct time tmp1,tmp2;
    char name[20] = {0};
    char ans1[20] = {0};
    char ans2[20] = {0};
    int n;
    scanf("%d",&n);
    scanf("%s",ans1);
    strcpy(ans2, ans1);
    scanf("%2d:%2d:%2d",&fir.hh,&fir.mm,&fir.ss);
    scanf("%2d:%2d:%2d",&las.hh,&las.mm,&las.ss);
    for (int i = 1;i<n;i++)
    {
        scanf("%s",name);
        scanf("%2d:%2d:%2d",&tmp1.hh,&tmp1.mm,&tmp1.ss);
        scanf("%2d:%2d:%2d",&tmp2.hh,&tmp2.mm,&tmp2.ss);
        if (tmp1 < fir)
        {
            fir.hh = tmp1.hh;
            fir.mm = tmp1.mm;
            fir.ss = tmp1.ss;
            strcpy(ans1, name);
        }
        if (tmp2 > las)
        {
            las.hh = tmp2.hh;
            las.mm = tmp2.mm;
            las.ss = tmp2.ss;
            strcpy(ans2, name);
        }
    }
    printf("%s %s",ans1,ans2);
    return 0;
}
