//
// Created by 崔进 on 2019-08-18.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "include/common.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct Kitty {
    struct TreeNode *node;
    char s[1000];

} Kitty;

char **binaryTreePaths(struct TreeNode *root, int *returnSize) {

    *returnSize = 0;
    if (!root) {
        return NULL;
    }

    char **ans = calloc(1000, sizeof(char *));
    int top = -1;

    Kitty stack[1000] = {
            [0 ... 999] = {
                    .s = ""
            }
    };
    stack[++top].node = root;
    sprintf(stack[top].s, "%d", root->val);

    while (top >= 0) {

        int size = top;
        for (int i = 0; i <= size; i++) {
            Kitty tmp = stack[top--];

            if (tmp.node->left) {
                stack[++top].node = tmp.node->left;
                sprintf(stack[top].s, "%s->%d", tmp.s, tmp.node->left->val);
            }

            if (tmp.node->right) {
                stack[++top].node = tmp.node->right;
                sprintf(stack[top].s, "%s->%d", tmp.s, tmp.node->right->val);
            }

            if (!tmp.node->left && !tmp.node->right) {
                ans[*returnSize] = malloc(sizeof(char) * 400);
                sprintf(ans[*returnSize], "%s", tmp.s);
                (*returnSize)++;
            }

        }
    }


    return ans;

}

int main() {
    struct TreeNode * as = create();

    struct TreeNode five = {5, NULL, NULL};
    struct TreeNode two = {2, NULL, &five};
    struct TreeNode second = {3, NULL, NULL};
    struct TreeNode root = {1, &two, &second};

    int returnSize = 0;

    char **ans = binaryTreePaths(&root, &returnSize);

    return 0;
}
