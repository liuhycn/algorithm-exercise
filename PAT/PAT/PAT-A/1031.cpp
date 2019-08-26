//
//  1031.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/8/25.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

char buf[101][101];

int main()
{
    cout << endl;
    string nums;
    cin >> nums;
    int len = nums.size() - 2;
    int l ,r;
    if (len % 3 == 2)
    {
        r = len / 3;
        l = r + 2;
    }
    else if (len % 3 == 1)
    {
        l = len / 3 + 2;
        r = len / 3 - 1;
    }
    else
    {
        l = len / 3 + 1;
        r = len / 3;
    }
    for (int i = 0; i < l; i ++)
        for (int j = 0; j < r + 2; j++)
            buf[i][j] = ' ';
    
    int index = 0;
    
    for (int i = 0; i < l; i++)
    {
        buf[i][0] = nums[index++];
    }
    for (int i = 1; i < r + 1; i++)
    {
        buf[l - 1][i] = nums[index++];
    }
    for (int i = l - 1; i >= 0; i--)
    {
        buf[i][r + 1] = nums[index++];
    }
    for (int i = 0; i < l; i ++)
    {
        for (int j = 0; j < r + 2; j++)
            printf("%c", buf[i][j]);
        
        printf("\n");
    }
    
    return 0;
}
