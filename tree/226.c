//
// Created by 崔进 on 2019-08-04.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/common.h"

struct TreeNode* invertTree(struct TreeNode* root){
    if(!root){
        return NULL;
    }
    struct TreeNode * tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
