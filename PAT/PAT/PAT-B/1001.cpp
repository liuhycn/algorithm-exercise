//
//  1002.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/17.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    pp();
    long long int a, b;
    scanf("%ld%ld", &a, &b);
    long long int sum = a + b;
    int fu = 0;
    if (sum < 0)
    {
        fu = 1;
        sum = sum * -1;
    }
    char str[100000] = {0};
    sprintf(str, "%d", sum);
    int length = strlen(str);
    char ans[100000] = {0};
    int flag = 0;
    int cnt = 0;
    for (int i = length - 1; i >= 0; i--)
    {
        ans[flag++] = str[i];
        cnt ++;
        if (cnt % 3 == 0)
        {
            //cnt = 0;
            ans[flag++] = ',';
        }
    }
    if (ans[flag - 1] == ',')
    {
        flag --;
    }
    if (fu == 1)
    {
        printf("-");
    }
    for (int i = flag - 1; i >= 0; i--)
    {
        printf("%c", ans[i]);
    }
    
    //printf("%s\n", str);
    return 0;
}
