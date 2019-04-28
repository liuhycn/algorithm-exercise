//
//  2014.cpp
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
        int buf[101] = {0};
        int sum = 0;
        for(int i = 0;i<n;i++)
        {
            scanf("%d",&buf[i]);
            sum = sum + buf[i];
        }
        sort(buf,buf+n);
        sum = sum - buf[0];
        sum = sum - buf[n-1];
        printf("%.2lf\n",sum*1.0/(n-2));
    }
}
