//
//  1100.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/7/18.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

string buf[13][2] =
{
    "tret", "tret",
    "jan", "tam",
    "feb", "hel",
    "mar", "maa",
    "apr", "huh",
    "may", "tou",
    "jun", "kes",
    "jly", "hei",
    "aug", "elo",
    "sep", "syy",
    "oct", "lok",
    "nov", "mer",
    "dec", "jou"
};

map<string, int> mymap;
void init()
{
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 0)
                mymap[buf[i][j]] = i;
            if (j == 1)
                mymap[buf[i][j]] = i * 13;
        }
    }
}

int main()
{
    pp();
    init();
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        string num;
        getline(cin, num);
        if (num[0] >= '0' && num[0] <= '9')
        {
            int tmp;
            sscanf(num.c_str(), "%d", &tmp);
            if (tmp % 13 == 0)
            {
                printf("%s\n", buf[tmp/13][1].c_str());
            }
            else
            {
                int x, y;
                x = tmp / 13;
                y = tmp % 13;
                if (x != 0)
                    printf("%s %s\n", buf[x][1].c_str(), buf[y][0].c_str());
                else
                    printf("%s\n", buf[y][0].c_str());
            }
        }
        else
        {
            if (num.length() > 4)
            {
                string x = "";
                string y = "";
                int j = 0;
                for (j = 0; j < num.length(); j++)
                {
                    if (num[j] == ' ') break;
                    else x += num[j];
                }
                y = num.substr(j + 1, num.length() - j - 1);
                printf("%d\n", mymap[x] + mymap[y]);
            }
            else
            {
                printf("%d\n", mymap[num]);
            }
        }
    }
    return 0;
}
