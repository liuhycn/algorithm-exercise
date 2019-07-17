//
//  A-1036.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/17.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    pp();
    int cntm = 0;
    int cntf = 0;
    int scorem = 100;
    int scoref = -1;
    int n;
    scanf("%d",&n);
    char mname[20];
    char fname[20];
    char fid[20];
    char mid[20];
    for (int i =0;i<n;i++)
    {
        char name[20] = {0};
        char gender[2] = {0};
        char id[20] = {0};
        int score;
        scanf("%s%s%s%d",name,gender,id,&score);
        if (gender[0] == 'M')
        {
            cntm++;
            if (score < scorem)
            {
                scorem = score;
                strcpy(mname,name);
                strcpy(mid,id);
            }
        }
        else
        {
            cntf++;
            if (score > scoref)
            {
                scoref = score;
                strcpy(fname,name);
                strcpy(fid,id);
            }
        }
    }
    if (cntm == 0)
    {
        printf("%s %s\n",fname,fid);
        printf("Absent\nNA");
    }
    else if (cntf == 0)
    {
        printf("Absent\n");
        printf("%s %s\n",mname,mid);
        printf("NA");
    }
    else
    {
        printf("%s %s\n",fname,fid);
        printf("%s %s\n",mname,mid);
        printf("%d",scoref - scorem);
    }
    return 0;
}
