#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct node
{
    string id, name;
    int score;
};
const int N = 100001;

node nodes[N];

bool cmp1(node a, node b)
{
    return a.id < b.id;
}

bool cmp2(node a, node b)
{
    if (a.name != b.name)
    {
        return a.name < b.name;
    }
    else return cmp1(a, b);
}

bool cmp3(node a, node b)
{
    if (a.score != b.score)
        return a.score < b.score;
    else return cmp1(a, b);
}

int main()
{
    int n, op;
    cin >> n >> op;
    for (int i = 0; i < n; i++)
    {
        string id, name;
        int score;
        cin >> id >> name >> score;
        nodes[i] = {id, name, score};
    }
    if (op == 1)
    {
        sort(nodes, nodes + n, cmp1);
    }
    else if (op == 2)
    {
        sort(nodes, nodes + n, cmp2);
    }
    else
    {
        sort(nodes, nodes + n, cmp3);
    }
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1) cout << nodes[i].id << ' ' << nodes[i].name << ' ' << nodes[i].score << endl;
        else cout << nodes[i].id << ' ' << nodes[i].name << ' ' << nodes[i].score;
    }
    return 0;
}
