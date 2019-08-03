//
//  1022.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/7/31.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"
#include <set>

struct bookInfo
{
    int id;
    string title;
    string author;
    string keyword;
    string publisher;
    int pubyear;
}bookBuf[10001];

map<string, set<int>> titlemap;
map<string, set<int>> authormap;
map<string, set<int>> keywordmap;
map<string, set<int>> publishermap;
map<int, set<int>> yearmap;


int n;
int m;
int main()
{
    pp();
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bookBuf[i].id);
        getchar();
        getline(cin, bookBuf[i].title);
        if (titlemap.find(bookBuf[i].title) == titlemap.end())
        {
            titlemap[bookBuf[i].title] = set<int>();
            titlemap[bookBuf[i].title].insert(bookBuf[i].id);
        }
        else
            titlemap[bookBuf[i].title].insert(bookBuf[i].id);
        getline(cin, bookBuf[i].author);
        if (authormap.find(bookBuf[i].author) == authormap.end())
        {
            authormap[bookBuf[i].author] = set<int>();
            authormap[bookBuf[i].author].insert(bookBuf[i].id);
        }
        else
            authormap[bookBuf[i].author].insert(bookBuf[i].id);
        getline(cin, bookBuf[i].keyword);
        //printf("key :%s\n", bookBuf[i].keyword.c_str());
        {
            int len = bookBuf[i].keyword.length();
            string tmp = "";
            for (int j = 0; j < len; j++)
            {
                int k = j;
                while (k < len && bookBuf[i].keyword[k] != ' ')
                {
                    tmp += bookBuf[i].keyword[k];
                    k ++;
                }
                if (keywordmap.find(tmp) == keywordmap.end())
                {
                    keywordmap[tmp] = set<int>();
                    keywordmap[tmp].insert(bookBuf[i].id);
                }
                else
                    keywordmap[tmp].insert(bookBuf[i].id);
                tmp = "";
                j = k;
            }
        }
        
        getline(cin, bookBuf[i].publisher);
        if (publishermap.find(bookBuf[i].publisher) == publishermap.end())
        {
            publishermap[bookBuf[i].publisher] = set<int>();
            publishermap[bookBuf[i].publisher].insert(bookBuf[i].id);
        }
        else
            publishermap[bookBuf[i].publisher].insert(bookBuf[i].id);
        scanf("%d", &bookBuf[i].pubyear);
        if (yearmap.find(bookBuf[i].pubyear) == yearmap.end())
        {
            yearmap[bookBuf[i].pubyear] = set<int>();
            yearmap[bookBuf[i].pubyear].insert(bookBuf[i].id);
        }
        else
            yearmap[bookBuf[i].pubyear].insert(bookBuf[i].id);
    }
    scanf("%d", &m);
    getchar();
    for (int i = 0; i < m; i++)
    {
        string tmp;
        getline(cin, tmp);
        printf("%s\n", tmp.c_str());
        char flag = tmp[0];
        tmp.erase(tmp.begin());
        tmp.erase(tmp.begin());
        tmp.erase(tmp.begin());
        if (flag == '1')
        {
            if (titlemap.find(tmp) == titlemap.end())
            {
                printf("Not Found");
            }
            else
            {
                int first = 0;
                for (auto item : titlemap[tmp])
                {
                    if (first == 0)
                    {
                        first = 1;
                        printf("%07d", item);
                    }
                    else
                        printf("\n%07d", item);
                }
            }
        }
        else if (flag == '2')
        {
            if (authormap.find(tmp) == authormap.end())
            {
                printf("Not Found");
            }
            else
            {
                int first = 0;
                for (auto item : authormap[tmp])
                {
                    if (first == 0)
                    {
                        first = 1;
                        printf("%07d", item);
                    }
                    else
                        printf("\n%07d", item);
                }
            }
        }
        else if (flag == '3')
        {
            if (keywordmap.find(tmp) == keywordmap.end())
            {
                printf("Not Found");
            }
            else
            {
                int first = 0;
                for (auto item : keywordmap[tmp])
                {
                    if (first == 0)
                    {
                        first = 1;
                        printf("%07d", item);
                    }
                    else
                        printf("\n%07d", item);
                }
            }
        }
        else if (flag == '4')
        {
            if (publishermap.find(tmp) == publishermap.end())
            {
                printf("Not Found");
            }
            else
            {
                int first = 0;
                for (auto item : publishermap[tmp])
                {
                    if (first == 0)
                    {
                        first = 1;
                        printf("%07d", item);
                    }
                    else
                        printf("\n%07d", item);
                }
            }
        }
        else
        {
            int tar;
            sscanf(tmp.c_str(), "%d", &tar);
            if (yearmap.find(tar) == yearmap.end())
            {
                printf("Not Found");
            }
            else
            {
                int first = 0;
                for (auto item : yearmap[tar])
                {
                    if (first == 0)
                    {
                        first = 1;
                        printf("%07d", item);
                    }
                    else
                        printf("\n%07d", item);
                }
            }
        }
        if (i != m - 1)
            printf("\n");
    }
    
    return 0;
}
