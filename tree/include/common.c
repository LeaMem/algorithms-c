//
// Created by 崔进 on 2019-08-19.
//

#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void levelCreate(struct TreeNode *root, int *ans, int returnSize, int i) {

    if (2 * i + 1 < returnSize && ans[2 * i + 1] != -1) {
        struct TreeNode *left = malloc(sizeof(struct TreeNode));
        left->val = ans[2 * i + 1];
        left->left = NULL;
        left->right = NULL;
        root->left = left;
        levelCreate(left, ans, returnSize, 2 * i + 1);
    }

    if (2 * i + 2 < returnSize & ans[2 * i + 2] != -1) {
        struct TreeNode *right = malloc(sizeof(struct TreeNode));
        right->val = ans[2 * i + 2];
        right->left = NULL;
        right->right = NULL;
        root->right = right;
        levelCreate(right, ans, returnSize, 2 * i + 2);
    }

}

struct TreeNode *create() {

    int returnSize = -1;
    int ans[100];
    int a;
    while(~scanf("%d", &a)){
        ans[++returnSize] = a;
    }

    if (returnSize < 0) {
        return NULL;
    }

    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = ans[0];
    root->left = NULL;
    root->right = NULL;

    levelCreate(root, ans, returnSize, 0);

    return root;
}


