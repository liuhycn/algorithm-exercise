//
//  1002.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/7/24.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

string buf[10] =
{
    "ling",
    "yi",
    "er",
    "san",
    "si",
    "wu",
    "liu",
    "qi",
    "ba",
    "jiu"
};

int main()
{
    pp();
    int sum = 0;
    char numBuf[101] = {0};
    scanf("%s", numBuf);
    int len = strlen(numBuf);
    for (int i = 0; i < len; i++)
    {
        sum += numBuf[i] - '0';
    }
    char ansBuf[5] = {0};
    sprintf(ansBuf, "%d", sum);
    len = strlen(ansBuf);
    for (int i = 0; i < len; i++)
    {
        if (i == 0)
            printf("%s", buf[ansBuf[i] - '0'].c_str());
        else
            printf(" %s", buf[ansBuf[i] - '0'].c_str());
    }
    return 0;
}
