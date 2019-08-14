#include <iostream>

using namespace std;

const int N = 1000001;

int primebuf[N];
int primecnt;
int filter[N];

void fun(int n)
{
	memset(filter, 0, sizeof filter);
	for (int i = 2; i <= n; i++)
	{
		if (filter[i] == 0)
		{
			primebuf[primecnt++] = i;
			for (int j = 2 * i; j <= n; j += i)
			{
				filter[j] = 1;
			}
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	fun(n);
	printf("%d\n", primecnt);
	return 0;
}
