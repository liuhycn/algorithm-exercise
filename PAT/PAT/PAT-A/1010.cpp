//
//  1010.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/8/18.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

typedef long long LL;

int chartoInt(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    else
        return c - 'a' + 10;
}

LL toDec(string nums, int ra)
{
    int len = nums.size();
    int r = 1;
    LL res = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        res += chartoInt(nums[i]) * r;
        r *= ra;
    }
    return res;
}

bool find(string nums, LL tar, int &res)
{
    for (int i = 2; i <= 36; i++)
    {
        if (toDec(nums, i) == tar)
        {
            res = i;
            return true;
        }
    }
    return false;
}

int main()
{
    cout << "1" << endl;
    string nums1, nums2;
    int tag, ra;
    cin >> nums1 >> nums2 >> tag >> ra;
    LL tar;
    int res;
    string tmp;
    if (tag == 1)
    {
        tar = toDec(nums1, ra);
        tmp = nums2;
    }
    if (tag == 2)
    {
        tar = toDec(nums2, ra);
        tmp = nums1;
    }
    cout << tar << ' ' << tmp << endl;
    if (find(tmp, tar, res)) printf("%d", res);
    else printf("impossible");
    return 0;
}
