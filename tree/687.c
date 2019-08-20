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

int longest(struct TreeNode *root, int *ans) {
    if (!root) {
        return 0;
    }
    int left = 1 + longest(root->left, ans);
    int right = 1 + longest(root->right, ans);

    if (!root->left || root->left->val != root->val) {
        left = 0;
    }
    if (!root->right || root->right->val != root->val) {
        right = 0;
    }


    *ans = max(*ans, left + right);

    return max(left, right);
}

int longestUnivaluePath(struct TreeNode *root) {
    int ans = 0;
    longest(root, &ans);
    return ans;
}

int main() {

    struct TreeNode *root = create();

    int ans = longestUnivaluePath(root);

    printf("%d\n", ans);

    return 0;
}
