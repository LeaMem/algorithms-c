//
// Created by iceli on 2019/8/1.
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

bool findTarget(struct TreeNode *root, int k) {

    struct TreeNode *stack[4000] = {NULL};
    int set[4000];
    int index = -1;
    int nodeLen = -1;

    struct TreeNode *tmp = root;

    while (tmp || index >= 0) {

        while (tmp) {
            stack[++index] = tmp;
            tmp = tmp->left;
        }

        //pop
        tmp = stack[index--];

        if (tmp) {

            int rest = k - tmp->val;
            for (int i = 0; i <= nodeLen; i++) {
                if (tmp->val == set[i]) {
                    return true;
                }
            }
            set[++nodeLen] = rest;
            tmp = tmp->right;
        }

    }


    return false;
}

int main() {

    struct TreeNode two = {2, NULL, NULL};
    struct TreeNode four = {4, NULL, NULL};
    struct TreeNode seven = {7, NULL, NULL};
    struct TreeNode three = {3, &two, &four};
    struct TreeNode six = {6, NULL, &seven};
    struct TreeNode five = {5, &three, &six};

    bool ans = findTarget(&five, 9);

    printf("%d\n", ans);


    return 0;
}