#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#define _CRT_SECURE_NO_WARNINGS
#define isleap(x) (x % 100 != 0 && x % 4 == 0 || x % 400 == 0) ? 1 : 0

using namespace std;

int dayofmonth[13][2] =
{
	0,0,
	31,31,
	28,29,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31
};
struct date
{
	int year;
	int month;
	int day;
	void nextday()
	{
		day++;
		if (day > dayofmonth[month][isleap(year)])
		{
			day = 1;
			month++;
			if (month > 12)
			{
				year++;
				month = 1;
			}
		}
	}
};
int buf[5001][13][32] = { 0 };

int main()
{
	date temp;
	int cnt = 0;
	temp.day = 1;
	temp.month = 1;
	temp.year = 0;
	while (temp.year != 5001)
	{
		buf[temp.year][temp.month][temp.day] = cnt;
		cnt++;
		temp.nextday();
	}
	int y1, m1, d1;
	int y2, m2, d2;
	scanf_s("%4d%2d%2d", &y1, &m1, &d1);
	scanf_s("%4d%2d%2d", &y2, &m2, &d2);
	printf("%d\n", abs(buf[y1][m1][d1] - buf[y2][m2][d2]) + 1);
	system("pause");
	return 0;
}