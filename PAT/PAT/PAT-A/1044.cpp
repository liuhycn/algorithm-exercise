//
//  1044.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/8/26.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include <iostream>
#include <vector>


using namespace std;
typedef pair<int, int> PII;
int curans = 0x3f3f3f3f;
vector<int> nums;
vector<PII> res;
int main()
{
    cout << endl;
    int n, tar;
    scanf("%d%d", &n, &tar);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        nums.push_back(a);
    }
    int i = 0, j = 0;
    int sum = 0;
    while (1)
    {
        while (sum < tar && j < n)
            sum += nums[j++];
        if (sum < curans && sum >= tar)
        {
            curans = sum;
            res.clear();
            res.push_back({i, j - 1});
        }
        else if (sum == curans)
            res.push_back({i, j - 1});
        while (sum >= tar && i < j)
        {
            sum -= nums[i++];
            if(sum<curans && sum>=tar)
            {
                curans=sum;
                res.clear();
                res.push_back({i, j - 1});
            }
            else if (sum == curans)
                res.push_back({i, j - 1});
        }
        if (j == n) break;
    }
    for (auto ans : res)
    {
        printf("%d-%d\n", ans.first + 1, ans.second + 1);
    }
    return 0;
}
