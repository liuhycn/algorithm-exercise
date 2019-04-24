//
//  2039.cpp
//  
//
//  Created by Hongyan Liu on 2019/4/25.
//

#include "Header.h"

int main()
{
    int n;
    pp();
    while (scanf("%d",&n)!=EOF)
    {
        for (int i =0;i<n;i++)
        {
            double line[3];
            scanf("%lf",&line[0]);
            scanf("%lf",&line[1]);
            scanf("%lf",&line[2]);
            sort(line,line+3);
            if(line[0] + line[1] > line[2])
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}
