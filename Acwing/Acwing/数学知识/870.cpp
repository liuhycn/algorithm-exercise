#include <iostream>
#include <map>

using namespace std;

map<int, int> primes;
int n;
const int mod = 1e9 + 7;

void fun(int x)
{
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
            primes[i] += s;
        }
    }
    if (x > 1)
        primes[x] ++;
}

int main()
{   
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        fun(a);
    }
    long long int ans = 1;
    for (auto prime : primes)
    {
        ans = (ans * (prime.second + 1)) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}