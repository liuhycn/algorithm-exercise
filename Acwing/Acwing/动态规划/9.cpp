#include <iostream>

using namespace std;

const int N = 101;

int v[N][N];
int w[N][N];
int dp[N][N];
int cnt[N];


int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d", &a);
        cnt[i] = a;
        for (int j = 1; j <= a; j++)
            scanf("%d%d", &v[i][j], &w[i][j]);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j]);
            for (int k = 1; k <= cnt[i]; k++)
            {
                if (j >= v[i][k])
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i][k]] + w[i][k]);
                }
            }
        }
    printf ("%d\n", dp[n][m]);  
    return 0;
}