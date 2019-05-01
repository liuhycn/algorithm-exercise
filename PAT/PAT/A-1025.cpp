//
//  A-1025.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/1.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

struct stu {
    char id[13];
    int no;
    int score;
    int local;
    int r;
}buf[3001];


bool local_cmp(stu a,stu b)
{
    if(a.score != b.score)
    {
        return a.score > b.score;
    }
    else
    {
        return strcmp(a.id,b.id) < 0;
    }
}

int main()
{
    int N;
    pp();
    int cnt = 0;
    scanf("%d",&N);
    for(int i = 1;i<=N;i++)
    {
        int k;
        scanf("%d",&k);
        stu local[301];
        for(int j = 0;j<k;j++)
        {
            scanf("%s%d",local[j].id,&local[j].score);
            local[j].no = i;
        }
        sort(local, local+k, local_cmp);
        local[0].local = 1;
        for(int j = 1;j<k;j++)
        {
            if(local[j].score == local[j-1].score)
            {
                local[j].local = local[j-1].local;
            }
            else if(local[j].score < local[j-1].score)
            {
                local[j].local = j+1;
            }
        }
        //printf("考场%d排名\n",i);
        //for(int j = 0;j<k;j++)
        //{
        //    printf("%s %d %d %d\n",local[j].id,local[j].score,local[j].no,local[j].local);
        //}
        for(int j = 0;j<k;j++)
        {
            buf[cnt++] = local[j];
        }
    }
    sort(buf,  buf+cnt, local_cmp);
    buf[0].r = 1;
    for(int i = 1;i<cnt;i++)
    {
        if(buf[i].score == buf[i-1].score)
        {
            buf[i].r = buf[i-1].r;
        }
        else if(buf[i].score < buf[i-1].score)
        {
            buf[i].r = i+1;
        }
    }
    printf("%d\n",cnt);
    for(int i = 0;i<cnt;i++)
    {
        printf("%s %d %d %d\n",buf[i].id,buf[i].r,buf[i].no,buf[i].local);
    }
    return 0;
}
