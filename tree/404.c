//
// Created by 崔进 on 2019-08-04.
//
#include <stdio.h>
#include <stdlib.h>
#include "include/common.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void sumLeft(struct TreeNode *root, int *sum) {
    if (!root) {
        return;
    }

    if (root->left && root->left->left == NULL && root->left->right == NULL) {
        *sum += root->left->val;
    }

    sumLeft(root->left, sum);

    sumLeft(root->right, sum);

}

int sumOfLeftLeaves(struct TreeNode *root) {
    int sum = 0;
    sumLeft(root, &sum);
    return sum;
}

int main() {
    struct TreeNode five = {5, NULL, NULL};
    struct TreeNode four = {4, NULL, NULL};
    struct TreeNode three = {3, NULL, NULL};
    struct TreeNode two = {2, &four, &five};
    struct TreeNode root = {1, &two, &three};

    int sum = sumOfLeftLeaves(&root);

    printf("%d\n", sum);

    return sum;

}

