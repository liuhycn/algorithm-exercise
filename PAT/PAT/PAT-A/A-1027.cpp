//
//  A-1027.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/17.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

char buf[13] =
{
    '0',
    '1',
    '2',
    '3',
    '4',
    '5',
    '6',
    '7',
    '8',
    '9',
    'A',
    'B',
    'C'
};
int main()
{
    int a,b,c;
    pp();
    scanf("%d%d%d",&a,&b,&c);
    printf("#");
    printf("%c%c",buf[a/13],buf[a%13]);
    printf("%c%c",buf[b/13],buf[b%13]);
    printf("%c%c",buf[c/13],buf[c%13]);
    return 0;
}
