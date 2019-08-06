//
// Created by iceli on 2019/8/6.
//
#include <stdlib.h>
#include <stdio.h>
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




bool isCousins(struct TreeNode *root, int x, int y) {

    if (!root) {
        return false;
    }

    struct TreeNode **stack = calloc(1000, sizeof(struct TreeNode *));
    int rare = -1;
    int front = -1;
    stack[++rare] = root;

    int level = 0;
    int heightX = 0, heightY = 0;
    struct TreeNode *parentX = NULL, *parentY = NULL;

    while (front != rare) {

        level++;

        int len = abs(front - rare);
        for (int i = 0; i < len; i++) {

            front = (front + 1) % 1000;
            struct TreeNode *tmp = stack[front];

            if (tmp->left) {
                rare = (rare + 1) % 1000;
                stack[rare] = tmp->left;
                if (tmp->left->val == x) {
                    heightX = level + 1;
                    parentX = tmp;
                }
                if (tmp->left->val == y) {
                    heightY = level + 1;
                    parentY = tmp;
                }
            }

            if (tmp->right) {
                rare = (rare + 1) % 1000;
                stack[rare] = tmp->right;
                if (tmp->right->val == y) {
                    heightY = level + 1;
                    parentY = tmp;
                }

                if (tmp->right->val == x) {
                    heightX = level + 1;
                    parentX = tmp;
                }
            }
        }
    }
    return heightX == heightY && parentX != parentY;
}


int main() {
    struct TreeNode five = {5, NULL, NULL};
    struct TreeNode four = {4, NULL, NULL};
    struct TreeNode three = {3, NULL, &five};
    struct TreeNode two = {2, NULL, &four};
    struct TreeNode root = {1, &two, &three};

    bool and = isCousins(&root, 4, 5);

    printf("%d\n", and);

    return 0;
}

