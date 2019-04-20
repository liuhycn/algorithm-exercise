//
//  Hexadecimal conversion.cpp
//  wangdao_exercise
//
//  Created by Hongyan Liu on 2019/4/17.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"
int nums[20] = {0};
int size = 0;
int main()
{
    long long int x,y;
    int m;
    printf("welcome\n");
    while(scanf("%d",&m)!=EOF)
    {
        size = 0;
        memset(nums, 0, sizeof(nums));
        if(m == 0)
        {
            break;
        }
        scanf("%lld%lld",&x,&y);
        long long int sum = x + y;
        if(sum == 0)
        {
            size++;
        }
        while(sum != 0)
        {
            nums[size++] = sum % m;
            sum = sum / m;
        }
        for(int i = size-1 ;i>=0;i--)
        {
            printf("%d",nums[i]);
        }
        printf("\n");
    }
    return 0;
}
