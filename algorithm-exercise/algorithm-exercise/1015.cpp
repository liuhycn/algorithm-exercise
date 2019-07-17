//
//  1015.cpp
//  algorithm-exercise
//
//  Created by Hongyan Liu on 2019/5/20.
//  Copyright © 2019 Hongyan Liu. All rights reserved.

//  用类别编号排序

#include "Header.h"

struct stu
{
    char id[20];
    int de;
    int cai;
    int flag;
}stus[10001];

bool cmp (stu a, stu b)
{
    bool ans = false;
    if (a.flag != b.flag)
    {
        if (a.flag < b.flag)
        {
            ans = true;
        }
    }
    else if (a.de + a.cai != b.cai + b.de)
    {
        if (a.de + a.cai > b.cai + b.de)
        {
            ans = true;
        }
    }
    else
    {
        if (strcmp(a.id, b.id) < 0)
        {
            ans = true;
        }
    }
    return ans;
}

int main()
{
    int n,l,h;
    pp();
    scanf("%d%d%d",&n,&l,&h);
    int cnt = n;
    for (int i = 0; i<n; i++)
    {
        
        scanf("%s%d%d",stus[i].id,&stus[i].de,&stus[i].cai);
        
        if (stus[i].de < l || stus[i].cai < l)
        {
            stus[i].flag = 5;
            cnt--;
        }
        else if (stus[i].de >= h && stus[i].cai >= h)
        {
            stus[i].flag = 1;
        }
        else if (stus[i].de >= h && stus[i].cai < h)
        {
            stus[i].flag = 2;
        }
        else if (stus[i].cai < h && stus[i].de < h && stus[i].de >= stus[i].cai)
        {
            stus[i].flag = 3;
        }
        else
        {
            stus[i].flag = 4;
        }
    }
    sort(stus,stus+n,cmp);
    printf("%d\n",cnt);
    for (int i = 0;i<cnt;i++)
    {
        printf("%s %d %d\n",stus[i].id,stus[i].de,stus[i].cai);
    }
    return 0;
}
