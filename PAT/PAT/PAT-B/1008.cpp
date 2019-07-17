//
//  1008.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/5.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    int buf[101];
    pp();
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 0; i<n; i++)
    {
        scanf("%d",&buf[i]);
    }
    m = m % n;
    for (int i = n - m; i<n; i++)
    {
        printf("%d ",buf[i]);
    }
    for (int i = 0; i< n - m; i++)
    {
        printf("%d",buf[i]);
        if(i != n-m-1)
        {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
