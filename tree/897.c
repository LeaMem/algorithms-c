//
// Created by iceli on 2019/8/20.
//

#include <stdlib.h>
#include <stdio.h>
#include "include/common.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *increasingBST(struct TreeNode *root) {
    struct TreeNode *stack[1500];
    int top = -1;
//    stack[++top] = root;
//
    struct TreeNode *tmp = root;
    struct TreeNode parent = {0, NULL, NULL};
    struct TreeNode *next = &parent;
    while (tmp || top >= 0) {

        while (tmp) {
            stack[++top] = tmp;
            tmp = tmp->left;
        }

        tmp = stack[top--];

        if (tmp) {
            next->left = NULL;
            next->right = tmp;
            next = next->right;
            tmp = tmp->right;
        }

    }
    next->left = NULL;
    next->right = NULL;

    return parent.right;

}

int main() {

    struct TreeNode *root = create();

    struct TreeNode *new = increasingBST(root);

    printf("%d\n", new->val);

    return 0;
}

