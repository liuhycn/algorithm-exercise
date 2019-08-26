#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;


typedef pair<string, string> PII;
unordered_map<char, char> dict;
vector<PII> res;

void init()
{
    dict['1'] = '@';
    dict['0'] = '%';
    dict['l'] = 'L';
    dict['O'] = 'o';
}

int main()
{
    init();
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        string str, id;
        cin >> id >> str;
        int flag = 0;
        for (int j = 0; j < str.size(); j++)
        {
            if (dict.find(str[j]) != dict.end())
            {
                str[j] = dict[str[j]];
                flag = 1;
            }
        }
        if (flag == 1)
        {
            cnt ++;
            res.push_back({id, str});
        }
    }
    if (res.size() == 0)
        if (n == 1) printf("There is %d account and no account is modified", n);
        else printf("There are %d accounts and no account is modified", n);
        else
        {
            printf("%d\n", cnt);
            for (int i = 0; i < res.size(); i++)
            {
                if (i == res.size() - 1)
                    printf("%s %s", res[i].first.c_str(), res[i].second.c_str());
                else
                    printf("%s %s\n", res[i].first.c_str(), res[i].second.c_str());
            }
        }
    return 0;
}
