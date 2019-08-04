//
// Created by 崔进 on 2019-08-04.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "include/common.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool path(struct TreeNode * root, int sum, int start){

    if(!root){
        return false;
    }

    if(!root->left && !root->right){
        return  start + root->val == sum;
    }

    int leftStart = start + root->val;
    int rightStart = start + root->val;

    return path(root->left, sum, leftStart) || path(root->right, sum, rightStart);
}


bool hasPathSum(struct TreeNode* root, int sum){
    return path(root, sum, 0);
}
