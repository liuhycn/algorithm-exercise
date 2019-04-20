#include<iostream>
#include<algorithm>
#include<string.h> 

//#define _CRT_SECURE_NO_WARNINGS

using namespace std;

struct student
{
	char no[101];
	char name[101];
	char sex[4];
	int age;
}stu[1001];

bool cmp(student s1, student s2)
{
	int temp = strcmp(s1.no, s2.no);
	if (temp != 0)
	{
		return temp < 0;
	}
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%s%s%s%d", stu[i].no, stu[i].name, stu[i].sex, &stu[i].age);
		}
		int m;
		sort(stu, stu + n, cmp);
		scanf("%d", &m);
		while (m != 0)
		{
			char request[101];
			scanf("%s", request);
			int l = 0;
			int r = n - 1;
			int mid;
			while (l <= r)
			{
				mid = (l + r) / 2;
				if (strcmp(stu[mid].no, request) == 0) break;
				else if (strcmp(stu[mid].no, request) > 0)
				{
					r = mid - 1;
				}
				else if (strcmp(stu[mid].no, request) < 0)
				{
					l = mid + 1;
				}
			}
			if (strcmp(stu[mid].no, request) == 0)
			{
				printf("%s %s %s %d\n", stu[mid].no, stu[mid].name, stu[mid].sex, stu[mid].age);
			}
			else
			{
				printf("No Answer!\n");
			}
			m--;
		}
	}
	return 0;
}