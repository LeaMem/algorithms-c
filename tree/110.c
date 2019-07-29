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

int max(int a, int b){
    return a > b ? a : b;
}

int height(struct TreeNode * root){
    if(!root){
        return 0;
    }

    return 1 + max(height(root->left), height(root->right));

}

bool isBalanced(struct TreeNode* root){

    if(!root){
        return true;
    }

    int res = abs(height(root->left) - height(root->right));

    if(res > 1){
        return false;
    }

    return isBalanced(root->left) && isBalanced(root->right);
}

