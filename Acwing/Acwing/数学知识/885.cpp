#include <iostream>

using namespace std;

const int N = 2001, mod = 1e9 + 7;

int c[N][N];
void init()
{
	for (int i = 0; i <= 2000; i++)
		for (int j = 0; j <= i; j++)
			if (j == 0) c[i][j] = 1;
			else if (j == i) c[i][j] = 1;
			else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
}

int main()
{
	int n;
	scanf("%d", &n);
	init();
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", c[a][b]);
	}
	return 0;
}