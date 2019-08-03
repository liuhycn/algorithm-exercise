//
//  1071.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/7/31.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"



bool isLeagle(char c)
{
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return true;
    else
        return false;
}


map <string, int> mymap;

int main()
{
    pp();
    string buf;
    getline(cin, buf);
    int len = buf.length();
    int sub = (int)('a' - 'A');
    for (int i = 0; i < len; i++)
    {
        if (buf[i] >= 'A' && buf[i] <= 'Z')
            buf[i] += sub;
    }
    
    for (int i = 0; i < len; i++)
        if (buf[i] != ' ' && !isLeagle(buf[i]))
            buf[i] = ' ';
    
    cout << buf;
    
    string tmp = "";
    for (int i = 0; i < len; i++)
    {
        int j = i;
        while (j < len && buf[j] != ' ')
        {
            tmp += buf[j];
            j++;
        }
        i = j;
        if (tmp != "")
        {
            mymap[tmp] ++;
        }
        tmp = "";
    }
    int max = 0;
    string ans;
    for (auto item : mymap)
    {
        if (item.second > max)
        {
            max = item.second;
            ans = item.first;
        }
        else if (item.second == max)
        {
            if (item.first < ans)
                ans = item.first;
        }
    }
    printf("%s %d", ans.c_str(), max);
    return 0;
}
