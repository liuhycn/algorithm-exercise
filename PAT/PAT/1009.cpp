//
//  1009.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/6.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    //pp();
    int azhi[1001] = {0};
    double axi[1001] = {0};
    double cxi[2001] = {0};
    
    int an;
    scanf("%d",&an);
    
    for (int i = 0;i<an;i++)
    {
        scanf("%d",&azhi[i]);
        scanf("%lf",&axi[i]);
    }
    int bn;
    scanf("%d",&bn);
    for (int i = 0 ;i<bn;i++)
    {
        int thiszhi;
        double thisxi;
        
        scanf("%d%lf",&thiszhi,&thisxi);
        
        for (int j = 0;j<an;j++)
        {
            int newzhi;
            double newxi;
            
            newzhi = azhi[j] + thiszhi;
            newxi = axi[j] * thisxi;
            //printf("%d %.1lf * %d %.1lf = %d %.1lf\n",thiszhi,thisxi,azhi[j],axi[j],newzhi,newxi);
            cxi[newzhi] += newxi;
        }
    }
    int sum = 0;
    for (int i = 2000;i>=0;i--)
    {
        if(cxi[i] != 0.0)
        {
            sum ++;
        }
    }
    printf("%d",sum);
    for (int i = 2000;i>=0;i--)
    {
        if(cxi[i] != 0.0)
        {
            printf(" %d %.1lf",i,cxi[i]);
        }
    }
    return 0;
}
