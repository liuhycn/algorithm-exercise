#include <iostream>

using namespace std;

const int mod = 1e9 + 7, N = 100001;
typedef long long LL;

LL qmi(int a, int b)
{
	if (b == 0) return 1;
	LL tmp = qmi(a, b >> 1);
	if (b % 2 == 1) return tmp * tmp % mod * a % mod;
	else return tmp * tmp % mod;
}

LL fact[N], infact[N];


int main()
{
	int n;
	scanf("%d", &n);
	fact[0] = 1;
	infact[0] = 1;
	for (int i = 1; i < N; i++)
	{
		fact[i] = fact[i - 1] * i % mod;
		infact[i] = infact[i - 1] * qmi(i, mod - 2) % mod;
	}
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%lld\n", fact[a] * infact[a - b] % mod * infact[b] % mod);
	}	
	return 0;
}