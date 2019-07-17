//
//  1039.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/7/17.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    pp();
    int n; //num of student
    int m; //num of courses
    scanf("%d%d", &n, &m);
    map<string, vector<int>> mymap;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        for (int j = 0; j < y; j++)
        {
            string name;
            cin >> name;
            mymap[name].push_back(x);
        }
    }
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        cout << a;
        printf(" %d", mymap[a].size());
        sort(mymap[a].begin(), mymap[a].end());
        for (int j = 0; j < mymap[a].size(); j++)
        {
            printf("% d", mymap[a][j]);
        }
        cout << endl;
    }
    return 0;
}
