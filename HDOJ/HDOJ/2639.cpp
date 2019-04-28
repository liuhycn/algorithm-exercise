//
//  2639.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/28.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    int n;
    pp();
    while (scanf("%d",&n)!=EOF)
    {
        for (int i = 0;i<n;i++)
        {
            
            char str[20];
            scanf("%s",str);
            printf("He/She is from ");
            char city[2];
            city[0] = str[0];
            city[1] = str[1];
            int x = 0;
            sscanf(city,"%d",&x);
            if(x == 33)
            {
                printf("Zhejiang");
            }
            else if (x == 11)
            {
                printf("Beijing");
            }
            else if (x == 71)
            {
                printf("Taiwan");
            }
            else if (x == 81)
            {
                printf("Hong Kong");
            }
            else if (x == 82)
            {
                printf("Macao");
            }
            else if (x == 54)
            {
                printf("Tibet");
            }
            else if (x == 21)
            {
                printf("Liaoning");
            }
            else
            {
                printf("Shanghai");
            }
            printf(",and his/her birthday is on ");
    
            printf("%c",str[10]);
            printf("%c",str[11]);
            printf(",");
            
            printf("%c",str[12]);
            printf("%c",str[13]);
            printf(",");
            
            printf("%c",str[6]);
            printf("%c",str[7]);
            printf("%c",str[8]);
            printf("%c",str[9]);
            
            printf(" based on the table.\n");
            
        }
        
    }
    return 0;
}
