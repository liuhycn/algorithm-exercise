#include <iostream>

using namespace std;

const int N = 20001;

int dp[N], w[N], v[N];
int cnt;

int main()
{
    int n, size;
    scanf("%d%d", &n, &size);
    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c);
        int r = 1;
        while (true)
        {
            if (c > r)
            {
                c -= r;
                cnt ++;
                v[cnt] = a * r;
                w[cnt] = b * r;
                r  = r << 1;
            }
            else 
            {
                cnt ++;
                v[cnt] = a * c;
                w[cnt] = b * c;
                break;
            }
        }
    }
    
    for (int i = 1; i <= cnt; i++)
        for (int j = size; j >= v[i]; j--)
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
    printf("%d\n", dp[size]);
    return 0;
}