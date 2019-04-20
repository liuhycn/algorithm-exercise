#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

struct student
{
	char name[101];
	int age;
	int score;
	bool operator < (const student& b) const				//overload operator of structure
	{
		if (score != b.score) return score < b.score;
		int temp = strcmp(name, b.name);
		if (temp != 0) return temp < 0;
	}

}stu[1000];


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
	sort(stu, stu + n);
	for (int i = 0; i < n; i++)
	{
		cout << stu[i].name << " " << stu[i].age << " " << stu[i].score << endl;
	}
	system("pause");
	return 0;
}