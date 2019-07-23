//
//  1003.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/7/16.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

bool check (string str)
{
    int pTime = 0;
    int tTime = 0;
    int pIndex = 0;
    int tIndex = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != 'P' && str[i] != 'A' && str[i] != 'T') {
            return false;
        }
        if (str[i] == 'P') {
            pTime++;
            pIndex = i;
            if (pTime > 1) {
                return false;
            }
        }
        if (str[i] == 'T') {
            tTime++;
            tIndex = i;
            if (tTime > 1) {
                return false;
            }
        }
    }
    if (pIndex > tIndex || pIndex + 1 == tIndex) {
        return false;
    }
    string midA = str.substr(pIndex, tIndex - pIndex - 1);
    if (midA.size() == 1) {
        if (str.substr(0, pIndex) != str.substr(tIndex + 1, str.size() - tIndex - 1)) {
            return false;
        }
    }
    else if (midA.size() > 1) {
        midA.erase(midA.begin());
        string b = midA;
        string a = str.substr(0, pIndex);
        string c = str.substr(tIndex + 1, str.size() - tIndex - 1);
        if (c.size() < a.size())
            return false;
        for (int i = 0; i < a.size(); i++) {
            c.erase(c.end() - 1);
        }
        return check(a + "P" + b + "T" + c);
    }
    return true;
}



int main()
{
    pp();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if (check(str)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
