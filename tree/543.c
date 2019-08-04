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

int maxDeep(struct TreeNode * root, int * deep){
    if(!root){
        return 0;
    }

    int left = maxDeep(root->left, deep);
    int right = maxDeep(root->right, deep);

    if(*deep < left + right){
        *deep = left + right;
    }

    return 1 + (left > right ? left : right);
}

int diameterOfBinaryTree(struct TreeNode *root) {
    int max = 0;
    int ans = maxDeep(root, &max);

    return max;
}

int main(){

    struct TreeNode four = {4, NULL, NULL};

    struct TreeNode five = {5, NULL, NULL};

    struct TreeNode two = {2, &four, &five};

    struct TreeNode three = {3, NULL, NULL};

    struct TreeNode root = {1, &two, &three};


    int maxLen = diameterOfBinaryTree(&root);

    printf("%d\n", maxLen);


    return 0;
}

