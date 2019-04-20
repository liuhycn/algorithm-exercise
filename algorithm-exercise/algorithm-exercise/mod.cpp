//
//  mod.cpp
//  wangdao_exercise
//
//  Created by Hongyan Liu on 2019/4/17.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include <stdio.h>

int main()
{
    int x,y;
    printf("welcome\n");
    scanf("%d%d",&x,&y);
    printf("%d\n",x%y);
    printf("%d\n",((x%y)+y)%y);
    return 0;
}
