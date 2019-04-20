#include<iostream>
#include<algorithm>

using namespace std;

struct javahouse
{
	double count;
	double cost;
	double rate;
	bool operator < (const javahouse& b)const
	{
		return rate > b.rate;
	}
}j[1001];

int main()
{
	int n;
	double m;
	while (scanf("%lf%d", &m, &n) != EOF)
	{
		if(m == -1 && n == -1)
		{
			break;
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%lf%lf", &j[i].count, &j[i].cost);
			j[i].rate = j[i].count / j[i].cost;
			//printf("%.3lf\n", j[i].rate);
		}
		sort(j, j + n);
		double ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (j[i].cost >= m)
			{
				ans = ans + m * j[i].rate;
				break;
			}
			else
			{
				//cout << "È«Âò" << i << endl;
				m = m - j[i].cost;
				ans = ans + j[i].count;
				//cout << ans << endl;
			}
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}