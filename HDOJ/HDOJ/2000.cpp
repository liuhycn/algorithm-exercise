//
//  2000.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/24.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    char str[3];
    pp();
    while (scanf("%s",str)!=EOF)
    {
        sort(str, str+3);
        for(int i = 0;i<3;i++)
        {
            if(i == 2)
            {
                printf("%c",str[2]);
            }
            else
            {
                printf("%c ",str[i]);
            }
            
        }
        printf("\n");
    }
    return 0;
}
