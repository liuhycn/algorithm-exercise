#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> PII;

int n;
vector<PII> ans;

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
			ans.push_back({i, s});
		}
	}
	if (x > 1) ans.push_back({x, 1});
}

int main()
{
	scanf("%d", &n);	
	for (int i = 0; i < n; i++)
	{
		ans.clear();
		int a;
		scanf("%d", &a);
		fun(a);
		for (auto item : ans)
			printf("%d %d\n", item.first, item.second);
		printf("\n");
	}
	return 0;
} 