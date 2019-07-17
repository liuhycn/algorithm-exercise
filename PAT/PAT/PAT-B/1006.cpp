//
//  1006.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/17.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    pp();
    char buf[4] = {0};
    scanf("%s",buf);
    if (strlen(buf) == 3)
    {
        for (int i = 0; i<buf[0] - '0'; i++)
        {
            printf("B");
        }
        for (int i = 0; i<buf[1] - '0'; i++)
        {
            printf("S");
        }
        for (int i = 1;i<=buf[2]-'0';i++)
        {
            printf("%d",i);
        }
    }
    else if (strlen(buf) == 2)
    {
        for (int i = 0; i<buf[0] - '0'; i++)
        {
            printf("S");
        }
        for (int i = 1;i<=buf[1]-'0';i++)
        {
            printf("%d",i);
        }
    }
    else if (strlen(buf) == 1)
    {
        for (int i = 1;i<=buf[0]-'0';i++)
        {
            printf("%d",i);
        }
    }
    return 0;
}
