//
//  1040.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/8/26.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

const int N = 1001;
int dp[N][N];

int main()
{
    cout << endl;
    string str;
    getline(cin, str);
    int len = str.size();
    int res = 0;
    for (int i = 0; i < len; i++)
        for (int j = 0; j <= i; j++)
        {
            if (i == j) dp[i][j] = 1;
            else if (i == j + 1) dp[i][j] = (int)(str[j] == str[i]);
            else dp[i][j] = (int)(str[i] == str[j] && dp[i - 1][j + 1]);
            if (dp[i][j]) res = max(res, i - j + 1);
        }
    cout << res;
    return 0;
}
