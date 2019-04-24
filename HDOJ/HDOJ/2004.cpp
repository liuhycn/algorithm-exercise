//
//  2004.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/24.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if(n < 0 || n > 100)
        {
            printf("Score is error!\n");
        }
        else if (n >= 90 && n <=100)
        {
            printf("A\n");
        }
        else if (n >= 80 && n <=89)
        {
            printf("B\n");
        }
        else if (n >= 70 && n <=79)
        {
            printf("C\n");
        }
        else if (n >= 60 && n <=69)
        {
            printf("D\n");
        }
        else if (n >= 0 && n <=59)
        {
            printf("E\n");
        }
    }
    return 0;
}
