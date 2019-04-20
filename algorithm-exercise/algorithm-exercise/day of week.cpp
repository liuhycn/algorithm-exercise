#include<iostream>
#include<math.h>
#include<string.h>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

#define isleap(x) x % 100 != 0 && x % 4 == 0 || x % 400 == 0 ? 1 : 0

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
};							//°´ÐÐ¸³Öµ


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

char monthName[13][20] =
{
	"",
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

char weekName[7][20] =
{
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thurday",
	"Friday",
	"Saturday",
	"Sunday"
};

int main()
{
	date temp;
	temp.year = 0;
	temp.month = 1;
	temp.day = 1;
	int cnt = 0;
	while (temp.year != 5000)
	{
		buf[temp.year][temp.month][temp.day] = cnt;
		cnt++;
		temp.nextday();
	}
	int y1;
	char m1[20];
	int d1;
	int m;
	scanf_s("%d%s%d", &d1, m1, &y1);
	//cin >> d1 >> m1 >> y1;
	for (int i = 1; i < 13; i++)
	{
		if (strcmp(m1, monthName[i]) == 0)
		{
			m = i;
			break;
		}
	}
	int less = buf[2019][4][5] - buf[y1][m][d1];
	less = less + 5;
	printf("%s", weekName[(less % 7 + 7) % 7]);
	system("pause");
	return 0;
}