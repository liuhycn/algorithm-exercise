//
//  BFS II.cpp
//  algorithm-exercise
//
//  Created by Hongyan Liu on 2019/4/22.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

struct state
{
    int s;
    int n;
    int m;
    int step;
};

bool visit[101][101][101];
queue<state> Q;
void init()
{
    while(!Q.empty())
    {
        Q.pop();
    }
    memset(visit, 0, sizeof(visit));
}

void AtoB(int &ahave,int acan,int &bhave,int bcan)              //倒水的时候传饮用
{
    if(ahave == 0 || bhave == bcan) return;
    int temp = bcan - bhave;                                    //b杯子还差多少满
    if(ahave <= temp)
    {
        bhave = bhave + ahave;
        ahave = 0;
    }
    else
    {
        ahave = ahave - temp;
        bhave = bcan;
    }
    
}

int bfs(int s,int n,int m)
{
    while (!Q.empty())
    {
        state thisState = Q.front();                           //当前正在扩展的状态
        Q.pop();
        int sOfthisstate = thisState.s;
        int nOfthisstate = thisState.n;
        int mOfthisstate = thisState.m;
        int stepOfthisstate = thisState.step;
        
        AtoB(sOfthisstate, s, nOfthisstate, n);                  //容积为s的杯子向容积为n的杯子倒水
        
        if(visit[sOfthisstate][nOfthisstate][mOfthisstate] == 0)
        {
            state newState;
            newState.s = sOfthisstate;
            newState.n = nOfthisstate;
            newState.m = mOfthisstate;
            newState.step = stepOfthisstate + 1;
            Q.push(newState);
            visit[sOfthisstate][nOfthisstate][mOfthisstate] = 1;
            
            if(newState.n == s /2 && newState.m == s / 2)
            {
                return newState.step;
            }
            if(newState.n == s /2 && newState.s == s / 2)
            {
                return newState.step;
            }
            if(newState.m == s /2 && newState.s == s / 2)
            {
                return newState.step;
            }
        }
        
        sOfthisstate = thisState.s;
        nOfthisstate = thisState.n;
        mOfthisstate = thisState.m;
        stepOfthisstate = thisState.step;
        
        AtoB(nOfthisstate, n, sOfthisstate, s);                 //容积为n的杯子向容积为s的杯子倒水
        
        if(visit[sOfthisstate][nOfthisstate][mOfthisstate] == 0)
        {
            state newState;
            newState.s = sOfthisstate;
            newState.n = nOfthisstate;
            newState.m = mOfthisstate;
            newState.step = stepOfthisstate + 1;
            Q.push(newState);
            visit[sOfthisstate][nOfthisstate][mOfthisstate] = 1;
            
            if(newState.n == s /2 && newState.m == s / 2)
            {
                return newState.step;
            }
            if(newState.n == s /2 && newState.s == s / 2)
            {
                return newState.step;
            }
            if(newState.m == s /2 && newState.s == s / 2)
            {
                return newState.step;
            }
        }
        
        sOfthisstate = thisState.s;
        nOfthisstate = thisState.n;
        mOfthisstate = thisState.m;
        stepOfthisstate = thisState.step;
        
        AtoB(nOfthisstate, n, mOfthisstate, m);                 //容积为n的杯子向容积为m的杯子倒水
        
        if(visit[sOfthisstate][nOfthisstate][mOfthisstate] == 0)
        {
            state newState;
            newState.s = sOfthisstate;
            newState.n = nOfthisstate;
            newState.m = mOfthisstate;
            newState.step = stepOfthisstate + 1;
            Q.push(newState);
            visit[sOfthisstate][nOfthisstate][mOfthisstate] = 1;
            
            if(newState.n == s /2 && newState.m == s / 2)
            {
                return newState.step;
            }
            if(newState.n == s /2 && newState.s == s / 2)
            {
                return newState.step;
            }
            if(newState.m == s /2 && newState.s == s / 2)
            {
                return newState.step;
            }
        }
        
        sOfthisstate = thisState.s;
        nOfthisstate = thisState.n;
        mOfthisstate = thisState.m;
        stepOfthisstate = thisState.step;
        
        AtoB(mOfthisstate, m, nOfthisstate, n);                 //容积为m的杯子向容积为n的杯子倒水
        
        if(visit[sOfthisstate][nOfthisstate][mOfthisstate] == 0)
        {
            state newState;
            newState.s = sOfthisstate;
            newState.n = nOfthisstate;
            newState.m = mOfthisstate;
            newState.step = stepOfthisstate + 1;
            Q.push(newState);
            visit[sOfthisstate][nOfthisstate][mOfthisstate] = 1;
            
            if(newState.n == s /2 && newState.m == s / 2)
            {
                return newState.step;
            }
            if(newState.n == s /2 && newState.s == s / 2)
            {
                return newState.step;
            }
            if(newState.m == s /2 && newState.s == s / 2)
            {
                return newState.step;
            }
        }
        sOfthisstate = thisState.s;
        nOfthisstate = thisState.n;
        mOfthisstate = thisState.m;
        stepOfthisstate = thisState.step;
        
        AtoB(sOfthisstate, s, mOfthisstate, m);                 //容积为s的杯子向容积为m的杯子倒水
        
        if(visit[sOfthisstate][nOfthisstate][mOfthisstate] == 0)
        {
            state newState;
            newState.s = sOfthisstate;
            newState.n = nOfthisstate;
            newState.m = mOfthisstate;
            newState.step = stepOfthisstate + 1;
            Q.push(newState);
            visit[sOfthisstate][nOfthisstate][mOfthisstate] = 1;
            
            if(newState.n == s /2 && newState.m == s / 2)
            {
                return newState.step;
            }
            if(newState.n == s /2 && newState.s == s / 2)
            {
                return newState.step;
            }
            if(newState.m == s /2 && newState.s == s / 2)
            {
                return newState.step;
            }
        }
        sOfthisstate = thisState.s;
        nOfthisstate = thisState.n;
        mOfthisstate = thisState.m;
        stepOfthisstate = thisState.step;
        
        AtoB(mOfthisstate, m, sOfthisstate, s);                 //容积为m的杯子向容积为s的杯子倒水
        
        if(visit[sOfthisstate][nOfthisstate][mOfthisstate] == 0)
        {
            state newState;
            newState.s = sOfthisstate;
            newState.n = nOfthisstate;
            newState.m = mOfthisstate;
            newState.step = stepOfthisstate + 1;
            Q.push(newState);
            visit[sOfthisstate][nOfthisstate][mOfthisstate] = 1;
            
            if(newState.n == s /2 && newState.m == s / 2)
            {
                return newState.step;
            }
            if(newState.n == s /2 && newState.s == s / 2)
            {
                return newState.step;
            }
            if(newState.m == s /2 && newState.s == s / 2)
            {
                return newState.step;
            }
        }
    }
    return -1;
}

int main()
{
    int s,n,m;
    pp();
    while (scanf("%d%d%d",&s,&n,&m)!=EOF)
    {
        
        if(s == 0 && n == 0 && m == 0)
        {
            break;
        }
        if( s % 2 == 1)
        {
            printf("NO\n");
            continue;
        }
        init();
        state tmp;
        tmp.s = s;
        tmp.n = 0;
        tmp.m = 0;
        tmp.step = 0;
        visit[s][0][0] = 1;
        Q.push(tmp);
        int ans = bfs(s, n, m);
        if(ans == -1)
        {
            printf("NO\n");
        }
        else
        {
            printf("%d\n",ans);
        }
    }
    return 0;
}
