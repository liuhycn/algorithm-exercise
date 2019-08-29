#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> nums;
vector<int> res;

int n, tar;
bool dfs(int index, int x)
{
    int tmp = x - nums[index];
    res.push_back(nums[index]);
    if (tmp < 0)
    {
        res.pop_back();
        return false;
    }
    if (tmp == 0) return true;
    for (int i = index + 1; i < n; i++)
    {
        if (nums[i] > tmp) break;
        if (dfs(i, tmp)) return true;
    }
    res.pop_back();
    return false;
}

int main()
{
    cout << endl;
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
        if(dfs(i, tar))
        {
            break;
        }
    }
    
    if (res.size() == 0) printf("No Solution");
    else
    {
        for (int i = 0; i < res.size(); i++)
            if (i == 0) printf("%d", res[i]);
            else printf(" %d", res[i]);
    }
    return 0;
}
