//
//  1048.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/8/26.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<int, vector<int>> dict;
vector<int> nums;
pair<int, int> res;

int main()
{
    int n, tar;
    scanf("%d%d", &n, &tar);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        nums.push_back(a);
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        if (dict.find(nums[i]) == dict.end())
        {
            dict[nums[i]] = vector<int>(1, i);
        }
        else
        {
            dict[nums[i]].push_back(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (dict.find(tar - nums[i]) != dict.end())
        {
            for (int j = 0; j < dict[tar - nums[i]].size(); j++)
            {
                if (dict[tar - nums[i]][j] != i)
                {
                    printf("%d %d", nums[i], tar - nums[i]);
                    return 0;
                }
            }
        }
    }
    printf("No Solution");
    return 0;
}
