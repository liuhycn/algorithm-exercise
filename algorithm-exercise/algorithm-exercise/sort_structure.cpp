#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

struct student
{
	char name[101];
	int age;
	int score;
}stu[1000];

bool cmp(student s1, student s2)
{
	if (s1.score != s2.score) return s1.score < s2.score;
	int temp = strcmp(s1.name, s2.name);
	if (temp != 0) return temp < 0;							//input char* ,if str1 < str2 ,return negative;
														    //if str1 > str2. return positive; 
															//else return 0
	
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> stu[i].name;
		cin >> stu[i].age;
		cin >> stu[i].score;
	}
	sort(stu, stu + n, cmp);
	for (int i = 0; i < n; i++)
	{
		cout << stu[i].name << " " << stu[i].age << " " << stu[i].score << endl;
	}
	system("pause");
	return 0;
}