#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> prob;
int n ,k ,m;

struct person
{
    int id;
    int sum;
    vector<int> scores;
    int soulved;
    int rank;
    int pass;
    person()
    {
        id = 0;
        sum = 0;
        scores = vector<int>(k, -2);
        soulved = 0;
    }
    void getsum()
    {
        for (int i = 0; i < k; i++)
        {
            if (scores[i] < 0) continue;
            sum += scores[i];
        }
    }
    void getsoulved()
    {
        for (int i = 0; i < k; i++)
        {
            if (scores[i] == prob[i]) soulved ++;
        }
    }
    void getpass()
    {
        for (int i = 0; i < k; i++)
        {
            if (scores[i] >= 0) pass ++;
        }
    }
    void dispaly()
    {
        printf("%d %05d %d", rank, id, sum);
        for (int i = 0; i < k; i++)
        {
            if (scores[i] == -2) printf(" -");
            else if (scores[i] == -1) printf(" 0");
            else printf(" %d", scores[i]);
        }
        printf("\n");
    }
};

vector<person> users;

bool cmp1(person p1, person p2)
{
    return p1.sum > p2.sum;
}

bool cmp2(person p1, person p2)
{
    if (p1.rank != p2.rank) return p1.rank < p2.rank;
    if (p1.soulved != p2.soulved) return p1.soulved > p2.soulved;
    if (p1.id != p2.id) return p1.id < p2.id;
}

int main()
{
    scanf("%d%d%d", &n, &k, &m);
    users = vector<person>(n);
    for (int i = 0; i < k; i++)
    {
        int a;
        scanf("%d", &a);
        prob.push_back(a);
    }
    for (int i = 0; i < m; i++)
    {
        int uid, pid, w;
        scanf("%d%d%d", &uid, &pid, &w);
        if (w > prob[pid - 1]) continue;
        if (uid > n) continue;
        if (pid > k) continue;
        users[uid - 1].scores[pid - 1] = max(users[uid - 1].scores[pid - 1], w);
        users[uid - 1].id = uid;
    }
    for (int i = 0; i < n; i++) users[i].getsum();
    for (int i = 0; i < n; i++) users[i].getsoulved();
    for (int i = 0; i < n; i++) users[i].getpass();
    sort(users.begin(), users.end(), cmp1);
    users[0].rank = 1;
    for (int i = 1; i < n; i++)
    {
        if (users[i].sum == users[i - 1].sum) users[i].rank = users[i - 1].rank;
        else users[i].rank = i + 1;
    }
    sort(users.begin(), users.end(), cmp2);
    for (int i = 0; i < n; i++)
    {
        if (users[i].pass == 0) continue;
        users[i].dispaly();
    }
    return 0;
}
