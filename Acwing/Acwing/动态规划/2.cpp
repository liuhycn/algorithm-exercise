#include <iostream>

using namespace std;

const int N = 1001;

int v[N], w[N];
int dp[N];

int main()
{
    int n, size;
    scanf("%d%d", &n, &size);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &v[i], &w[i]);
    }
    for (int i = 1; i <= n; i++)
        for (int j = size; j >= v[i]; j--)
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
    printf("%d\n", dp[size]);
}