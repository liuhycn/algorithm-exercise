#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <math.h>

using namespace std;

struct person
{
    string name;
    int age;
    int w;
};

bool cmp2(person p1, person p2)
{
    if (p1.w != p2.w) return p1.w > p2.w;
    if (p1.age != p2.age) return p1.age < p2.age;
    if (p1.name != p2.name) return p1.name < p2.name;
    return false;
}

struct bucket
{
    int l, r, cnt;
    vector<person> buf;
    bucket()
    {
        buf = vector<person>(0);
    }
};

vector<person> peoples;
vector<bucket> res;

int main()
{
    int n, t;
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; i++)
    {
        string name;
        int age, w;
        cin >> name >> age >> w;
        peoples.push_back({name, age, w});
    }
    sort(peoples.begin(), peoples.end(), cmp2);
    
    
    
    for (int i = 0; i < t; i++)
    {
        int cnt, l, r;
        scanf("%d%d%d", &cnt, &l, &r);
        bucket tmp;
        tmp.cnt = cnt;
        tmp.l = l;
        tmp.r = r;
        res.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        person tmpper = peoples[i];
        for (int j = 0; j < t; j++)
        {
            if (res[j].buf.size() == res[j].cnt) continue;
            if (tmpper.age >= res[j].l && tmpper.age <= res[j].r) res[j].buf.push_back(tmpper);
        }
    }
    for (int i = 0; i < t; i++)
    {
        printf("Case #%d:\n", i + 1);
        if (res[i].buf.size() == 0) printf("None\n");
        else
        {
            for (int j = 0; j < res[i].buf.size(); j++)
                printf("%s %d %d\n", res[i].buf[j].name.c_str(), res[i].buf[j].age, res[i].buf[j].w);
        }
    }
    return 0;
}
