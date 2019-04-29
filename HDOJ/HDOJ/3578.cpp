//
//  3578.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/29.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"
#define INF 0x1fffffff
#define OFFSET 2000
int list[101];
int dp[101][4001];//dp[x][y]表示待选橘子数为x，重量差为y时的最大总重量


int main() {
    int T;
    int n;
    pp();
    scanf("%d",&T);
    int cas=0;
    while(T--)
    {
        
        cas++;
        bool have0=false;
        scanf("%d",&n);
        int cnt,i,j;
        cnt=0;//记录不为0的橘子数
        for(i=1;i<=n;i++)
        {
            scanf("%d",&list[++cnt]);
            if(list[cnt]==0)
            {
                //去掉重量为0的橘子
                cnt--;
                have0=true;
            }
        }
        n=cnt;//把非0橘子数赋值给n
        
        //初始化橘子数为0，各重量差为负无穷
        for(i=-2000;i<=2000;i++)
        {
            dp[0][i+OFFSET]=-INF;
        }
        //初始不加任何橘子。重量差为0，总重量为0，初始唯一存在的状态，其他都是负无穷
        dp[0][0+OFFSET]=0;
        /*dp[x][y]由三种状态转换而来,
         
         1.加入其中一堆，使重量差变小了: dp[x][y]=dp[x-1][y+list[x]]+list[x]
         2.加入其中一堆，使重量差变大了: dp[x][y]=dp[x-1][y-list[x]]+list[x]
         3.这个橘子不加入任何一堆: dp[x][y]=dp[x-1][y];
         */
        for(i=1;i<=n;i++)
        {
            for(j=-2000;j<=2000;j++)
            {
                int tmp1=-INF;//暂存第一种情况的结果
                int tmp2=-INF;//暂存第二种情况的结果
                //如果当前状态可由第一种转移而来
                if(j+list[i]<=2000&&dp[i-1][j+list[i]+OFFSET]!=-INF)
                {
                    tmp1=dp[i-1][j+list[i]+OFFSET]+list[i];
                }
                //如果当前状态可由第二种转移而来
                if(j-list[i]>=-2000&&dp[i-1][j-list[i]+OFFSET]!=-INF)
                {
                    tmp2=dp[i-1][j-list[i]+OFFSET]+list[i];
                }
                //取二者中较大的一个
                if(tmp1<tmp2) tmp1=tmp2;
                //考虑不加入的情况
                if(dp[i-1][j+OFFSET]>tmp1) tmp1=dp[i-1][j+OFFSET];
                //更新dp[i][j]
                dp[i][j+OFFSET]=tmp1;
            }
        }
        printf("Case %d: ",cas);
        if(dp[n][0+OFFSET]!=0)
            printf("%d\n",dp[n][0+OFFSET]/2);
        else
        {
            if(have0==false) printf("-1\n");
            else printf("0\n");
            
        }
        
    }
    
    
    
    
    
    return 0;
}
