//
//  1170.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/28.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

double calculate(char op,double x,double y)
{
    double ans;
    if(op == '+')
    {
        ans = x + y;
    }
    else if(op == '-')
    {
        ans = x - y;
    }
    else
    {
        ans = x * y;
    }
    return ans;
}


int main()
{
    char c;
    double a,b;
    int n;
    pp();
    while (scanf("%d",&n)!=EOF)
    {
        getchar();
        for (int i = 0;i<n;i++)
        {
            scanf("%c%lf%lf",&c,&a,&b);
            getchar();
            if(c == '/')
            {
                if((int)a%(int)b == 0)
                {
                    printf("%.0lf\n",a/b);
                }
                else
                {
                    printf("%.2lf\n",a/b);
                }
            }
            else
            {
                printf("%.0lf\n",calculate(c,a,b));
            }
        }

    }
    return 0;
}
