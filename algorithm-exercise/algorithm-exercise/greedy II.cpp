#include<iostream>
#include<algorithm>
#define _CRT_SUCURE_NO_WARNINGS

using namespace std;

struct program
{
	int startTime;
	int endTime;
	bool operator < (const program& b)const			//当cmp返回true时，第一个参数会在第二个参数前面
	{
		if (endTime != b.endTime)
		{
			return endTime < b.endTime;
		}
		else
		{
			return startTime > b.startTime;
		}
	}
}p[101];

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)break;
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &p[i].startTime, &p[i].endTime);
		}
		sort(p, p + n);
		int ans = 1;
		int cur = p[0].endTime;
		for (int i = 1; i < n; i++)
		{
			if (cur <= p[i].startTime)
			{
				cur = p[i].endTime;
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}