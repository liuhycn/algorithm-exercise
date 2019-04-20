//
//  traverse_to_identify.cpp
//  wangdao_exercise
//
//  Created by Hongyan Liu on 2019/4/10.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;

struct node
{
    char c;
    node* left;
    node* right;
    node(char s)
    {
        c = s;
        left = NULL;
        right = NULL;
    }
};

node* recover(char* s1, char* s2)
{
    
    if(strlen(s1) == 1 && strlen(s2) == 1)
    {
        return new node(s1[0]);
    }
    if(strlen(s1) == 0 && strlen(s2) == 0)
    {
        return NULL;
    }
    char head = s1[0];
    char left_mid[501] = {0};                          //存放左子树的中序遍历
    char right_mid[501] = {0};                         //存放右子树的中序遍历
    char left_pre[501] = {0};
    char right_pre[501] = {0};
    node* ans = new node(head);
    int pos = 0;
    int flag = 0;
    int j = 0;
    int k = 0;
    for(int i = 0;i < strlen(s2); i++)            //在中序遍历中找到头节点
    {
        if(s2[i] == head)
        {
            pos = i;
            flag = 1;
        }
        else
        {
            if(flag == 0)
            {
                left_mid[j++] = s2[i];
            }
            else
            {
                right_mid[k++] = s2[i];
            }
        }
    }
    j = 0;
    k = 1;
    for(int i = 0;i<strlen(left_mid);i++)
    {
        left_pre[i] = s1[k++];
    }
    for(int i = 0;i<strlen(right_mid);i++)
    {
        right_pre[i] = s1[k++];
    }
    //printf("左子树的中序%s\n",left_mid);
    //printf("右子树的中序%s\n",right_mid);
    //printf("左子树的前序%s\n",left_pre);
    //printf("右子树的前序%s\n",right_pre);
    ans->left = recover(left_pre,left_mid);
    ans->right = recover(right_pre, right_mid);
    
    return ans;
}

void display(node* root)
{
    if(root == NULL)
    {
        return;
    }
    
    else
    {
        display(root->left);
        display(root->right);
        printf("%c ",root->c);
    }
}

int main()
{
    char s1[1001] = { 0 };                        //存放前序遍历结果
    char s2[1001] = { 0 };                        //存放中序遍历结果
    int n;
    while(scanf("%d",&n) != EOF)
    {
        getchar();
        for (int i = 0; i < n; i++)
        {
            scanf("%c",&s1[i]);
            getchar();
        }
        //printf("%s",s1);
        for (int i = 0; i < n; i++)
        {
            scanf("%c",&s2[i]);
            getchar();
        }
        //printf("%s",s2);
        node* root = recover(s1, s2);
        display(root);
        printf("\n");
    }
    return 0;
}


/*
 TEST : pre = XDEFAG
        mid = FDXEAG
 ANS :
 */
