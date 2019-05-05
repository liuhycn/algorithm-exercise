//
//  1018.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/5.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

char huase[55];
int no[55];

void init()
{
    for(int i = 1;i<=13;i++)
    {
        huase[i] = 'S';
        no[i] = i;
    }
    for(int i = 14;i<=14+12;i++)
    {
        huase[i] = 'H';
        no[i] = i-13;
    }
    for(int i = 27;i<=27+12;i++)
    {
        huase[i] = 'C';
        no[i] = i-26;
    }
    for(int i = 40;i<=40+12;i++)
    {
        huase[i] = 'D';
        no[i] = i-39;
    }
    huase[53] = 'J';
    huase[54] = 'J';
    no[53] = 1;
    no[54] = 2;
}
int buf[55];
char dstc[55];
int dsti[55];
int main()
{
    init();
    pp();
    int k;
    scanf("%d",&k);
    for (int i = 1;i<=54; i++)
    {
        scanf("%d",&buf[i]);
    }
    for (int i = 1;i<=54;i++)
    {
        int temp = i;
        for (int j = 0;j<k;j++)
        {
            temp = buf[temp];
        }
        dstc[temp] = huase[i];
        dsti[temp] = no[i];
    }
    for(int i = 1;i<=54;i++)
    {
        printf("%c%d",dstc[i],dsti[i]);
        if (i!=54)
        {
            printf(" ");
        }
    }
    return 0;
}
