//
//  1021.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/17.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int buf[10];

int main()
{
    pp();
    char num[1001] = {0};
    scanf("%s",num);
    int len = strlen(num);
    for (int i = 0;i<len;i++)
    {
        buf[num[i] - '0']++;
    }
    for (int i = 0;i<10;i++)
    {
        if (buf[i] != 0)
        {
            printf("%d:%d\n",i,buf[i]);
        }
    }
    return 0;
}
