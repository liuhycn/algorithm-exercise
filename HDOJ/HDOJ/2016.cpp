//
//  2016.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/28.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    int n;
    pp();
    while (scanf("%d",&n)!=EOF)
    {
        if(n == 0)
        {
            break;
        }
        int buf[101] = {0};
        int min = 1e9;
        int index = 0;
        for (int i= 0;i<n;i++)
        {
            scanf("%d",&buf[i]);
            if(buf[i] < min)
            {
                min = buf[i];
                index = i;
            }
        }
        swap(buf[0],buf[index]);
        for(int i=0;i<n;i++)
        {
            if(i == 0)
            {
                printf("%d",buf[i]);
            }
            else
            {
                printf("% d",buf[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
