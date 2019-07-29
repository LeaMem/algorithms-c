//
// Created by 崔进 on 2019-07-22.
//

#include<stdlib.h>
#include <stdio.h>
#include <math.h>
#include "include/common.h"


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


int maxLength(struct TreeNode *root) {

    if (root == NULL) {
        return 0;
    }

    int maxLeft = maxLength(root->left);

    int maxRight = maxLength(root->right);

    return maxLeft > maxRight ? maxLeft + 1 : maxRight + 1;

}

int **levelOrderBottom(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {

    *returnSize = maxLength(root);

    (*returnColumnSizes) = calloc(*returnSize, sizeof(int));


    int **result = calloc(*returnSize, sizeof(int *));


    if (!root) {
        return result;
    }

    int level = 0;
    int top = 0;
    int pop = 0;

    struct TreeNode **queue = calloc(4000, sizeof(struct TreeNode *));

    queue[top] = root;
    top = (top + 1) % 4000;

    while (pop != top) {

        int levelSize = abs(top - pop);

        int *innerResult = calloc(levelSize, sizeof(int));

        for (int i = 0; i < levelSize; i++) {

            struct TreeNode *tmp = queue[pop++];

            innerResult[i] = tmp->val;

            if (tmp->left) {
                queue[top] = tmp->left;
                top = (top + 1) % 4000;
            }
            if (tmp->right) {
                queue[top] = tmp->right;
                top = (top + 1) % 4000;
            }
        }

        returnColumnSizes[0][level] = levelSize;
        result[level++] = innerResult;

    }

    for(int i = 0; i < level / 2; i++){
        int * tmp = result[level - i - 1];

        int tmpb = returnColumnSizes[0][level - 1 - i];

        result[level - 1 - i] = result[i];
        result[i] = tmp;

        returnColumnSizes[0][level - 1 - i] = (*returnColumnSizes)[i];
        returnColumnSizes[0][i] = tmpb;
    }

    free(queue);

    return result;
}

int main() {

    struct TreeNode fifty = {15, NULL, NULL};
    struct TreeNode seven = {7, NULL, NULL};
    struct TreeNode twenty = {20, &fifty, &seven};
    struct TreeNode nine = {9, NULL, NULL};
    struct TreeNode root = {3, &nine, &twenty};


    struct TreeNode * tmp = NULL;

    int a;

    int * b = malloc(sizeof(int) * 10);

    int ** result = levelOrderBottom(tmp, &a, &b);

    for(int i = 0; i < a; i++){

        for(int j = 0; j < b[i]; j++){

            printf("%d\n", result[i][j]);

        }

    }

    return 0;
}

