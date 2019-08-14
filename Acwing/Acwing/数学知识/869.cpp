#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
vector<int> ans;

void fun(int x)
{
    for (int i = 1; i <= x / i; i++)
    {
        if (x % i == 0)
        {
            ans.push_back(i);
            if (i != x / i)
                ans.push_back(x / i);
        }
    }
    sort(ans.begin(), ans.end());
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        ans.clear();
        fun(a);
        for (auto i : ans)
            printf("%d ", i);
        printf("\n");
    }
    return 0;
}