//
// Created by 崔进 on 2019-07-21.
//
#include <stdio.h>
#include <stdlib.h>
#include "include/common.h"

int *findMode(struct TreeNode *root, int *returnSize) {

    int top = -1;
    struct TreeNode **stack = (struct TreeNode **)calloc(2000, sizeof(struct TreeNode *));
    int *result = (int *)malloc(sizeof(int) * 2000);


    struct TreeNode *tmp = root;
    struct TreeNode *pre = NULL;

    int max = 0;
    int cnt = 1;
    *returnSize = 0;

    while (tmp || top >= 0) {

        while (tmp) {
            stack[++top] = tmp;
            tmp = tmp->left;
        }

        //pop
        tmp = stack[top--];

        if (tmp) {

            if (pre) {
                if (pre->val == tmp->val) {
                    cnt++;
                } else {
                    cnt = 1;
                }
            }

            if (cnt >= max) {
                if (cnt > max) {
                    *returnSize = 0;
                }
                result[(*returnSize)++] = tmp->val;
                max = cnt;
            }


            pre = tmp;
            tmp = tmp->right;

        }
    }

    free(stack);
    return result;


}


int main() {

    struct TreeNode third = {2, NULL, NULL};
    struct TreeNode second = {2, &third, NULL};
    struct TreeNode root = {1, NULL, &second};
    struct TreeNode * tmp = NULL;

    int len = 0;
    int *result = findMode(tmp, &len);

    printf("%s\n", "kitty");

    return 0;
}

