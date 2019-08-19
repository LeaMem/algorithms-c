//
// Created by iceli on 2019/8/19.
//
#include <stdio.h>
#include <stdlib.h>
#include "include/common.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left; *     struct TreeNode *right; * };
 */

int max(a, b) {
    return a > b ? a : b;
}

int longest(struct TreeNode *root) {
    if(!root){
        return 0;
    }
    int left = longest(root->left);
    int right = longest(root->right);
    if(root->left && root->left->val == root->val){
        left += 1;
    }
    if(root->right && root->right->val == root->val){
        right += 1;
    }

    if(root->left && root->right && root->left->val == root->val && root->right->val == root->val){
        return left + right;
    }

    return max(left, right);
}

int longestUnivaluePath(struct TreeNode *root) {
    return longest(root);
}
