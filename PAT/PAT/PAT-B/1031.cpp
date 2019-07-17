//
//  1031.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/17.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int rright[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};

char M[] = {'1','0','X','9','8','7','6','5','4','3','2'};

int main()
{
    pp();
    int pass = 0;
    int unpass = 0;
    int n;
    scanf("%d",&n);
    while (n !=0)
    {
        char buf[20] = {0};
        scanf("%s",buf);
        int len = strlen(buf)-1;
        int ans = 0;
        for (int i = 0;i<len;i++)
        {
            ans = ans + (buf[i] - '0') * rright[i];
        }
        ans = ans % 11;
        char temp = M[ans];
        //printf("%c\n",temp);
        if (temp == buf[len])
        {
            pass++;
        }
        else
        {
            printf("%s\n",buf);
            unpass++;
        }
        n--;
    }
    if (unpass == 0 && pass != 0)
    {
        printf("All passed");
    }
    return 0;
}
