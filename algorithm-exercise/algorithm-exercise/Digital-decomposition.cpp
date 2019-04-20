//
//  Digital-decomposition.cpp
//  wangdao_exercise
//
//  Created by Hongyan Liu on 2019/4/17.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

//输入的数字在inta范围内


#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int num1[10] = {0};
int num2[10] = {0};
int size1 = 0;
int size2 = 0;
int main()
{
    int x,y;
    //cout<<"welcome"<<endl;
    while(scanf("%d%d",&x,&y)!=EOF)
    {
        while(x != 0)
        {
            num1[size1++] = x % 10;
            //cout<<x % 10<<endl;
            x = x / 10;
        }
        while(y != 0)
        {
            num2[size2++] = y % 10;
            //cout<<y % 10<<endl;
            y = y / 10;
        }
        int ans = 0;
        //cout<<size1<<" "<<size2<<endl;
        for(int i = 0;i< size1;i++)
        {
            for (int j = 0; j<size2; j++)
            {
                ans = ans + num1[i] * num2[j];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
