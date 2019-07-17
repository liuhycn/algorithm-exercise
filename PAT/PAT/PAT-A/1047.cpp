//
//  1047.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/7/17.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    pp();
    int n;
    int m;
    scanf("%d%d", &n, &m);
    vector<vector<string> > mymap(m);
    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        int cnt;
        scanf("%d", &cnt);
        for (int j = 0; j < cnt; j++)
        {
            int id;
            scanf("%d", &id);
            mymap[id - 1].push_back(name);
        }
    }
    for (int i = 0; i < m; i++)
    {
        printf("%d %d\n", i + 1, mymap[i].size());
        sort(mymap[i].begin(), mymap[i].end());
        for (int j = 0; j < mymap[i].size(); j++)
        {
            printf("%s\n", mymap[i][j].c_str());
        }
    }
    return 0;
}
