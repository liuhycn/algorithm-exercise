
//
//  1041.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/6.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

struct stu
{
    char id[17];
    int no;
}buf[1001];

int main()
{
    int n;
    pp();
    scanf("%d",&n);
    for (int i = 0;i<n;i++)
    {
        char str[17] = {0};
        int a;
        int b;
        scanf("%s%d%d",str,&a,&b);
        buf[a].no = b;
        strcpy(buf[a].id, str);
    }
    scanf("%d",&n);
    for (int i = 0;i<n;i++)
    {
        int que;
        scanf("%d",&que);
        printf("%s %d\n",buf[que].id,buf[que].no);
    }
    return 0;
}
