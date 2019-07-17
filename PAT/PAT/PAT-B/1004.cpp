//
//  1004.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/6.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

struct stu
{
    char id[12];
    char name[12];
    int val;
    bool operator < (const stu& y)const
    {
        return val < y.val;
    }
    bool operator > (const stu& y)const
    {
        return val > y.val;
    }
    
}thiss,maxs,mins;



int main()
{
    int n;
    pp();
    scanf("%d",&n);
    mins.val = 101;
    maxs.val = -1;
    for (int i = 0;i<n;i++)
    {
        scanf("%s%s%d",thiss.name,thiss.id,&thiss.val);
        if(thiss > maxs)
        {
            maxs.val = thiss.val;
            strcpy(maxs.name, thiss.name);
            strcpy(maxs.id, thiss.id);
        }
        if(thiss < mins)
        {
            mins.val = thiss.val;
            strcpy(mins.name, thiss.name);
            strcpy(mins.id, thiss.id);
        }
    }
    printf("%s %s\n",maxs.name,maxs.id);
    printf("%s %s\n",mins.name,mins.id);
    return 0;
}
