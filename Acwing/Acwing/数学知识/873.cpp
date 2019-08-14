#include <iostream>

using namespace std;

long long int phi(int x)
{
    long long int ans = x;
    for (int i = 2; i <= x / i; i++)
    {
        if (x % i == 0)
        {
            int s = 0;
            while (x % i == 0)
            {
                x /= i;
                s ++;
            }
            ans = ans * (i - 1) / i;
        }
    }
    if (x > 1) ans = ans * (x - 1) / x;
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        printf("%lld\n", phi(a));
    }
    return 0;
}