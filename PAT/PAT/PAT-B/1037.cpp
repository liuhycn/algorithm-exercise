//
//  1037.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/17.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    int a,b,c;
    int x,y,z;
    scanf("%d.%d.%d",&a,&b,&c);
    scanf("%d.%d.%d",&x,&y,&z);
    int temp = ((x*17+y)*29+z) - ((a*17+b)*29+c);
    if(temp < 0)
    {
        temp = temp * -1;
        printf("-");
    }
    printf("%d %d %d",temp/(17*29),(temp / 29) % 17,temp % 29);
    return 0;
}
