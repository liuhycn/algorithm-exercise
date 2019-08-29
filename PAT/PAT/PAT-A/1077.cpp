//
//  1077.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/8/29.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;

vector<string> words;

bool check(int index)
{
    char tmp = words[0][index];
    for (int i = 0; i < words.size(); i++)
    {
        if (words[i][index] != tmp) return false;
    }
    return true;
}


int main()
{
    scanf("%d", &n);
    getchar();
    if (n == 0)
    {
        printf("nai");
        return 0;
    }
    int len = 0x3f3f3f3f;
    for (int i = 0; i < n; i ++)
    {
        string str;
        getline(cin, str);
        len = min(len, (int)str.size());
        reverse(str.begin(), str.end());
        words.push_back(str);
    }
    string res;
    int index = 0;
    while (index < len)
    {
        if (check(index))
        {
            res += words[0][index];
            index ++;
        }
        else break;
    }
    if (res.size() == 0) printf("nai");
    else
    {
        reverse(res.begin(), res.end());
        printf("%s", res.c_str());
    }
    return 0;
}
