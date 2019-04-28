//
//  2734.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/28.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int conver(char x)
{
    if(x == ' ')
    {
        return 0;
    }
    else
    {
        return x - 'A' + 1;
    }
}


int quicksum(char * str)
{
    int ans = 0;
    int length = strlen(str);
    for (int i = 0;i<length;i++)
    {
        ans = ans + ((i+1) * conver(str[i]));
    }
    return ans;
}


int main()
{
    pp();
    while (1)
    {
        char str[256];
        gets(str);
        if(str[0] == '#')
        {
            break;
        }
        printf("%d\n",quicksum(str));
    }
    return 0;
}
