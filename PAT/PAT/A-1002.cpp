//
//  A-1002.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/5.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    pp();
    int azhi[1002];
    double axi[1002];
    int bzhi[1002];
    double bxi[1002];
    int czhi[1002];
    double cxi[1002];
    int sum = 0;
    int an;
    scanf("%d",&an);
    for (int i = 0;i<an;i++)
    {
        scanf("%d",&azhi[i]);
        scanf("%lf",&axi[i]);
    }
    int bn;
    scanf("%d",&bn);
    for (int i = 0;i<bn;i++)
    {
        scanf("%d",&bzhi[i]);
        scanf("%lf",&bxi[i]);
    }
    int i=0;
    int j=0;
    while (1)
    {
        if(i == an || j == bn)
        {
            break;
        }
        
        if(azhi[i] > bzhi[j])
        {
            czhi[sum] = azhi[i];
            cxi[sum] = axi[i];
            i++;
            sum++;
        }
        else if (azhi[i] == bzhi[j])
        {
            double tmp = axi[i] + bxi[j];
            if(tmp == 0)
            {
                i++;
                j++;
                continue;
            }
            else
            {
                czhi[sum] = azhi[i];
                cxi[sum] = tmp;
                i++;
                j++;
                sum++;
            }
        }
        else if (azhi[i] < bzhi[j])
        {
            czhi[sum] = bzhi[j];
            cxi[sum] = bxi[j];
            j++;
            sum++;
        }
    }
    if(i!=an)
    {
        while (i!=an)
        {
            czhi[sum] = azhi[i];
            cxi[sum] = axi[i];
            sum++;
            i++;
        }
    }
    if(j!=bn)
    {
        while (j!=bn)
        {
            czhi[sum] = bzhi[j];
            cxi[sum] = bxi[j];
            sum++;
            j++;
        }
    }
    printf("%d",sum);
    for(i = 0;i<sum;i++)
    {
        printf(" %d",czhi[i]);
        printf(" %.1lf",cxi[i]);
    }
    return 0;
}
