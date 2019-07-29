//
// Created by 崔进 on 2019-07-24.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "include/common.h"


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int minDepth(struct TreeNode *root) {

    if(!root){
        return 0;
    }

    struct TreeNode ** queue = calloc(2000, sizeof(struct TreeNode *));
    int rare = 0;
    int front = 0;
    int level = 0;
    queue[rare++] = root;

    while(front != rare){

        int size = abs(front - rare);
        level++;
        for(int i = 0; i < size; i++){
            struct TreeNode * tmp = queue[front++];

            if(!tmp->left && !tmp->right){
                free(queue);
                return level;
            }

            if(tmp->left){
                queue[rare++] = tmp->left;
            }

            if(tmp->right){
                queue[rare++] = tmp->right;
            }

        }

    }

    return level;

}



